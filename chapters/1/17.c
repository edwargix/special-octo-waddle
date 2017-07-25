#include <stdio.h>

#define LIMIT 1000

int m_getline(char s[], int limit);

int main()
{
  int len;
  char str[LIMIT];
  while((len = m_getline(str, LIMIT)) > 80)
    printf("%s", str);

  return 0;
}

int m_getline(char s[], int limit) {
  int c,
    l = 0;

  while ((c = getchar()) != EOF && c != '\n' && l < limit - 1) {
    s[l] = c;
    ++l;
  }

  if (c == '\n') {
    s[l] = c;
    ++l;
  }

  s[l] = '\0';
  return l;
}
