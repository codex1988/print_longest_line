#include "trim_line.h"

#include <stdio.h>

int trim_line(char s[], int lim) {
  int i = 0;             // read index
  int y = 0;             // write index
  int space_before = 0;  // zero - no space befor, one - there is space befor

  // trim at the beginning
  while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ') {
    ++i;
  }

  // trim in the middle and at the end
  while (s[i] != '\0' && i < lim - 1) {
    if (s[i] == '\n') {
      s[y++] = '\n';
      break;
    }
    if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
      if (space_before) {
        i++;
        continue;
      }
      s[y++] = ' ';
      space_before = 1;
    } else {
      s[y++] = s[i++];
      space_before = 0;
    }
  }

  s[y] = '\0';

  return 0;
}