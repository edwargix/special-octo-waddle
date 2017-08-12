#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buffer */

int getch(void) /* get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

#define NUMBER '0'

/* getop: get next operator or numeric operand */
int getop(char *s)
{
  int i, c;
  char *pn = s;

  while ((*pn = c = getch()) == ' ' || c == '\t')
    ;
  *(pn + 1) = '\0';
  if (!isdigit(c) && c != '.')
    return c; /* not a number */
  i = 0;
  if (isdigit(c)) /* collect integer part */
    while (isdigit(*(++pn) = c = getch()))
      ;
  if (c == '.') /* collect fraction part */
    while (isdigit(*(++pn) = c = getch()))
      ;
  *pn = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}


int main()
{
  char a[BUFSIZE];
  int type = getop(a);
  printf("op type: %d\nop: %s\n", type, a);
  return 0;
}
