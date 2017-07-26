/* entab - convert spaces to the appropriate number of tabs when appropriate */

#include <stdio.h>

#define TAB_LENGTH 8

int main()
{
  int c,
    depth = 0,
    i,
    spcs = 0;

  while ((c = getchar()) != EOF) {
    ++depth;

    if (c == ' ') {
      ++spcs;

      if (depth % 8 == 0) {
        putchar('\t');
        spcs = 0;
      }

      continue;
    }

    for (i = 0; i < spcs; i++)
      putchar(' ');

    if (c == '\n') {
      depth = 0;
    }

    putchar(c);
  }

  return 0;
}
