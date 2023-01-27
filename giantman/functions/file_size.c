/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** file_size
*/

#include "../include/my.h"

int file_size(char *path)
{
    struct stat sb;
    stat(path, &sb);
    return (sb.st_size);
}
