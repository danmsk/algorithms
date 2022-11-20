#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void sort(int *array, size_t size) {
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - 1 - i; ++j) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
      }
    }
  }
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

bool is_sorted(int *array, size_t size) {
  for (int i = 0; i < size - 1; ++i) {
    if (array[i] > array[i + 1]) {
      return 0;
    }
  }
  return 1;
}

void danil_memcpy(void *dst, const void *src, size_t size) {
  char *d = dst;
  const char *s = src;
  for (int i = 0; i < size; ++i) {
    d[i] = s[i];
  }
}

void count_sort(int *array, size_t size) {
  int min, max;
  int count = 0;
  minmax(array, &min, &max, size);
  int counted[max - min + 1];
  count_elements(array, counted, size);
  for (int i = 0; i < max - min + 1; ++i) {
    for (int j = 0; j < counted[i]; ++j) {
      int k = i + min;
      danil_memcpy(&array[count], &k, sizeof(int));
      count++;
    }
  }
}

void push_right(int *array, int start, int end) {
  int mem = array[end];
  for (int i = end; i > start; --i) {
    danil_memcpy(&array[i], &array[i - 1], sizeof(int));
  }
  array[start] = mem;
}

void push_left(int *array, int start, int end) {
  int mem = array[start];
  for (int i = start; i < end; ++i) {
    danil_memcpy(&array[i], &array[i + 1], sizeof(int));
  }
  array[end] = mem;
}

size_t partition(int *array, size_t size) {
  size_t count_greater = 0;
  size_t pivot_index = 0;
  int pivot_value = array[pivot_index];
  for (int i = 0; i < size; ++i) {
    if (pivot_index + count_greater + 1 == size) {
      return pivot_index;
    }
    if (array[i] <= pivot_value) {
      swap(&array[pivot_index], &array[i]);
      pivot_index = i;
    } else {
      swap(&array[i], &array[size - count_greater - 1]);
      count_greater++;
      i--;
    }
  }
  return pivot_index;
}

void quick_sort(int *array, size_t size) {
  if (size < 2) {
    return;
  }
  if (is_sorted(array, size)) {
    return;
  }
  size_t pivot = partition(array, size);
  quick_sort(array + pivot + 1, size - pivot - 1);
  quick_sort(array, pivot);
}