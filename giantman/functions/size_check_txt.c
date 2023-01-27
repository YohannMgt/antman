/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** size_check_txt
*/

#include "../include/my.h"

int check_size(node_list_t *list, node_t *tree)
{
    int sum = 0;
    for (int i = 0; i < list->node_number; i++)
        sum += list->list[i]->frequency;
    if (sum != tree->frequency)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
