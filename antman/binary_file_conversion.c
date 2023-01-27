/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** binary_conversion
*/

#include "include/my.h"

char *find_binary(node_t *node, unsigned int target)
{
    if (node == NULL)
        return ("");
    if (node->code == target)
        return (node->binary);
    char *tmp = malloc(sizeof(char) * 16);
    my_strcat(tmp, find_binary(node->left, target));
    my_strcat(tmp, find_binary(node->right, target));
    return (tmp);
}

char *convert_file_to_bin(char *file, node_t *tree)
{
    char *converted = malloc(sizeof(char) * (NOT_ZERO(my_strlen(file))));
    for (int i = 0; i < my_strlen(file); i++)
        my_strcat(converted, find_binary(tree, (unsigned int)file[i]));
    return (converted);
}

char *extract_bin(char *bin_file, int i)
{
    char *res = malloc(sizeof(char) * CHAR_SIZE);
    int index = 0;
    for (int j = i * CHAR_SIZE; j < i * CHAR_SIZE + CHAR_SIZE; j++)
        res[index++] = bin_file[j];
    return (res);
}

char *last_bits(char *bin_file, int pos)
{
    char *res = malloc(sizeof(char) * CHAR_SIZE);
    for (int i = pos; bin_file[i] != '\0'; i++)
        res[i - pos] = bin_file[i];
    return (res);
}

char **make_bin_arr(char *bin_file)
{
    int number = my_strlen(bin_file) / CHAR_SIZE;
    char **bin_arr = malloc((number + 2) * (CHAR_SIZE + 2));
    for (int i = 0; i < number; i++) {
        bin_arr[i] = malloc(sizeof(char) * CHAR_SIZE);
        my_strcpy(bin_arr[i], extract_bin(bin_file, i));
    }
    if (my_strlen(bin_file) % CHAR_SIZE != 0)
        bin_arr[number] = last_bits(bin_file, number * CHAR_SIZE);
    return (bin_arr);
}
