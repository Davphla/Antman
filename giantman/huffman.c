/*
** EPITECH PROJECT, 2021
** huffman.c
** File description:
** huffman, le véritable, un homme de valeur
*/

#include "antman.h"

full_data_t *fulldata_initialize(char *av, int file_size)
{
    full_data_t *data = malloc(sizeof(full_data_t));

    data->full_data = malloc(sizeof(char) * file_size);
    data->full_data[0] = '\0';
    data->full_data += 1;
    data->nbr_chara = 0;
    data->prefix_len = 0;
    data->table_len = 0;
    return (data);
}

int uncipher(char **data, int data_len)
{
    static int pos = 7;
    int buffer = 0;

    for (int i = 0; i < data_len; i += 1) {
        if (pos == -1) {
            pos = 7;
            *data += 1;
        }
        buffer <<= 1;
        buffer += (**data >> pos) & 1;
        pos -= 1;
    }
    return (buffer);
}

void header_initialize(full_data_t *data, char **av)
{
    data->nbr_chara = uncipher(av, 8) + 1;
    data->prefix_len = uncipher(av, 8);
}

void search_in_btree(b_tree_t *tree, char **av, full_data_t *data)
{
    while (tree->data == -1000) {
        if (uncipher(av, 1) == 0)
            tree = tree->zero;
        else
            tree = tree->one;
    }
    data->full_data[0] = tree->data;
    data->full_data += 1;
}

void huffman_algo_giant(char *av)
{
    int file_size = uncipher(&av, 32);
    full_data_t *data = fulldata_initialize(av, file_size);
    b_tree_t *tree;

    header_initialize(data, &av);
    tree = create_btree_2(data, &av);
    for (int i = 0; i < file_size; i += 1) {
        search_in_btree(tree, &av, data);
    }
    for (int i = 0; i < file_size; i += 1)
        data->full_data -= 1;
    read_file(data->full_data);
}