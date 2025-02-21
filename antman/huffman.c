/*
** EPITECH PROJECT, 2021
** hufman.c
** File description:
** le grand le véritable, un vrai homme
*/

#include "antman.h"

int encrypt_data(int data, int data_size, char *full_data)
{
    static unsigned char data_buffer = 0;
    static int data_pos = 7;

    for (; 0 < data_size && data_pos >= 0;) {
        data_buffer |= ((data >> (data_size - 1)) & 1) << data_pos;
        data_pos -= 1;
        data_size -= 1;
    }
    if (data_pos == -1) {
        *full_data = data_buffer;
        full_data += 1;
        my_putchar(data_buffer);
        data_pos = 7;
        data_buffer = 0;
        if (0 < data_size) {
            return (encrypt_data(data, data_size, full_data));
        }
        return (data_pos);
    }
    return (data_pos);
}

void encrypt_dico(b_tree_list_t *tree, dico_element_t *dico, full_data_t *data)
{
    while (data->table_len > 0) {
        data->table_len >>= 1;
        data->prefix_len += 1;
    }
    encrypt_data(data->nbr_chara - 1, 8, data->full_data);
    encrypt_data(data->prefix_len, 8, data->full_data);
    for (int i = 0; i < 256; i += 1) {
        if (dico[i].data_len != -1) {
            encrypt_data(dico[i].data_len, data->prefix_len, data->full_data);
            encrypt_data(dico[i].data, dico[i].data_len, data->full_data);
            encrypt_data(i, 8, data->full_data);
        }
    }
}

void initiate_dico(b_tree_t *tree, dico_element_t *dico,
bit_data_t bit, full_data_t *data)
{
    if (tree->data != -1) {
        dico[tree->data].data = bit.bit_value;
        dico[tree->data].data_len = bit.data_len;
        if (data->table_len < bit.data_len)
            data->table_len = bit.data_len;
    } else {
        initiate_dico(tree->one, dico,
        (bit_data_t){(bit.bit_value << 1) + 1, bit.data_len + 1}, data);
        initiate_dico(tree->zero, dico,
        (bit_data_t){bit.bit_value << 1, bit.data_len + 1}, data);
    }
}

dico_element_t *dico_create(b_tree_t *tree,
full_data_t *data, b_tree_list_t *tree_list)
{
    dico_element_t *dico = malloc(sizeof(dico_element_t) * 256);

    for (int i = 0; i < 256; i += 1) {
        dico[i].data = 0;
        dico[i].data_len = -1;
    }
    initiate_dico(tree, dico, (bit_data_t){0, 0}, data);
    encrypt_dico(tree_list, dico, data);
    return (dico);
}

void huffman_algo(int ac, unsigned char *av, int file_size)
{
    full_data_t *data = initialize_full_data(file_size);
    b_tree_list_t *tree_list;
    b_tree_t *tree = create_btree(av, data, tree_list);
    dico_element_t *dico = dico_create(tree, data, tree_list);

    if (ac == 3) {
        my_printf("\n\n");
        for (int i = 32; i < 256; i += 1)
            if (dico[i].data_len != -1)
                my_printf("(%d) %b -> %c   ",
                dico[i].data_len, dico[i].data, i);
        my_printf("\n\n");
    }
    for (int i = 0; i < file_size; i += 1)
        encrypt_data(dico[av[i]].data, dico[av[i]].data_len, data->full_data);
    encrypt_data(0, 8, data->full_data);
    my_free(2, data, dico);
}