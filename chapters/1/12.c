#include <stdio.h>

#define OUT_WORD 0
#define IN_WORD 1

int main()
{
  int c,
    state = OUT_WORD;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN_WORD) putchar('\n');
      state = OUT_WORD;
      continue;
    }

    state = IN_WORD;

    putchar(c);
  }
}
