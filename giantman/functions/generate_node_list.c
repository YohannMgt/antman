/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** generate_node_list
*/

#include "../include/my.h"

char *cut_last_part(char *src)
{
    char *res = malloc(sizeof(char) * 10);
    int i;
    for (i = 0; i < my_strlen(src); i++)
        if (src[i] == '\"')
            break;
    for (int j = 0; i + j < my_strlen(src); j++) {
        res[j] = src[i + j + 1];
    }
    return (res);
}

char *cut_first_part(char *src)
{
    char *res = malloc(sizeof(char) * 10);
    int i;
    for (i = 0; i < my_strlen(src) && src[i] != '\"'; i++)
        res[i] = src[i];
    return (res);
}

node_t **init_list(char **dict, int element_number)
{
    node_t **list = malloc(sizeof(node_t) * (NOT_ZERO(element_number)));
    for (int i = 0; i < element_number; i++) {
        list[i] = malloc(sizeof(node_t));
        list[i]->code = my_getnbr(cut_first_part(dict[i]));
        list[i]->frequency = my_getnbr(cut_last_part(dict[i]));
        list[i]->right = NULL;
        list[i]->left = NULL;
        list[i]->binary = malloc(sizeof(char) * 16);
        list[i]->binary[0] = '\0';
    }
    return (list);
}

node_list_t *dict_to_node(char **dict, int element_number)
{
    node_list_t *list = malloc(sizeof(node_list_t));
    list->node_number = element_number;
    list->list = init_list(dict, element_number);
    return (list);
}
