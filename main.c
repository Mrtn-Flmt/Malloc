/*
** EPITECH PROJECT, 2022
** PSU-400
** File description:
** main
*/

#include <dlfcn.h>
#include <stdio.h>
#include "./include/header.h"
#include <unistd.h>
#include <pthread.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str += 1;
    }
    return (0);
}

int my_strlen(char const *str)
{
    int counts = 0;

    for (; *str != '\0'; str += 1)
        counts += 1;
    return (counts);
}

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = (nb * -1);
    }
    if (nb >= 10)
        my_putnbr(nb / 10);
    my_putchar((nb % 10) + 48);
}

int main(void)
{
    char *str = my_malloc(sizeof(char) * 6);
    char *str2 = my_malloc(sizeof(char) * 2);
    int *ptr = my_calloc(5, sizeof(int));
    if (!str) {
        my_putstr("lmao null\n");
        return (84);
    }
    for (int i = 0; i < 5; i++)
        my_putnbr(ptr[i]);
    for (int i = 0; i < 5; i++)
        ptr[i] = 10;
    str2[0] = 'c';
    str2[1] = '\0';
    str[0] = 'H';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 'o';
    str[5] = '\0';
    for (int i = 0; i < 5; i++)
        my_putnbr(ptr[i]);
    my_putstr(str);
    my_putstr(str2);
    str = my_realloc(str, sizeof(char) * 3);
    str[0] = 'B';
    str[1] = 'o';
    str[2] = '\0';
    my_putstr(str);
    my_putchar('\n');
    // ptr = my_reallocarray(ptr, 10, sizeof(int));
    return (0);
}