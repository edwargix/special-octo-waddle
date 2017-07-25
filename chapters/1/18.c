#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int m_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
  int len; /* current line length */
  char line[MAXLINE]; /* current input line */

  while ((len = m_getline(line, MAXLINE)) > 0)
    if (line[0] != '\n') {
      printf("%s", line);
    }

  return 0;
}

/* m_getline: read a line into s, return length
   needs 'm_' because `getline` is defined in stdio.h */
int m_getline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  for (int j = i - 1; j > -1; j--) {
    if (s[j] != ' ' && s[j] != '\t') {
      i = j + 1;
    }
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;

}
