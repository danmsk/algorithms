#pragma once
#include <stdio.h>
#include <stdlib.h>

#define EXPECT(condition)                                                      \
  if (!(condition)) {                                                          \
    printf("condition " #condition " failed, line %d\n", __LINE__);            \
    abort();                                                                   \
  }
