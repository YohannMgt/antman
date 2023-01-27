/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** extract_metadata
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

char *extract_from_pos(char *file, int start, int end)
{
    char *res = malloc(sizeof(char) * end - start);

    for (int i = start + 1; i < end; i++)
        res[i - start - 1] = file[i];
    return (res);
}

char **make_file_arr(char *file, int size)
{
    int pos = find_pos(file) - 1;
    char **file_arr = malloc(sizeof(char) * size * 4);
    int start = pos;
    int end = pos;
    int index = 0;

    for (int i = pos + 1; i < size; i++) {
        if (file[i] == '\n') {
            start = end;
            end = i;
            file_arr[index++] = extract_from_pos(file, start, end);
        }
    }
    file_arr[index] = NULL;
    return (file_arr);
}
