#include <string.h>
#include <stdio.h>

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
  int i, j, k;

  for (i = strlen(s) - 1; i >= 0; --i) {
    for (j=i, k=strlen(t)-1; k>=0 && s[j]==t[k]; --j, --k)
      ;
    if (k < 0)
      return i - (strlen(t) - 1);
  }

  return -1;
}


int main()
{
  char s[] = "asdffffffdffff";
  printf("%d\n", strindex(s, "df"));
  return 0;
}
