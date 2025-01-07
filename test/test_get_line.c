#include <stdio.h>

#include "get_line.h"

#define MAX_LENGTH 20

void test_get_line() {
  char s[MAX_LENGTH];

  printf(
      "Enter \'hello world\' (without '') and press enter to test "
      "get_line()\n");
  int len = get_line(s, MAX_LENGTH);

  int i = 0;
  char template[MAX_LENGTH] = "hello world\n";
  while (s[i] == template[i]) {
    if (s[i] == '\0') {
      break;
    }
    ++i;
  }

  if (i != len) {
    printf("ERROR in get_line(): failure\n");
  }
}

int main() {
  //comment if statement to do checks
  if(1){
    return 0;
  }
  test_get_line();
  return 0;
}
