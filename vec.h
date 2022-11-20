#pragma once
#include <stdint.h>

void *danil_malloc(size_t size);
void danil_free(void *addr, size_t size);
struct int_vec *int_vec_create(int initial_capacity);
struct int_vec {
  int *data;
  int size;     // current elements count
  int capacity; // current max elements count
};
int int_vec_get(struct int_vec *vec, int idx);
void int_vec_push(struct int_vec *vec, int value);
void int_vec_dealloc(struct int_vec *vec);
void int_vec_insert(struct int_vec *vec, int value, int position);
bool int_vec_pop(struct int_vec *vec, int *value);
void int_vec_remove(struct int_vec *vec, int position);
