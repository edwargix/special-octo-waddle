#include <stdio.h>
#include <stdbool.h>

/* squeeze: remove all characters from s that appear in c */
void squeeze(char s[], char c[])
{
  int i, j, k = 0;

  for (i = 0; s[i] != '\0'; ++i) {
    bool found = false;
    for (j = 0; c[j] != '\0'; ++j)
      if (s[i] == c[j]) {
        found = true;
        break;
      }

    if (!found) {
      s[k++] = s[i];
    }
  }

  s[k] = '\0';
}

int main()
{
  char str[] = "bitcoin";
  char rem[] = "in";
  squeeze(str, rem);
  printf("%s\n", str);
  return 0;
}
