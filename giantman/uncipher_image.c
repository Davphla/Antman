/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** uncipher_image
*/

#include "antman.h"

uncipher_image(char *str, int line)
{
    unsigned char temp;

    for (int i = 0; i < line; i = (str[0] == '\n') ? i += 1 : i) {
        my_printf("%c", str[0]);
        str += 1;
    }
    my_printf("%c", str[0]);
    str += 1;
    for (int i = 0; str[i] != '@' || str[i + 1] != -1 || str[i + 2] != '@' ||
    str[i + 3] != '@' || str[i + 4] != -1; i += 1) {
        temp = str[i];
        my_printf("%d\n", (unsigned char)temp);
    }
}
