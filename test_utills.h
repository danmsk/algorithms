#include <stdio.h>
#include <stdlib.h>

void expect_equal(int expected, int actual) {
  if (expected != actual) {
    printf("expected %d, found %d\n", expected, actual);
    exit(-1);
  }
}