/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** create_sequence
*/

#include "../include/my.h"

char *first_part(char *src)
{
    char *res = malloc(sizeof(char) * 10);

    for (int i = 0; src[i] != ':'; i++) {
        res[i] = src[i];
    }
    return (res);
}

char *last_part(char *src)
{
    char *res = malloc(sizeof(char) * 10);
    int i = 0;
    int j = 0;

    for (i; src[i] != ':'; i++);
    i++;
    for (i; src[i] != '|' && src[i] != '\0'; i++) {
        res[j] = src[i];
        j++;
    }
    return (res);
}

void split_sequence(ppm_t **ppm, int i)
{
    (*ppm)->decompress_file[(*ppm)->nb_seq] = malloc((sizeof(dict_t)));
    (*ppm)->decompress_file[(*ppm)->nb_seq]->val =
    my_getnbr(first_part((*ppm)->file_arr[(*ppm)->nb_seq]));
    (*ppm)->decompress_file[(*ppm)->nb_seq]->rec =
    my_getnbr(last_part((*ppm)->file_arr[(*ppm)->nb_seq]));
    (*ppm)->nb_seq += 1;
}

void create_sequence(ppm_t *ppm)
{
    for (int i = 0; ppm->file_arr[i] != NULL; i++) {
        split_sequence(&ppm, i);
    }
}
