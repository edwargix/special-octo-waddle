#include <stdio.h>
#include <ctype.h>

int atoi(char *s)
{
  int n, sign;

  while (isspace(*s)) /* skip white space */
    s++;
  sign = (*s == '-') ? -1 : 1;
  if (*s == '+' || *s == '-') /* skip sign */
    s++;
  for (n = 0; isdigit(*s); ++s)
    n = 10 * n + (*s - '0');
  return sign * n;
}


int main()
{
  int i = atoi(" -97 ");
  printf("%d\n", i);
  return 0;
}
