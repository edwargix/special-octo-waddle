#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int m_getline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[]);

int main()
{
  int len; /* current line length */
  char line[MAXLINE]; /* current input line */

  while ((len = m_getline(line, MAXLINE)) > 0) {
    reverse(line);
    printf("%s", line);
  }

  return 0;
}

void reverse(char s[]) {
  int i, j;

  for (i = 0; s[i] != '\0'; i++) ;

  char tmp[i / 2];
  for (j = 0; j < i / 2; j++) {
    tmp[j] = s[j];
    s[j] = s[i - 1 - j];
  }

  for (j = 0; j < i / 2; j++) {
    s[i - 1 - j] = tmp[j];
  }
}

/* m_getline: read a line into s, return length
   needs 'm_' because `getline` is defined in stdio.h */
int m_getline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;

}
