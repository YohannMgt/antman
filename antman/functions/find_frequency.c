/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** find_frequency
*/

#include "../include/my.h"

int *find_frequency(char *file)
{
    int size = my_strlen(file);
    int *char_list = malloc(sizeof(int) * MAX_CHAR);
    for (int i = 0; i < size; i++) {
        char_list[(unsigned char)file[i]] += 1;
    }
    return (char_list);
}
