/*
** EPITECH PROJECT, 2021
** structures
** File description:
** Initialize structures
*/

#include "antman.h"

full_data_t *initialize_full_data(int file_size)
{
    full_data_t *data = malloc(sizeof(full_data_t));

    data->full_data = malloc(sizeof(char) * file_size);
    data->full_data[0] = '\0';
    data->full_data += 1;
    data->file_size = file_size;
    data->table_len = 0;
    data->prefix_len = 0;
    data->nbr_chara = 0;
    encrypt_data(file_size, 32, data->full_data);
    return (data);
}