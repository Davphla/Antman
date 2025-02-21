/*
** EPITECH PROJECT, 2021
** antman
** File description:
** uncompress
*/

#include "antman.h"

int write_words(char *str, char **dictionary, int indice)
{
    int value = 0;
    int i;

    for (i = indice + 1; str[i] != -1; i++) {
        value *= 100;
        if (str[i] == 101)
            value += 0;
        else
            value += str[i];
    }
    my_printf("%s", dictionary[value - 1]);
    return (i);
}

void write_data_uncompress(char *str, char **dictionnary)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == -1) {
            i = write_words(str, dictionnary, i);
        }
        else {
            my_putchar(str[i]);
        }
    }
}

void uncompress_file(char *str)
{
    char **dictionary = read_dictionary(str);

    write_data_uncompress(str, dictionary);
    return;
}