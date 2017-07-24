#include <stdio.h>
#include <limits.h>

int main()
{
  int c,
    freq[UCHAR_MAX],
    i;

  for (i = 0; i < UCHAR_MAX; ++i) freq[i] = 0;


  while ((c = getchar()) != EOF)
    ++freq[c+128];

  for (int i = 0; i < UCHAR_MAX; i++) {
    printf("'%c' : %3d\n", (char)(i - 128), freq[i]);
  }

  return 0;
}

