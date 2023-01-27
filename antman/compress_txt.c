/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** compress_txt
*/

#include "include/my.h"

void add_binary_value(node_t **node, int level, char *bin, char *previous_txt)
{
    if ((*node) == NULL)
        return;
    my_strcat((*node)->binary, previous_txt);
    my_strcat((*node)->binary, bin);
    add_binary_value(&((*node)->left), level + 1,
        "1", (*node)->binary);
    add_binary_value(&((*node)->right), level + 1,
        "0", (*node)->binary);
}

int size_sanity(node_t *tree, node_list_t *node_list)
{
    int sum = 0;
    for (int i = 0; i < node_list->node_number; i++)
        sum += node_list->list[i]->frequency;
    if (sum != tree->frequency)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

char *convert_to_compressed(char *file, node_t *tree)
{
    char *bin_file = convert_file_to_bin(file, tree);
    char *compressed = malloc(sizeof(char) * (NOT_ZERO(my_strlen(bin_file))));
    char **bin_arr = make_bin_arr(bin_file);
    for (int i = 0; bin_arr[i] != NULL; i++)
        compressed[i] = (char)bin_to_int(bin_arr[i]) + CHAR_OFFSET;
    return (compressed);
}

int compress_txt(char *file)
{
    node_list_t *node_list = init_node_list(file);
    node_t *tree = create_huffman_tree(node_list);
    if (tree == NULL)
        return (84);
    if (size_sanity(tree, node_list) == EXIT_FAILURE)
        return (84);
    add_binary_value(&tree, 0, "", "");
    add_tree(file, tree);
    return (EXIT_SUCCESS);
}
