/*
** EPITECH PROJECT, 2021
** b_tree.c
** File description:
** binary tree generation
*/

#include "antman.h"

b_tree_t *create_node_2(int data, b_tree_t *zero, b_tree_t *one)
{
    b_tree_t *node = malloc(sizeof(b_tree_t));

    node->data = data;
    node->zero = zero;
    node->one = one;
    return (node);
}

void view_tree(b_tree_t *tree, char direction)
{
    if (tree->zero != NULL)
        view_tree(tree->zero, 0);
    if (tree->one != NULL)
        view_tree(tree->one, 1);
}

void initiate_branch(b_tree_t **tree, char direction)
{
    if (direction == 0) {
        if ((*tree)->zero == NULL)
            (*tree)->zero = create_node_2(-1000, NULL, NULL);
        (*tree) = (*tree)->zero;
    } else if (direction == 1) {
        if ((*tree)->one == NULL)
            (*tree)->one = create_node_2(-1000, NULL, NULL);
        (*tree) = (*tree)->one;
    }
}

void initiate_node(b_tree_t *tree, char path_len, int path, char letter)
{
    b_tree_t *node = create_node_2(letter, NULL, NULL);

    for (; 1 < path_len; path_len -= 1) {
        initiate_branch(&tree, (((path >> (path_len - 1)) & 1) == 1));
    }
    ((path & 1) == 0) ? (tree->zero = node) : (tree->one = node);
}

b_tree_t *create_btree_2(full_data_t *data, char **av)
{
    char path_len = 0;
    int path = 0;
    char letter = 0;
    b_tree_t *tree = create_node_2(-1000, NULL, NULL);

    for (int i = 0; i < data->nbr_chara; i += 1) {
        path_len = uncipher(av, data->prefix_len);
        path = uncipher(av, path_len);
        letter = uncipher(av, 8);
        initiate_node(tree, path_len, path, letter);
    }
    return (tree);
}