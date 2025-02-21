/*
** EPITECH PROJECT, 2021
** antman
** File description:
** respect coding style
*/

#include "antman.h"

void add_zero_to_str(char *str1, char *str2, struct stat file_stat)
{
    str1[file_stat.st_size] = '\0';
    str2[0] = '\0';
    return;
}

void add_first_style(char *temp, char *str_to_david, int length)
{
    temp[length] = '\0';
    push_char(str_to_david, my_getnbr(temp), 0);
    return;
}

void add_second_style(char *str_to_david, int line, char str0)
{
    push_char(str_to_david, -1 * line, 0);
    push_char(str_to_david, str0, 0);
    return;
}

int third_style(char *string, char *str_to_david, int(*fonc)(char*, char*))
{
    fonc(string, str_to_david);
    huffman_algo(1, (unsigned char *)str_to_david, push_char(0, 0, 1));
    return (0);
}