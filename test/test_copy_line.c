#include <stdio.h>

#include "copy_line.h"

#define LIMIT 12

void test_copy_line() {
  char input[LIMIT] = "hello world";
  char output[LIMIT] = "ooooo ooooo";
  int val;
  val = copy_line(input, output, LIMIT);

  if (val == 1) {
    printf("ERROR in copy_line(): function failure #1\n");
  }

  int i = 0;
  while (output[i] == input[i]) {
    if (output[i] == '\0') {
      break;
    }
    ++i;
  }

  if (i != LIMIT - 1) {
    printf("ERROR in copy_line(): function failure #2\n");
  }
  
}

int main() {
  test_copy_line();
  return 0;
}
