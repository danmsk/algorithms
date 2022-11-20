#include <stdbool.h>
#include <stdio.h>
#include <sys/mman.h>

void *danil_malloc(size_t size) {
  return mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,
              -1, 0);
}

void danil_free(void *addr, size_t size) { munmap(addr, size); }

struct int_vec {
  int *data;
  int size;
  int capacity; // current max elements count
};

struct int_vec *int_vec_create(int initial_capacity) {
  struct int_vec *vec = danil_malloc(sizeof(struct int_vec));
  vec->data = danil_malloc(sizeof(int) * initial_capacity);
  vec->size = 0;
  vec->capacity = initial_capacity;
  return vec;
};

int int_vec_get(struct int_vec *vec, int idx) { return (*vec).data[idx]; };

void int_vec_push(struct int_vec *vec, int value) {
  if (vec->size < vec->capacity) {
    vec->data[vec->size] = value;
    vec->size++;
  } else {
    vec->capacity *= 2;
    int *new_array = danil_malloc(sizeof(int) * vec->capacity);
    for (int i = 0; i < vec->size; ++i) {
      new_array[i] = vec->data[i];
    }
    danil_free(vec->data, vec->size);
    vec->data = new_array;
    vec->data[vec->size] = value;
    vec->size++;
  }
}

void int_vec_dealloc(struct int_vec *vec) {
  danil_free(vec, sizeof(struct int_vec));
}

void int_vec_insert(struct int_vec *vec, int value, int position) {
  if (vec->size < vec->capacity) {
    vec->size++;
    for (int i = vec->size; i > position; --i) {
      vec->data[i] = vec->data[i - 1];
    }
    vec->data[position] = value;
  } else {
    vec->capacity *= 2;
    int *new_array = danil_malloc(sizeof(int) * vec->capacity);
    for (int i = 0; i < vec->size; ++i) {
      new_array[i] = vec->data[i];
    }
    danil_free(vec->data, vec->size);
    vec->data = new_array;
    vec->size++;
    for (int i = vec->size; i > position; --i) {
      vec->data[i] = vec->data[i - 1];
    }
    vec->data[position] = value;
  }
}

bool int_vec_pop(struct int_vec *vec, int *value) {
  if (vec->size == 0) {
    return false;
  }
  *value = vec->data[vec->size - 1];
  vec->size--;
  return true;
}

void int_vec_remove(struct int_vec *vec, int position) {
  for (int i = position; i < vec->size; ++i) {
    vec->data[i] = vec->data[i + 1];
  }
  vec->size--;
}