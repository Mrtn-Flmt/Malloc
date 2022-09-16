/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-martin.flament
** File description:
** reallocarray
*/

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "../include/header.h"
#include <string.h>

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return (realloc(ptr, nmemb * size));
}
