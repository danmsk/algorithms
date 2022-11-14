#include "test_utills.h"
#include <stdio.h>

// TODO:
// Написать тесты на memcpy
// Написать тесты на сортировку
// Залить на гит, когда все тесты пройдут

// Написать сортировку подсчетами
// Написать быструю сортировку

void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void sort(int *array, int size) {
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - 1 - i; ++j) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
      }
    }
  }
}

void check_swap(int a, int b) {
  int old_a = a;
  int old_b = b;

  swap(&a, &b);
  expect_equal(old_a, b);
  expect_equal(old_b, a);
}

void test_swap() {
  check_swap(1, 2);
  check_swap(1, 1);
  check_swap(1, 100500);
  check_swap(-100500, 100500);
  check_swap(9, 42);
}

int min(int *array, size_t size) {
  int min = array[0];
  for (int i = 0; i < size; ++i) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

int max(int *array, size_t size) {
  int max = array[0];
  for (int i = 0; i < size; ++i) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

void check_contains_all_element(int *original, int *sorted, int size) {
  int maxo = max(original, size);
  int mino = min(original, size);
  int elements_original[maxo - mino + 1];
  for (int i = 0; i < maxo - mino + 1; ++i) {
    elements_original[i] = 0;
  }
  for (int i = 0; i < size; ++i) {
    elements_original[original[i] - mino]++;
  }
  int maxs = max(sorted, size);
  int mins = min(sorted, size);
  int elements_sorted[maxs - mins + 1];
  for (int i = 0; i < maxs - mins + 1; ++i) {
    elements_sorted[i] = 0;
  }
  for (int i = 0; i < size; ++i) {
    elements_sorted[sorted[i] - mins]++;
  }
  for (int i = 0; i < maxs - mins; ++i) {
    expect_equal(elements_original[i], elements_sorted[i]);
  }
}

void check_sorted(int *sorted, int size) {
  for (int i = 0; i < size - 1; ++i) {
    if (sorted[i] > sorted[i + 1]) {
      printf("error\n");
    }
  }
}

void danil_memcpy(int *dst, int *src, size_t size) {
  for (int i = 0; i < size; ++i) {
    dst[i] = src[i];
  }
}

void check_danil_memcpy(int *dst, int *src, size_t size) {
  danil_memcpy(dst, src, size);
  for (int i = 0; i < size; ++i) {
    if (dst[i] != src[i]) {
      printf("expected%c, actual%c\n", src[i], dst[i]);
    }
  }
}

void test_danil_memcpy() {
  size_t size = 5;
  int array_test[5] = {1, 2, 3, 4, 5};
  int array1[5] = {1, 1, 1, 1, 1};
  int array2[5] = {2, 2, 2, 2, 2};
  int array3[5] = {3, 3, 3, 3, 3};
  int array4[5] = {4, 4, 4, 4, 4};
  check_danil_memcpy(array_test, array1, size);
  check_danil_memcpy(array_test, array2, size);
  check_danil_memcpy(array_test, array3, size);
  check_danil_memcpy(array_test, array4, size);
}

void check_sort(int *original, size_t size) {
  int sorted[size];
  danil_memcpy(sorted, original, size);
  int a = 5;
  int b;

  sort(sorted, size);
  check_contains_all_element(original, sorted, size);
  check_sorted(sorted, size);
}

void test_sort() {
  {
    int array[] = {1, 5, 2, 14, 5, 21, 58, 3, 2, 16};
    check_sort(array, 10);
  }
  {
    int array[] = {100, 2, 6, 3, 8, -2, 3, 6, 7, 0};
    check_sort(array, 10);
  }
}

int main() {
  test_swap();
  test_sort();
  test_danil_memcpy();
}