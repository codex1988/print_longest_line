#include <stdio.h>

#include "trim_line.h"

void test_trim_line() {
  char s[] = "\t\t    hello    world    ";
  trim_line(s, 100);
  // int i;
  // for(i = 0; i < 12; ++i) {
  //   printf("%c\n", s[i]);
  // } 
}

int main() {
  test_trim_line();
  return 0;
}
