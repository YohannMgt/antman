/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** my_strcat_size
*/

#include "../include/my.h"

int my_strcat_size(char *dest, char const *src, int size_file)
{
    int j;
    for (j = 0; src[j] != '\0'; j++)
        dest[j + size_file] = src[j];
    dest[size_file + j] = '\0';
    return (size_file + j);
}
