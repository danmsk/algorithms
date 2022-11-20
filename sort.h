#pragma once
#include <stddef.h>

void sort(int *array, size_t size);
void swap(int *a, int *b);
void minmax(int *array, int *min, int *max, size_t size);
void count_elements(int *array, int *counted_elements, size_t size);
void danil_memcpy(void *dst, const void *src, size_t size);
void count_sort(int *array, size_t size);
void push_right(int *array, int start, int end);
void push_left(int *array, int start, int end);
void quick_sort(int *array, size_t size);