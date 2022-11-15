#include "test_utills.h"
#include <stdint.h>
#include <stdio.h>

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
  EXPECT(old_a == b);
  EXPECT(old_b == a);
}

void test_swap() {
  check_swap(1, 2);
  check_swap(1, 1);
  check_swap(1, 100500);
  check_swap(-100500, 100500);
  check_swap(9, 42);
}

void minmax(int *array, int *min, int *max, size_t size) {
  *min = array[0];
  *max = array[0];
  for (int i = 0; i < size; ++i) {
    if (array[i] > *max) {
      *max = array[i];
    }
    if (array[i] < *min) {
      *min = array[i];
    }
  }
}

void count_elements(int *array, int *counted_elements, size_t size) {
  int min, max;
  minmax(array, &min, &max, size);
  for (int i = 0; i < max - min + 1; ++i) {
    counted_elements[i] = 0;
  }
  for (int i = 0; i < size; ++i) {
    counted_elements[array[i] - min]++;
  }
}

void check_contains_all_element(int *original, int *sorted, int size) {
  int min, max;
  minmax(original, &min, &max, size);
  int elements_original[max - min + 1];
  minmax(sorted, &min, &max, size);
  int elements_sorted[max - min + 1];
  count_elements(original, elements_original, size);
  count_elements(sorted, elements_sorted, size);
  for (int i = 0; i < max - min + 1; ++i) {
    EXPECT(elements_original[i] == elements_sorted[i]);
  }
}

void check_sorted(int *sorted, int size) {
  for (int i = 0; i < size - 1; ++i) {
    EXPECT(sorted[i] > sorted[i + 1]);
  }
}

void danil_memcpy(void *dst, const void *src, size_t size) {
  char *d = dst;
  const char *s = src;
  for (int i = 0; i < size; ++i) {
    d[i] = s[i];
  }
}

void check_danil_memcpy(void *dst, const void *src, size_t size) {
  char *d = dst;
  const char *s = src;
  danil_memcpy(dst, src, size);
  for (int i = 0; i < size; ++i) {
    EXPECT(s[i] == d[i]);
  }
}

void test_danil_memcpy() {
  size_t size = 5 * sizeof(int);
  int src[5] = {1, 2, 3, 4, 5};
  int dst[5];
  check_danil_memcpy(dst, src, sizeof(src));

  int a = 5, b;
  check_danil_memcpy(&b, &a, sizeof(int));
}

void check_sort(int *original, size_t size) {
  int sorted[size];
  danil_memcpy(sorted, original, size * sizeof(int));
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
  test_danil_memcpy();
  test_sort();
}