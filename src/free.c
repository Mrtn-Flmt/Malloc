/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-martin.flament
** File description:
** free
*/

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "../include/header.h"
#include <string.h>

void free(void *ptr)
{
    header_t *header;
    header_t *tmp;
    void *program_break;

    if (!ptr)
        return;
    pthread_mutex_lock(&global_malloc_lock);
    header = (header_t*)ptr - 1;

    program_break = sbrk(0);
    if ((char*)ptr + header->size == program_break) {
        if (header == tail)
            header = tail = NULL;
        else {
            tmp = head;
            while (tmp) {
                if (tmp->next == tail) {
                    tmp->next = NULL;
                    tail = tmp;
                }
                tmp = tmp->next;
            }
        }
        sbrk(0 - sizeof(header_t) - header->size);
        pthread_mutex_unlock(&global_malloc_lock);
        return;
    }
    header->is_free = 1;
    pthread_mutex_unlock(&global_malloc_lock);
}
