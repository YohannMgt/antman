/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** display_tree
*/

#include "../include/my.h"

void display_tree(node_t *node, int level)
{
    if (node == NULL)
        return;
    level += 1;
    display_tree(node->left, level);
    for (int i = 0; i < level * 8; i++)
        my_printf(" ");
    if (node->code != NO_CODE)
        my_printf("{%c, %d, %s}\n", node->code, node->frequency, node->binary);
    else
        my_printf("{%d, %d, %s}\n", node->code, node->frequency, node->binary);
    display_tree(node->right, level);
}
