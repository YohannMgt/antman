/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** antman
*/

#include "include/my.h"

void create_sequence(ppm_t *ppm, int rec)
{
    for (int i = 0; ppm->file_arr[i] != NULL; i++) {
        if (my_strcmp(ppm->file_arr[UP(i - 1)], ppm->file_arr[i]) == 0)
            rec++;
        else {
            rec = 1;
            ppm->nb_seq++;
        }
        ppm->compress_file[ppm->nb_seq - 1] = malloc((sizeof(dict_t)));
        ppm->compress_file[ppm->nb_seq - 1]->val = ppm->file_arr[i];
        ppm->compress_file[ppm->nb_seq - 1]->rec = rec;
    }
}

void add_sequence(ppm_t *ppm)
{
    for (int j = 0; j < ppm->nb_seq; j++) {
        ppm->size_file = my_strcat_size(ppm->new_file,
        ppm->compress_file[j]->val, ppm->size_file);
        ppm->size_file = my_strcat_size(ppm->new_file, ":", ppm->size_file);
        ppm->size_file = my_strcat_size(ppm->new_file,
        int_to_str(ppm->compress_file[j]->rec), ppm->size_file);
        if (j < ppm->nb_seq) {
            ppm->size_file = my_strcat_size(ppm->new_file, "|",
            ppm->size_file);
        }
    }
}

int compress_ppm(char *file, int size)
{
    ppm_t *ppm = malloc(sizeof(ppm_t));
    dict_t *dict = malloc(sizeof(dict_t));
    int rec = 0;
    int pos = find_pos(file) - 1;

    ppm->file_arr = make_file_arr(file, size);
    ppm->compress_file = malloc(sizeof(char) * size * 4);
    ppm->nb_seq = 1;
    ppm->new_file = malloc(sizeof(char) * size * 4);
    ppm->size_file = 0;
    for (int i = 0; i < pos; i++)
        my_printf("%c", file[i]);
    my_printf("\n");
    create_sequence(ppm, rec);
    add_sequence(ppm);
    write(1, ppm->new_file, ppm->size_file + 1);
    free_ppm(ppm, dict);
    return (EXIT_SUCCESS);
}
