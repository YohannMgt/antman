/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** find_pos
*/

#include "../include/my.h"

int find_pos(char *file)
{
    int target = PPM_METADATA;
    int index = 0;

    while (target > 0 || index >= my_strlen(file)) {
        target = (file[index] == '\n') ? target - 1 : target;
        target = (file[index] == '#' &&
        file[UP(index - 1)] == '\n') ? target + 1 : target;
        index++;
        if (target == 1 && file[index + 1] == '#')
            target++;
    }
    return (index);
}
