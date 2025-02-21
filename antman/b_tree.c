/*
** EPITECH PROJECT, 2021
** b_tree.c
** File description:
** b tree functions
*/

#include "antman.h"

b_tree_t *create_node(int data, b_tree_t *zero, b_tree_t *one)
{
    b_tree_t *node = malloc(sizeof(b_tree_t));

    node->data = data;
    node->zero = zero;
    node->one = one;
    return (node);
}

b_tree_list_t *tree_list_init(int *nb_letters, full_data_t *fdata)
{
    b_tree_list_t *tree;
    int nb_data = 0;
    int j = 0;

    for (int i = 0; i < 256; i += 1)
        nb_data += (nb_letters[i] != 0);
    fdata->nbr_chara = nb_data;
    tree = malloc(sizeof(b_tree_list_t) * (nb_data + 3));
    for (int i = 0; i < 256; i += 1)
        if (nb_letters[i] != 0) {
            (tree[j]).occurence = nb_letters[i];
            tree[j].node = create_node(i, NULL, NULL);
            j += 1;
        }
    tree[j].occurence = -1;
    return (tree);
}

void smallest_element(b_tree_list_t *tree)
{
    b_tree_list_t *temp = &tree[1];
    b_tree_list_t *temp2 = &tree[0];
    int i;

    for (i = 2; tree[i].occurence != -1; i += 1) {
        if ((temp->occurence > tree[i].occurence || temp->occurence == 0)
        && tree[i].occurence != 0)
            temp = &tree[i];
        else if ((temp2->occurence > tree[i].occurence ||
        temp2->occurence == 0) && tree[i].occurence != 0)
            temp2 = &tree[i];
    }
    temp2->occurence += temp->occurence;
    temp2->node = create_node(-1, temp->node, temp2->node);
    temp->occurence = 0;
}

b_tree_t *create_btree(unsigned char *data,
full_data_t *fdata, b_tree_list_t *tree)
{
    int *nb_letters = my_alloc_int(256, 0);

    for (int i = 0; i < fdata->file_size; i += 1)
        nb_letters[data[i]] += 1;
    tree = tree_list_init(nb_letters, fdata);
    for (int i = 0; tree[i + 1].occurence != -1; i += 1) {
        smallest_element(tree);
    }
    free(nb_letters);
    return (tree->node);
}