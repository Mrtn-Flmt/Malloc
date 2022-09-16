/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-martin.flament
** File description:
** realloc
*/

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "../include/header.h"
#include <string.h>

void *realloc(void *ptr, size_t size)
{
    header_t *header;
    void *tmp;
    if(!ptr || !size)
        return malloc(size);
    tmp = ptr - sizeof(header_t);
    if (size <= header->size)
        return (ptr);
    tmp = malloc(size);
    if (tmp) {
        memcpy(tmp, ptr, header->size);
        free(ptr);
    }
    return (tmp);
}
