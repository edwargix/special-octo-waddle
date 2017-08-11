#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getfloat(float *pn)
{
  int c, sign;

  while (isspace(c = getch())) /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); /* it's not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  if (!isdigit(c)) {
    ungetch(c);
    return 0;
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  if (c == '.') {
    int div;
    for (c = getch(), div = 1; isdigit(c); c = getch()) {
      *pn = 10 * *pn + (c - '0');
      div *= 10;
    }
    *pn /= div;
  }

  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int buf = EOF;
int getch(void)
{
  return (buf != EOF) ? buf : getchar();
}


void ungetch(int i)
{
  buf = i;
}


int main()
{
  float f;
  getfloat(&f);
  printf("%g\n", f);
  return 0;
}
