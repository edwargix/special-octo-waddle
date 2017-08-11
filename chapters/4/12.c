#include <stdio.h>

int convert(int, char[]);

void itoa(int n, char s[])
{
  int i = convert(n, s);
  s[i] = '\0';
}

int convert(int n, char s[])
{
  static int i = 0;

  if (n < 0) {
    s[i++] = '-';
    n = -n;
  }

  if (n / 10)
    convert(n / 10, s);
  s[i++] = n % 10 + '0';

  return i;
}

int main()
{
  char s[10];
  itoa(-512, s);
  printf("%s\n", s);
  return 0;
}
