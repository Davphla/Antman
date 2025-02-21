/*
** EPITECH PROJECT, 2021
** antman
** File description:
** image
*/

#include "antman.h"

int style_data(char const *str, int indice)
{
    int k;

    for (k = indice; (str[k] >= 'A' && str[k] <= 'Z') ||
        (str[k] >= 'a' && str[k] <= 'z'); k++);
    return (k);
}

int style_temp(char const *str, int i, char *temp)
{
    int x;

    for (x = i; (str[x] >= 'A' && str[x] <= 'Z') ||
    (str[x] >= 'a' && str[x] <= 'z'); x++)
        temp[x - i] = str[x];
    temp[x - i] = '\0';
    return (x);
}

int check_line(char *str)
{
    int n = 0;
    int activation = 0;
    int line = 10;

    for (int i = 0; str[i] != '\0' && n < 10; i++) {
        if (str[i] == '\n') {
            n += 1;
            if (activation == 1)
                line = n;
            activation = 0;
            continue;
        }
        if (str[i] < '0' || str[i] > '9')
            activation = 1;
    }
    return (line);
}

int memory_style(dictionnary_t *dictionary, int i, int j)
{
    if ((i != j && my_strcmp(dictionary[j].string,
    dictionary[i].string) == 0) || my_strlen(dictionary[i].string) < 4)
        return (1);
    return (0);
}

void compress_image(char *str, int line, char *str_to_david)
{
    char c = 127;
    char *temp = malloc(sizeof(char) * 5);
    int length = 0;
    int x = 0;

    add_second_style(str_to_david, line, str[0]);
    for (int indice = 0; indice < line;
    indice = (str[0] == '\n') ? indice += 1 : indice) {
        str += 1;
        push_char(str_to_david, str[0], 0);
    }
    str += 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            add_first_style(temp, str_to_david, length);
            length = 0;
        } else {
            temp[length] = str[i];
            length += 1;
        }
    }
}