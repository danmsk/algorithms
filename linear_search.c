#include <stdio.h>

void expect_equal(int expected, int actual) {
  if (expected != actual) {
    printf("expected %d, found %d\n", expected, actual);
  }
}

int find(int *array, int size, int value) {
  for (int i = 0; i < size; ++i) {
    if (array[i] == value)
      return i;
  }
  return -1;
}

int main() {
  int array[] = {5, 4, 1, 5, 6, 7, 8, 12, 3, 22};

  const int size = sizeof(array) / sizeof(int);

  expect_equal(0, find(array, size, 5));
  expect_equal(1, find(array, size, 4));
  expect_equal(4, find(array, size, 6));
  expect_equal(7, find(array, size, 12));
  expect_equal(-1, find(array, size, 100500));
}