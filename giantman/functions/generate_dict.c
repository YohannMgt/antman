/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** generate_dict
*/

#include "../include/my.h"

char *add_entry(char *file, int pos)
{
    char *entry = malloc(sizeof(char) * 10);
    int index = 0;
    int i;
    for (i = pos - 2; file[i] != '!' && i >= 0; i--)
        ;
    for (int j = i + 1; j < pos - 1; j++)
        entry[index++] = file[j];
    return (entry);
}

char **make_dictionary(char *file)
{
    char **dictionary = malloc(sizeof(char) * 10 * MAX_CHAR);
    int index = 0;
    for (int i = 0; file[i] != '\0'; i++)
        if (file[NOT_NEG(i - 1)] == '!')
            dictionary[index++] = add_entry(file, i);
    dictionary[index] = NULL;
    return (dictionary);
}
