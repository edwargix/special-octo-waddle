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

void itoa(int n, char s[], int w)
{
  int i, j, sign;

  char t[w + 1]; // string with just number

  sign = n;

  i = 0;
  do {
    t[i++] = abs(n % 10) + '0';
  } while (n /= 10);

  if (sign < 0)
    t[i++] = '-';

  // this places an even number of spaces on each side of the number with an
  // extra one the left if uneven

  int blanks = (w - i) / 2; // number of spaces on left (trailing number after
                            // reverse)
  for (j = 0; j < blanks; ++j) s[j] = ' '; // leading spaces


  for (j = blanks; j < blanks + i; ++j) s[j] = t[j - blanks]; // insert digits


  for (j = blanks + i; j < w; ++j) s[j] = ' '; // trailing spaces


  reverse(s);
  s[w] = '\0';
}


int main()
{
  char s[25];
  itoa(5, s, 6);
  printf("%s\n", s);
  return 0;
}
