#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h> /* for sin(), exp(), pow() */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
double last(void);
void clear(void);
void swap(void);

/* reverse Polish calculator */
int main()
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '%': /* casts all doubles to integers */
      op2 = pop();
      if (op2 != 0.0)
        push((int)pop() % (int)op2);
      else
        printf("error: zero divisor\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    case 'p': /* p: print top element of stack */
      printf("\t%.8g\n", last());
      break;
    case 'c': /* c: clear stack */
      clear();
      break;
    case 't':
      swap();
      break;
    case 's': /* s: sine */
      push(sin(pop()));
      break;
    case 'e': /* e: exp */
      push(exp(pop()));
      break;
    case '^': /* ^: pow */
      op2 = pop();
      push(pow(pop(), op2));
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}


#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* last: return top value from stack */
double last(void)
{
  if (sp > 0)
    return val[sp - 1];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* clear: wipe stack */
void clear(void)
{
  sp = 0;
}

/* swap: swap top two elements */
void swap(void)
{
  double temp = val[sp - 1];
  val[sp - 1] = val[sp - 2];
  val[sp - 2] = temp;
}


#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-')
    return c; /* not a number */
  i = 0;
  if (c == '-' && !isdigit(s[++i] = c = getch())) {
    s[i] = '\0';
    return '-';
  }
  if (isdigit(c)) /* collect integer parts */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}


#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;

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