#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[argc])
{
  // defaults
  int start_column = 0;
  int tabs_every = 8;

  // set starting column and tab stops
  int i;
  for (i = 0; i < argc; i++) {
    if (argv[i][0] == '-') // arg begins with a -
      start_column = atoi(argv[i] + 1);
    else if (argv[i][0] == '+') // arg begins with a +
      tabs_every = atoi(argv[i] + 1);
  }

  int c; // current char in input
  int cspace = 0;
  int line_length = 0;

  while ((c = getchar()) != EOF) {
    ++line_length;

    if (c == ' ') {
      if (line_length <= start_column)
        putchar(c);
      else if (++cspace >= tabs_every) {
        putchar('\t');
        cspace = 0;
      }

      continue;
    } else {
      for (i = 0; i < cspace; ++i) putchar(' ');

      if (c == '\n') {
        line_length = 0;
      }
    }

    cspace = 0;
    putchar(c);
  }

  if (cspace > 0) {
    for (i = 0; i < cspace; i++) {
      putchar(' ');
    }
  }

  return 0;
}
