/*
** EPITECH PROJECT, 2021
** antman
** File description:
** str_to_word_array
*/

#include "antman.h"

int count_words(char const *str)
{
    int word_start = 0;
    int words = 0;

    for (int i = 0; str[i] != '\0'; i++) {
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

int my_memory_allocation(char const *str, dictionnary_t *dictionary)
{
    int length = 0;
    int compt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
        (str[i] >= 'a' && str[i] <= 'z')) {
            length++;
            if (str[i + 1] == '\0')
                dictionary[compt].string = malloc(sizeof(char) * length + 1);
        } else if (length > 0) {
            dictionary[compt].string = malloc(sizeof(char) * length + 1);
            length = 0;
            compt++;
        } else {
            length = 0;
        }
    }
    return (0);
}

int push_words(char const *str, dictionnary_t *dictionary)
{
    int length = 0;
    int compteur = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
        (str[i] >= 'a' && str[i] <= 'z')) {
            dictionary[compteur].string[length] = str[i];
            length++;
            if (str[i + 1] == '\0')
                dictionary[compteur].string[length] = '\0';
        } else if (length > 0) {
            dictionary[compteur].string[length] = '\0';
            length = 0;
            compteur++;
        } else
            length = 0;
    }
    return (0);
}

dictionnary_t *my_str_to_word_array(char const *str)
{
    int words;
    dictionnary_t *dictionary;

    words = count_words(str);
    dictionary = malloc(sizeof(dictionnary_t) * (words + 1));
    my_memory_allocation(str, dictionary);
    push_words(str, dictionary);
    dictionary[words].string = NULL;
    for (int i = 0; dictionary[words].string != NULL; i++)
        dictionary[i].write = 0;
    return (dictionary);
}