#include <stdio.h>
#include <string.h>

static void swap(char s[], int i, int j)
{
  char t = s[i];
  s[i] = s[j];
  s[j] = t;
}

static void _reverse_recur_(char s[], int i, int j)
{
  if (i < j) {
    swap(s, i, j);
    _reverse_recur_(s, ++i, --j);
  }
}

void reverse(char s[])
{
  _reverse_recur_(s, 0, strlen(s) - 1);
}

int main()
{
  char s[] = "hello world";
  reverse(s);
  printf("%s\n", s);
  return 0;
}
