/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** main
*/

#include "antman.h"

char *memory_alloc_string(struct stat file_stat)
{
    char *mem_alloc = malloc(sizeof(char) * file_stat.st_size + 1);
    return (mem_alloc);
}

int read_file(char *string)
{
    write_file(string);
    return (0);
}

int write_file(char *str)
{
    int line = 0;

    if (str[0] < 0 && str[0] > -10) {
        line = (str[0] * -1);
        str += 1;
        uncipher_image(str, line);
    } else {
        uncompress_file(str);
    }
    return (0);
}
