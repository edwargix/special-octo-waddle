#include <stdio.h>

void m_strcat(char *s, char *t)
{
  while (*s++ != '\0') ;

  s--; // override '\0'

  while ((*s++ = *t++) != '\0') ;

  *s = '\0';
}


int main()
{
  char a[15] = "hello"; // leaves allocated space after {'h','e','l','l','o','\0'}
  char *b = "world";
  m_strcat(a,b);
  printf("%s\n", a);
  return 0;
}
