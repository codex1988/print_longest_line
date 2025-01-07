#include <stdio.h>

#include "revert_line.h"

void test_revert_line() {
  char s[] = "a b c";

  revert_line(s, 100);

  if (s[0] == 'c' && s[1] == 'b' && s[2] == 'a') {
    printf("ERROR in revert_line(): failure\n");
  }

}

int main() {
  test_revert_line();
  return 0;
}
