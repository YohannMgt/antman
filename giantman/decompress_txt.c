/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** decompress_txt
*/

#include "include/my.h"

void add_zero(char **src)
{
    char *result = malloc(sizeof(char) * CHAR_SIZE);
    for (int i = 0; i < CHAR_SIZE - my_strlen(*src); i++)
        my_strcat(result, "0");
    my_strcat(result, *src);
    *src = result;
}

void convert_text(char **file)
{
    char *new_file = malloc(sizeof(char) * my_strlen(*file) * CHAR_SIZE);
    int current_len = 0;
    char *tmp = malloc(sizeof(char) * CHAR_SIZE);
    for (int i = 0; i < my_strlen(*file); i++) {
        tmp = int_to_bin(((unsigned int)(*file)[i]) - CHAR_OFFSET);
        if (my_strlen(tmp) < 6)
            add_zero(&tmp);
        current_len = my_strcat_size(new_file, tmp, current_len);
    }
    (*file) = new_file;
}

char *char_to_str(int code)
{
    if (code == NO_CODE)
        return ("");
    char *str = malloc(sizeof(char) * 2);
    str[0] = code;
    str[1] = '\0';
    return (str);
}

void decode_binary(node_t *node, char *file)
{
    node_t *root = node;
    for (int i = 0; i < my_strlen(file) + 1; i++) {
        if (node->code != NO_CODE) {
            write(1, char_to_str(node->code), 1);
            node = root;
        }
        if (file[i] == '0')
            node = node->right;
        if (file[i] == '1')
            node = node->left;
    }
    my_printf("\n");
}

int decompress_txt(char *file)
{
    file[my_strlen(file) - 1] = '\0';
    node_t *tree = init_tree(&file);
    if (tree == NULL)
        return (EXIT_FAILURE);
    convert_text(&file);
    decode_binary(tree, file);
    return (EXIT_SUCCESS);
}
