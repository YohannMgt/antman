/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** int_to_bin
*/

#include "../include/my.h"

char *int_to_bin(unsigned int nb)
{
    int res[32];
    char *tmp;
    int sum = 0;
    while (nb > 0) {
        res[sum] = nb % 2;
        nb = nb / 2;
        sum++;
    }
    tmp = malloc(sum);
    for (int j = sum - 1; j >= 0; j--) {
        tmp[(sum - 1) - j] = res[j] + 48;
    }
    tmp[sum] = '\0';
    return (tmp);
}
