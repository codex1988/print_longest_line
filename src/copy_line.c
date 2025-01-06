#include "copy_line.h"

int copy_line(char from[], char to[], int lim) {
  int i, y;

  i = 0;
  while (from[i] != '\0') {
    ++i;
    if (i >= lim) {
      return 1;  // failed
    }
  }

  y = 0;
  while (to[y] != '\0') {
    ++y;
    if (y >= lim) {
      return 1;  // failed
    }
  }

  // if capacity of from[] is larger that capacity of to[] then failure.
  if (i > y) {
    return 1;
  }

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }

  to[i] = '\0';  // ensuring null terminating

  return 0;
}
