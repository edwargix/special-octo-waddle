#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *s)
{
  int c;
  char *pi, *pj;

  for (pi = s, pj = s + strlen(s) - 1; pi < pj; ++pi, --pj) {
    c = *pi;
    *pi = *pj;
    *pj = c;
  }
}


void itoa(int n, char *s)
{
  int sign;
  char *pn;

  sign = n;

  pn = s;
  do {
    *pn++ = abs(n % 10) + '0';
  } while (n /= 10);

  if (sign < 0)
    *pn++ = '-';
  *pn = '\0';
  reverse(s);
}


int main()
{
  char a[25];
  itoa(-56, a);
  printf("%s\n", a);
  return 0;
}
