#include "revert_line.h"

int revert_line(char s[], int lim) {
  int i, j, temp, len;

  for (i = 0; (s[i] != '\0') && (i < lim); ++i) {
    ;
  }

  len = i;      // the length of s[] (excluding '\0')
  i = len - 1;  // index of the last character
  j = 0;        // index of the first character

  temp = 0;
  for (j = 0; i > j; --i) {
    if (i == j) {
      break;
    }
    temp = s[i];
    s[i] = s[j];
    s[j++] = temp;
  }

  return 0;
}