#include <stdio.h>

int m_getline(char *s, int lim)
{
  int c;
  char *pn;

  pn = s;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *pn++ = c;
  if (c == '\n')
    *pn++ = c;
  *pn = '\0';
  return pn - s;
}

#define LIMIT 100

int main()
{
  char a[LIMIT];
  int status = m_getline(a, LIMIT);
  printf("%d: %s\n", status, a);
  return 0;
}
