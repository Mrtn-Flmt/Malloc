/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-martin.flament
** File description:
** calloc
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "../include/header.h"
#include <string.h>

void *calloc(size_t nmemb, size_t size)
{
    size_t o_size;
    void *block;
    if (!nmemb || !size)
        return (NULL);
    o_size = nmemb * size;
    block = malloc(o_size);
    if (!block)
        return (NULL);
    memset(block, 0, o_size);
    return (block);
}
