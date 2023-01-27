/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** decompress_ppm
*/

#include "include/my.h"

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
    char **file_arr = malloc(sizeof(char) * size * 2);
    int start = pos;
    int end = pos;
    int index = 0;

    for (int i = pos + 1; i < size; i++) {
        if (file[i] == '|') {
            start = end;
            end = i;
            file_arr[index++] = extract_from_pos(file, start, end);
        }
    }
    file_arr[index] = NULL;
    return (file_arr);
}

void add_sequence(ppm_t *ppm)
{
    for (int i = 0; i < ppm->nb_seq; i++) {
        for (int j = 0; j < ppm->decompress_file[i]->rec; j++) {
            ppm->size_file = my_strcat_size(ppm->new_file,
            int_to_str(ppm->decompress_file[i]->val), ppm->size_file);
            ppm->size_file = my_strcat_size(ppm->new_file, "\n",
            ppm->size_file);
        }
    }
}

int decompress_ppm(char *file, int size)
{
    ppm_t *ppm = malloc(sizeof(ppm_t));
    dict_t *dict = malloc(sizeof(dict_t));
    int pos = find_pos(file) - 1;

    ppm->file_arr = make_file_arr(file, size);
    ppm->decompress_file = malloc(sizeof(char) * size * 2);
    ppm->nb_seq = 0;
    ppm->new_file = malloc(sizeof(char) * size * 10);
    ppm->size_file = 0;

    for (int i = 0; i < pos; i++)
        my_printf("%c", file[i]);
    my_printf("\n");
    create_sequence(ppm);
    add_sequence(ppm);
    write(1, ppm->new_file, ppm->size_file);
    return (0);
}
