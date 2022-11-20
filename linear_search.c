#include <stdio.h>

int find(int *array, int size, int value) {
  for (int i = 0; i < size; ++i) {
    if (array[i] == value)
      return i;
  }
  return -1;
}