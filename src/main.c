#include <stdio.h>

#include "copy_line.h"
#include "get_line.h"
#include "revert_line.h"
#include "trim_line.h"

#define MAX_LENGTH 1000  // the maximum length of a line that can be processed

int main() {
  int curr_len, max_len;  // the length of captured line
  char current[MAX_LENGTH];
  char longest[MAX_LENGTH];

  // take the longest line from the input
  max_len = 0;
  while ((curr_len = get_line(current, MAX_LENGTH)) > 0) {
    if (curr_len > max_len) {
      copy_line(current, longest, MAX_LENGTH);
      max_len = curr_len;
    }
  }

  int i;
  printf("The longest lint => ");
  for (i = 0; i <= max_len; ++i) {
    printf("%c", longest[i]);
  }

  if (max_len > 0) {
    trim_line(longest, max_len);
    printf("Trimmed line => %s\n", longest);
    revert_line(longest, max_len);
    printf("Reversed line => %s\n", longest);
    return 0;
  } else if (max_len == 0) {
    printf("There is no charater to process.\n");
    return 0;
  } else {
    printf("Something goes wrong\n");
    return 1;
  }
}