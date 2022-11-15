#include <stdio.h>
#include <stdlib.h>

#define EXPECT(condition)                                                      \
  if (!(condition)) {                                                          \
    printf("condition " #condition " failed, line %d\n", __LINE__);            \
    exit(-1);                                                                  \
  }

void expect_equal(int expected, int actual) {
  if (expected != actual) {
    printf("expected %d, found %d\n", expected, actual);
    exit(-1);
  }
}

void expect_le(int expected, int actual) {
  if (expected > actual) {
    printf("expected %d, found %d\n", expected, actual);
    exit(-1);
  }
}

void expect_ge(int expected, int actual) {
  if (expected < actual) {
    printf("expected %d, found %d\n", expected, actual);
    exit(-1);
  }
}