#include <stdio.h>

int main()
{
  int c, was_last_blank = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (was_last_blank)
        continue;
      was_last_blank = 1;
    }
    else
      was_last_blank = 0;

    putchar(c);
  }
}
