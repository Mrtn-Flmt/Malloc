/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-martin.flament
** File description:
** header
*/

#include <pthread.h>

typedef char ALIGN[16];

struct header {
	size_t size;
	unsigned is_free;
	struct header_t *next;
} typedef header_t;

pthread_mutex_t global_malloc_lock;
header_t *head;
header_t *tail;

header_t *get_free_block(size_t size);

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);
