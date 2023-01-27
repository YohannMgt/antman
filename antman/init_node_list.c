/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** generate_node_list
*/

#include "include/my.h"

int *init_char_list(void)
{
    int *list = malloc(sizeof(int) * MAX_CHAR);
    for (int i = 0; i < MAX_CHAR; i++) {
        list[i] = 0;
    }
    return (list);
}

node_t *create_node(int code, int frequency)
{
    node_t *node = malloc(sizeof(node_t));
    node->right = NULL;
    node->left = NULL;
    node->frequency = frequency;
    node->code = code;
    node->binary = malloc(sizeof(char) * MALLOC_SIZE);
    node->binary[0] = '\0';
    return (node);
}

node_t **reduce_char_list(int *list)
{
    int item_nb = count_item(list);
    node_t **node_list = malloc(sizeof(node_t) * (NOT_ZERO(item_nb)));
    int index = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (list[i] != 0)
            node_list[index++] = create_node(i, list[i]);
    }
    return (node_list);
}

node_list_t *init_node_list(char *file)
{
    node_list_t *node_list_st = malloc(sizeof(node_list_t));
    int *char_list = find_frequency(file);
    int size = count_item(char_list);
    node_t **new_list = reduce_char_list(char_list);
    insertion_sort(new_list, size);
    node_list_st->list = new_list;
    node_list_st->node_number = size;
    return (node_list_st);
}
