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
    node->binary = malloc(sizeof(char) * MALLOC_SIZE);
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
    node_t *parent = malloc(+sizeof(node_t));
    parent->right = malloc(sizeof(node_t));
    parent->left = malloc(sizeof(node_t));
    while (node_list->node_number > 2)
        merge_node(node_list);
    parent->frequency =
        node_list->list[0]->frequency + node_list->list[1]->frequency;
    parent->right = node_list->list[0];
    parent->left = node_list->list[1];
    parent->code = NO_CODE;
    parent->binary = malloc(sizeof(char) * MALLOC_SIZE);
    return (parent);

}
