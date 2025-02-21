/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** uncompress
*/

#include "antman.h"

int count_words(char const *str)
{
    int word_start = 0;
    int words = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        i = only_three_length_words(str, i);
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
        (str[i] >= 'a' && str[i] <= 'z')) {
            if (word_start != 1)
                word_start = 1;
            if (str[i + 1] == '\0')
                words++;
        } else {
            if (word_start == 1) {
                word_start = 0;
                words++;
            }
        }
    }
    return (words);
}

int my_memory_allocation(char const *str, char **list)
{
    int length = 0;
    int compteur = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        i = only_three_length_words(str, i);
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
        (str[i] >= 'a' && str[i] <= 'z')) {
            length++;
            if (str[i + 1] == '\0')
                list[compteur] = malloc(sizeof(char) * length + 2);
        } else if (length > 0) {
            list[compteur] = malloc(sizeof(char) * length + 2);
            length = 0;
            compteur++;
        } else {
            length = 0;
        }
    }
    return (0);
}

int only_three_length_words(char const *str, int indice)
{
    int pass = 0;

    if (indice == 0 || (str[indice - 1] < 'A' || str[indice - 1] > 'Z') &&
    (str[indice -1]) < 'a' || str[indice - 1] > 'z') {
        for (int i = indice; str[i] != '\0' && (str[i] >= 'A' && str[i] <= 'Z')
        || (str[i] >= 'a' && str[i] <= 'z'); i++) {
            pass += 1;
        }
    }
    if (pass > 3) {
        return (indice);
    } else {
        return (indice + pass);
    }
    return (indice);
}

int push_words(char const *str, char **list)
{
    int length = 0;
    int compteur = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        i = only_three_length_words(str, i);
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
        (str[i] >= 'a' && str[i] <= 'z')) {
            list[compteur][length] = str[i];
            length++;
            if (str[i + 1] == '\0')
                list[compteur][length] = '\0';
        } else if (length > 0) {
            list[compteur][length] = '\0';
            length = 0;
            compteur++;
        } else
            length = 0;
    }
    return (0);
}

char **read_dictionary(char const *str)
{
    int count = count_words(str);
    char **dictionary = malloc(sizeof(char*) * (count + 2));

    my_memory_allocation(str, dictionary);
    push_words(str, dictionary);
    dictionary[count] = NULL;
    return (dictionary);
}