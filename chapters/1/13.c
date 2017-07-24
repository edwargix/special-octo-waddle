#include <stdio.h>

#define OUT 0
#define IN 1
#define MAX_LENGTH 10

int main()
{
  int c,
    state = OUT,
    counts[MAX_LENGTH],
    wl = 0,
    i = 0;

  for (i = 0; i < MAX_LENGTH; ++i)
    counts[i] = 0;


  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        ++counts[wl - 1];
        wl = 0;
      }
      state = OUT;
      continue;
    }

    state = IN;
    ++wl;
  }

  printf("length");

  for (i = 1; i <= MAX_LENGTH; ++i) {
    printf("%3d |", i);
  }

  printf("\nfreq  ");

  for (i = 0; i < MAX_LENGTH; ++i) {
    printf("%3d |", counts[i]);
  }

  putchar('\n');

}
