#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}


void itob(int n, char s[], int b)
{
  int i, sign;

  sign = n;

  i = 0;
  do {
    s[i++] = abs(n % b) + '0' + (abs(n % b) > 9 ? 7 : 0);
  } while (n /= b);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}


int main()
{
  char s[25];
  itob(31, s, 16);
  printf("%s\n", s);

  return 0;
}
