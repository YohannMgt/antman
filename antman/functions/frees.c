/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** frees
*/

#include "../include/my.h"

void free_ppm(ppm_t *ppm, dict_t *dict)
{
    free(ppm->file_arr);
    free(ppm->compress_file);
    free(ppm->new_file);
    free(ppm);
    free(dict->val);
    free(dict);
}
