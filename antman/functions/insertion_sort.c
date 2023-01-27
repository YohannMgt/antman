/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** insertion_sort
*/

#include "../include/my.h"

void reverse_node_list(node_t **list, int size)
{
    node_t *tmp_node = malloc(sizeof(node_t));

    for (int i = 0; i < size / 2; i++) {
        tmp_node = list[i];
        list[i] = list[size - i - 1];
        list[size - i - 1] = tmp_node;
    }
}

void insertion_sort(node_t **list, int size)
{
    node_t *tmp_node = malloc(sizeof(node_t));
    int j;

    for (int i = 1; i < size; i++) {
        tmp_node = list[i];
        j = i;
        while (j > 0 && list[j - 1]->frequency > tmp_node->frequency)
            list[j--] = list[j - 1];
        list[j] = tmp_node;
    }
    reverse_node_list(list, size);
}
