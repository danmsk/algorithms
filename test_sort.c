#include "sort.h"
#include "test_utils.h"

typedef void (*sort_fn_t)(int *, size_t);

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

void check_contains_all_element(int *original, int *sorted, size_t size) {
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

void check_sorted(int *sorted, size_t size) {
  for (int i = 0; i < size - 1; ++i) {
    EXPECT(sorted[i] <= sorted[i + 1]);
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
  int src[5] = {1, 2, 3, 4, 5};
  int dst[5];
  check_danil_memcpy(dst, src, sizeof(src));

  int a = 5, b;
  check_danil_memcpy(&b, &a, sizeof(int));
}

void check_sort(int *original, size_t size, sort_fn_t sort) {
  int sorted[size];
  danil_memcpy(sorted, original, size * sizeof(int));
  sort(sorted, size);
  check_contains_all_element(original, sorted, size);
  check_sorted(sorted, size);
}

void test_sort(sort_fn_t sort) {
  {
    int array[] = {1, 5, 2, 14, 5, 21, 58, 3, 2, 16};
    check_sort(array, 10, sort);
  }
  {
    int array[] = {100, 2, 6, 3, 8, -2, 3, 6, 7, 0};
    check_sort(array, 10, sort);
  }
  {
    int array[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    check_sort(array, sizeof(array) / sizeof(int), sort);
  }
}

int main() {
  test_swap();
  test_danil_memcpy();
  test_sort(sort);
  test_sort(count_sort);
  test_sort(quick_sort);
}