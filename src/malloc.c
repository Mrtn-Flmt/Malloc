/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-martin.flament
** File description:
** malloc
*/

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "../include/header.h"
#include <string.h>

void *malloc(size_t size)
{
    size_t total_size;
	void *block;
	header_t *header;
    
	if (size == 0)
		return NULL;
	pthread_mutex_lock(&global_malloc_lock);
	header = get_free_block(size);
	if (header) {
		header->is_free = 0;
		pthread_mutex_unlock(&global_malloc_lock);
		return (void*)(header + 1);
	}
	total_size = sizeof(header_t) + size;
	block = sbrk(total_size);
	if (block == (void*) -1) {
		pthread_mutex_unlock(&global_malloc_lock);
		return NULL;
	}
	header = block;
	header->size = size;
	header->is_free = 0;
	header->next = NULL;
	if (!head)
		head = header;
	if (tail)
		tail->next = header;
	tail = header;
	pthread_mutex_unlock(&global_malloc_lock);
	return (void*)(header + 1);
}

header_t *get_free_block(size_t size)
{
	header_t *current = head;
	while(current) {
		if (current->is_free && current->size >= size)
			return current;
		current = current->next;
	}
	return NULL;
}
