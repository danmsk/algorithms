#include "stdbool.h"
#include "test_utils.h"
#include "vec.h"

void test_int_vec_get(struct int_vec *vec, int idx) {
  int i = int_vec_get(vec, idx);
  EXPECT(i == vec->data[idx]);
};

void test_int_vec_push(struct int_vec *vec, int value) {
  int_vec_push(vec, value);
  EXPECT(int_vec_get(vec, vec->size - 1) == value);
}

void test_int_vec_insert(struct int_vec *vec, int value, int position) {
  int_vec_insert(vec, value, position);
  EXPECT(vec->data[position] == value);
}

void test_int_vec_pop(struct int_vec *vec, int *value) {
  int test = vec->data[vec->size - 1];
  int_vec_pop(vec, value);
  EXPECT(test == *value);
}

void test_int_vec_remove(struct int_vec *vec, int position) {
  struct int_vec *old_vec = int_vec_create(vec->capacity);
  int_vec_remove(vec, position);
  for (int i = position; i < vec->size - 1; ++i) {
    EXPECT(vec->data[i] == old_vec->data[i + 1]);
  }
}

int main() {
  struct int_vec *vec = int_vec_create(5);
  int idx = 0;
  int value = 9;
  test_int_vec_get(vec, idx);
  test_int_vec_insert(vec, value, idx);
  test_int_vec_pop(vec, &value);
  test_int_vec_push(vec, value);
  test_int_vec_remove(vec, idx);
}