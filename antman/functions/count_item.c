/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** count_item
*/

#include "../include/my.h"

int count_item(int *list)
{
    int count = 0;
    for (int i = 0; i < MAX_CHAR; i++)
        if (list[i] != 0)
            count++;
    return (count);
}
