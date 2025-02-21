/*
** EPITECH PROJECT, 2021
** stumper.h
** File description:
** stumper .h
*/

#ifndef antman
#define antman

#include "my.h"

// // Antman // //

typedef struct dictionnary {
    char *string;
    int write;
} dictionnary_t;

dictionnary_t *my_str_to_word_array(char const *str);
int compress_words(char const *str, char *str_to_david);
dictionnary_t *clean_duplicate(dictionnary_t *dictionary);
void display_words(dictionnary_t *dictionary, int j, char *str_to_david);
int strcont(char *str, char *cont);
int check_line(char *str);
void compress_image(char *str, int line, char *str_to_david);
int style_data(char const *str, int indice);
int style_temp(char const *str, int i, char *temp);
int memory_style(dictionnary_t *dictionary, int i, int j);
int push_char(char *str, char add, int value);
void add_zero_to_str(char *str1, char *str2, struct stat file_stat);
void add_first_style(char *temp, char *str_to_david, int length);
void add_second_style(char *str_to_david, int line, char str0);
void huffman_algo(int ac, unsigned char *av, int file_size);
int third_style(char *string, char *str_to_david, int(*fonc)(char*, char*));

// Huffman

typedef struct dico_element {
    int data;
    int data_len;
} dico_element_t;

typedef struct full_data {
    char *full_data;
    int table_len;
    int prefix_len;
    int nbr_chara;
    int file_size;
} full_data_t;

typedef struct bit_data {
    int bit_value;
    int data_len;
} bit_data_t;

typedef struct b_tree {
    int data; // -1 for non-leaf nodes
    struct b_tree *zero;
    struct b_tree *one;
} b_tree_t;

typedef struct b_tree_list {
    int occurence;
    b_tree_t *node;
} b_tree_list_t;

// Prototype
b_tree_t *create_btree(unsigned char *data,
full_data_t *fdata, b_tree_list_t *tree);
full_data_t *initialize_full_data(int file_size);
b_tree_t *create_btree_2(full_data_t *data, char **av);
int uncipher(char **data, int data_len);
int encrypt_data(int data, int data_size, char *full_data);
// // Giantman // //

void huffman_algo_giant(char *av);
char **read_dictionary(char const *str);
void uncompress_file(char *str);
int only_three_length_words(char const *str, int indice);
uncipher_image(char *str, int line);
int read_file(char *string);

#endif /* !antman */
