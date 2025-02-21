/*
** EPITECH PROJECT, 2021
** antman
** File description:
** clean_duplicate
*/

#include "antman.h"

int count_total_words(dictionnary_t *dictionary)
{
    int words = 0;

    for (int i = 0; dictionary[i].string != NULL; i++) {
        for (int j = 0; j < i; j++) {
            if ((i != j && my_strcmp(dictionary[j].string,
            dictionary[i].string) == 0) ||
            my_strlen(dictionary[i].string) < 4) {
                words -= 1;
                break;
            }
        }
        words += 1;
    }
    return (words);
}

void memory_allocation_duplicate(dictionnary_t *words,
dictionnary_t *dictionary)
{
    int count = 0;

    for (int i = 0; dictionary[i].string != NULL; i++) {
        if (i == 0 && my_strlen(dictionary[count].string) > 3) {
            words[count].string = malloc(sizeof(char) *
            my_strlen(dictionary[count].string) + 1);
            my_strcpy(words[count].string, dictionary[count].string);
            count += 1;
        }
        for (int j = 0; j < i; j++) {
            if (memory_style(dictionary, i, j) == 1)
                break;
            if (j + 1 == i) {
                words[count].string = malloc(sizeof(char) *
                my_strlen(dictionary[i].string) + 1);
                my_strcpy(words[count].string, dictionary[i].string);
                count += 1;
            }
        }
    }
    words[count].string = NULL;
}

void display_words(dictionnary_t *dictionary, int j, char *str_to_david)
{
    for (int i = 0; dictionary[j].string[i] != '\0'; i++)
        push_char(str_to_david, dictionary[j].string[i], 0);
    dictionary[j].write = 1;
    return;
}

dictionnary_t *clean_duplicate(dictionnary_t *dictionary)
{
    int count = count_total_words(dictionary);
    dictionnary_t *words = malloc(sizeof(dictionnary_t) * (count + 1));

    memory_allocation_duplicate(words, dictionary);
    return (words);
}