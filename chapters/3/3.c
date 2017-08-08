#include <stdio.h>

// return range category of `c', returning 0 if not in one
char category(char c)
{
  if (c >= 'a' && c <= 'z') return 1;
  if (c >= 'A' && c <= 'Z') return 2;
  if (c >= '0' && c <= '9') return 3;
  return 0;
}


void expand(char s1[], char s2[])
{
  // this assumes that s2 has enough space

  int c, i, j;
  char a, b;

  for (i = 0, j = 0; (c = s1[i]) != '\0'; ++i) {
    if (s1[i + 1] == '-')
      if ((a = category(c)) && (b = category(s1[i + 2]))) {
        if (a == b) { // if endpoints in same category
          a = c;
          b = s1[i + 2];

          if (a > b) // descending order
            while (a >= b)
              s2[j++] = a--;
          else // ascending order
            while (a <= b)
              s2[j++] = a++;

          i += 2; // skip letters for specifying range; will be 3 after
                  // increment step of for loop
          continue;
        }
      }

    s2[j++] = c;
  }

  s2[j] = '\0';
}


int main()
{
  char s[] = "-c-f- -hello- 5-8-9 Y-B";
  char t[100];
  expand(s, t);
  printf("%s\n", t);
  return 0;
}
