#include <stdio.h>
#include <stddef.h>
#include <string.h>


char *strncpy(char *s, const char *ct, size_t n)
{
  if (n == 0) return s;

  size_t i = 0;
  while ((*s++ = *ct++) != '\0' && ++i < n) ;
  if (*(s - 1) == '\0') i++;
  s -= i;
  return s;
}

char *strncat(char *s, const char *ct, size_t n)
{
  if (n == 0) return s;

  size_t i;
  char *o = s;

  i = 0;
  o += strlen(s);
  while((*o++ = *ct++) != '\0' && ++i < n) ;
  if (*o != '\0') *(o++) = '\0';
  return s;
}

int strncmp(const char *cs, const char *ct, size_t n)
{
  if (n == 0) return 0;

  for (size_t i = 0 ; *cs == *ct; cs++, ct++) {
    if (++i >= n) break;
    if (*cs == '\0')
      return 0;
  }
  return *cs - *ct;
}


int main()
{
  const char *e = "goodbye!";

  printf("strncpy(hello, %s, n):\n", e);
  for (size_t i = 0; i < 20; ++i) {
    char a[20] = "hello";
    char *c = strncpy(a, e, i);
    printf("n=%lu:%s\n", i, c);
  }

  printf("strncat(bitcoin, %s, n):\n", e);
  for (size_t i = 0; i < 20; ++i) {
    char a[20] = "lampshade";
    char *d = strncat(a, e, i);
    printf("n=%lu:%s\n", i, d);
  }

  printf("strncmp(goodluck, %s, n):\n", e);
  for (size_t i = 0; i < 20; ++i) {
    char a[20] = "goodluck";
    int r = strncmp(a, e, i);
    printf("n=%lu:%d\n", i, r);
  }


  return 0;
}
