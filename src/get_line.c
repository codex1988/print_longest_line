#include "get_line.h"

#include <stdio.h>

int get_line(char s[], int lim) {
  int i = 0;
  int c;

  while ((c = getchar()) != EOF && c != '\n') {
    if (i >= lim - 1) {
      ++i;
    } else {
      s[i++] = c;
    }
  }

  if (c == '\n' && i < lim - 1) {
    s[i++] = c;
    s[i] = '\0';  // Ensure null terminating
    // Return the number of characters captured (excluding null terminator)
    return i;
  } else if (c == '\n' && i >= lim - 1) {
    printf(
        "WARNING: You exceed the limit of line capacity. It's been "
        "truncated\n");
    printf("NOTE: The length of the full line is accurate.\n");
    s[lim - 2] = '\n';
    s[lim - 1] = '\0';
    // Return the number of characters read (excluding null terminator)
    return i;
  } else {
    s[i++] = '\0';
    // Return the number of characters captured (excluding null terminator)
    return i - 1;
  }
}
