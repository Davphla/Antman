/*
** EPITECH PROJECT, 2021
** antman
** File description:
** compress
*/

#include "antman.h"

void free_string_array(dictionnary_t *dico)
{
    int i;

    for (i = 0; dico[i].string != NULL; i++) {
        free(dico[i].string);
    }
    free(dico[i].string);
    free(dico);
    return;
}

int write_compress_code(int j, char *str_to_david)
{
    if (j + 1 < 100) {
        push_char(str_to_david, -1, 0);
        push_char(str_to_david, j + 1, 0);
        push_char(str_to_david, -1, 0);
    } else {
        if ((j + 1) % 100 == 0) {
            push_char(str_to_david, -1, 0);
            push_char(str_to_david, (j + 1) / 100, 0);
            push_char(str_to_david, 101, 0);
            push_char(str_to_david, -1, 0);
        }
        else {
            push_char(str_to_david, -1, 0);
            push_char(str_to_david, (j + 1) / 100, 0);
            push_char(str_to_david, (j + 1) % 100, 0);
            push_char(str_to_david, -1, 0);
        }
    }
    return (0);
}

int write_data(char const *str, dictionnary_t *dico, int i, char *str_to_david)
{
    char *temp;
    int x;

    temp = malloc(sizeof(char) * (style_data(str, i) - i) + 1);
    x = style_temp(str, i, temp);
    for (int j = 0; dico[j].string != NULL; j++) {
        if (my_strcmp(dico[j].string, temp) == 0 &&
        dico[j].write == 1) {
            write_compress_code(j, str_to_david);
            break;
        }
        if (my_strcmp(dico[j].string, temp) == 0 && dico[j].write == 0) {
            display_words(dico, j, str_to_david);
            break;
        }
        if (dico[j + 1].string == NULL) {
            return (i);
        }
    }
    free(temp);
    return (x);
}

void check_loop(char const *str, dictionnary_t *dico, char *str_to_david)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
        (str[i] >= 'a' && str[i] <= 'z')) {
            i = write_data(str, dico, i, str_to_david);
        }
        push_char(str_to_david, str[i], 0);
    }
    return;
}

int compress_words(char const *str, char *str_to_david)
{
    int k;
    dictionnary_t *dico = my_str_to_word_array(str);
    dictionnary_t *words = clean_duplicate(dico);

    free_string_array(dico);
    for (int i = 0; words[i].string != NULL; i++) {
        words[i].write = 0;
    }
    check_loop(str, words, str_to_david);
    return (0);
}