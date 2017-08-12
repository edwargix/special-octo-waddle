#include <stdio.h>

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t)
{
  char *ip, *jp, *kp;

  for (ip = s; *ip != '\0'; ++ip) {
    for (jp=ip, kp = t; *kp!='\0' && *jp==*kp; jp++, kp++)
      ;
    if (kp > t && *kp == '\0')
      return ip - s;
  }

  return -1;
}


int main()
{
  char *a = "abcdefg";
  char *b = "fg";
  int i = strindex(a, b);
  printf("%d\n", i);
  return 0;
}
