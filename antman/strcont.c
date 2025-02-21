/*
** EPITECH PROJECT, 2021
** antman
** File description:
** strcont
*/

int push_char(char *str, char add, int value)
{
    static indice = 0;

    if (value == 0) {
        str[indice] = add;
        str[indice + 1] = '\0';
        indice += 1;
    }
    else {
        return (indice);
    }
    return (0);
}

int check_cont(char *str, char *cont, int indice)
{
    for (int i = 0; cont[i] != '\0'; i++) {
        if (str[indice] != cont[i]) {
            return (0);
        }
        indice += 1;
    }
    return (1);
}

int strcont(char *str, char *cont)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == cont[0]) {
            if (check_cont(str, cont, i) == 1)
                return (1);
        }
    }
    return (0);
}