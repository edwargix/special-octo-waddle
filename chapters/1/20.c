/* detab - convert tabs to the appropriate number of spaces */

#include <stdio.h>

#define TAB_LENGTH 8

int main()
{
  int c,
    depth = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      for (int i = 0; i < TAB_LENGTH - depth; ++i) {
        putchar(' ');
      }
      depth = 0;
      continue;
    }

    depth = depth >= TAB_LENGTH - 1 ? 0 : depth + 1;

    if (c == '\n') {
      depth = 0;
    }
    putchar(c);
  }

  return 0;
}
