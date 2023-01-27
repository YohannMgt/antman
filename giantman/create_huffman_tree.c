/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** create_huffman_tree
*/

#include "include/my.h"

node_t *create_merged_node(node_t *right, node_t *left)
{
    node_t *node = malloc(sizeof(node_t));
    if (right == NULL)
        return (left);
    else if (left == NULL)
        return (right);
    node->right = right;
    node->left = left;
    node->frequency = left->frequency + right->frequency;
    node->code = NO_CODE;
    node->binary = malloc(sizeof(char) * 16);
    node->binary[0] = '\0';
    return (node);
}

void merge_node(node_list_t *list)
{
    list->list[list->node_number - 2] =
        create_merged_node(list->list[list->node_number - 1],
                            list->list[list->node_number - 2]);
    list->list[list->node_number - 1] = NULL;
    list->node_number--;
    insertion_sort(list->list, list->node_number);
}

node_t *create_huffman_tree(node_list_t *node_list)
{
    node_t *parent = malloc(sizeof(node_t));
    parent->right = malloc(sizeof(node_t));
    parent->left = malloc(sizeof(node_t));
    if (node_list->node_number == 0)
        return (NULL);
    while (node_list->node_number > 2)
        merge_node(node_list);
    parent->frequency =
        node_list->list[0]->frequency + node_list->list[1]->frequency;
    parent->right = node_list->list[0];
    parent->left = node_list->list[1];
    parent->code = NO_CODE;
    parent->binary = malloc(sizeof(char) * 16);
    return (parent);

}

char *remove_tree_info(char **file, int element_number, char **dict)
{
    char *new_file = malloc(sizeof(char) *
        (my_strlen(*file) - element_number));
    int info_size = 0;
    for (int i = 0; dict[i] != NULL; i++)
        info_size += my_strlen(dict[i]) + 1;
    for (int i = info_size; i < my_strlen(*file); i++)
        new_file[i - info_size] = (*file)[i];
    return (new_file);
}

node_t *init_tree(char **file)
{
    char **dictionary = make_dictionary(*file);
    int i;
    for (i = 0; dictionary[i] != NULL; i++)
        ;
    node_list_t *list = dict_to_node(dictionary, i);
    node_t *tree = create_huffman_tree(list);
    *file = remove_tree_info(file, i, dictionary);
    if (check_size(list, tree) == EXIT_FAILURE)
        return (NULL);
    return (tree);
}
