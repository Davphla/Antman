/*
** EPITECH PROJECT, 2021
** antman
** File description:
** main
*/

#include "antman.h"
int write_file(char *str, char *str_to_david);
int write_image(char *str, char *str_to_david);

char *memory_alloc_string(struct stat file_stat)
{
    char *mem_alloc = malloc(sizeof(char) * (file_stat.st_size + 1));
    return (mem_alloc);
}

int read_file_deux(int ac, char *av[], struct stat file_stat)
{
    int filedesc = open(av[1], O_RDONLY);
    char *string;
    char *str_to_david;

    if (filedesc == -1) 
        return (84);
    str_to_david = memory_alloc_string(file_stat);
    string = memory_alloc_string(file_stat);
    if (string == NULL || str_to_david == NULL)
        return (84);
    if (read(filedesc, string, file_stat.st_size) < 1)
        return (0);
    add_zero_to_str(string, str_to_david, file_stat);
    if (strcont(av[1], ".ppm") == 1)
        return (third_style(string, str_to_david, &write_image));
    if (file_stat.st_size < 300000)
        return (third_style(string, str_to_david, &write_file));
    huffman_algo(1, (unsigned char *)string, file_stat.st_size);
}

int write_image(char *str, char *str_to_david)
{
    int line = check_line(str);
    compress_image(str, line, str_to_david);
    push_char(str_to_david, '@', 0);
    push_char(str_to_david, -1, 0);
    push_char(str_to_david, '@', 0);
    push_char(str_to_david, '@', 0);
    push_char(str_to_david, -1, 0);
    return (0);
}

int write_file(char *str, char *str_to_david)
{
    compress_words(str, str_to_david);
    return (0);
}

int main(int ac, char *av[])
{
    struct stat file_stat;

    if (ac != 3)
        return (84);
    if (stat(av[1], &file_stat) < 0)
        return (84);
    return (read_file_deux(ac, av, file_stat));
}