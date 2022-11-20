#include "linear_search.h"
#include "test_utils.h"

void test_linear_search() {
  int array[] = {5, 4, 1, 5, 6, 7, 8, 12, 3, 22};

  const int size = sizeof(array) / sizeof(int);

  EXPECT(0 == find(array, size, 5));
  EXPECT(1 == find(array, size, 4));
  EXPECT(4 == find(array, size, 6));
  EXPECT(7 == find(array, size, 12));
  EXPECT(-1 == find(array, size, 100500));
}

int main() { test_linear_search(); }
