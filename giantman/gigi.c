/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** gigi
*/

#include "antman.h"

int main(int ac, char **av)
{
    struct stat stats;
    char *buff;

    if (ac != 3)
        return (84);
    if (stat(av[1], &stats) < 0 ||
    my_getnbr(av[2]) < 1 || 3 < my_getnbr(av[2]))
        return (84);
    buff = malloc(sizeof(char) * (stats.st_size + 1));
    if (buff == NULL || open(av[1], O_RDONLY) == -1)
        return (84);
    if (read(open(av[1], O_RDONLY), buff, stats.st_size) < 0)
        return (0);
    huffman_algo_giant(buff);
    return (0);
}