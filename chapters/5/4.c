#include <stdio.h>

int strend(char *s, char *t)
{
  while (*s++ != '\0')
    if (*s == *t)
      while (*s++ == *t++)
        if (*s == '\0' && *t == '\0') return 1;

  return 0;
}


int main()
{
  char *a = "hello world";
  char *b = "world";
  int i = strend(a, b);
  printf("%d\n", i);

  b = "bogus";
  i = strend(a, b);
  printf("%d\n", i);

  return 0;
}
