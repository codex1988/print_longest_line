#include "get_line.h"

#include <stdio.h>

int get_line(char s[], int lim) {
  int i = 0;
  int c;

  while (i < lim - 1 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }

  // Handle newline character
  if (c == '\n' && i < lim - 1) {
    s[i++] = c;
  }

  // Ensure null terminating
  s[i] = '\0';

  return i;  // Return the number of characters read (excluding null terminator)
}
