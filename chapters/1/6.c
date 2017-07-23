#include <stdio.h>

/* copy input to output; 1st version */
main()
{
  int c;

  while ((c = getchar()) != EOF) {
    printf("%d", c != EOF); // prints 1
    putchar(c);
  }
}
