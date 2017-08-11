#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h> /* for sin(), exp(), pow() */
#include <stdbool.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
double last(void);
void clear(void);
void swap(void);

int save_var(char, double);
int get_var(char, double*);

/* reverse Polish calculator */
int main()
{
  int type;
  double op2, var;
  char s[MAXOP];
  bool saving = false;

  while ((type = getop(s)) != EOF) {
    if (saving) {
      save_var(type, last());
      saving = false;
      continue;
    }

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
    case '=': /* =: save top of stack in variable that follows */
      saving = true;
      break;
    default:
      if (get_var(type, &var))
        push(var);
      else
        printf("error: unknown var/command %s\n", s);
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
  if (sp < MAXVAL) {
    val[sp++] = f;
    save_var('l', f); /* variable holding last value */
  } else
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

/* storage for variables */
double vars[26];

/* save_var: set var `c' to `d'; return 1 on success, 0 on failure */
int save_var(char c, double d)
{
  if (islower(c)) {
    vars[c - 'a'] = d;
    return 1;
  }

  printf("error: save_var: invalid variable name\n");
  return 0;
}

/* get_var: put value of var `c' in `d'; return 1 on success, 0 on failure */
int get_var(char c, double *d)
{
  if (islower(c)) {
    *d = vars[c - 'a'];
    return 1;
  }

  printf("error: getvar: invalid variable name\n");
  return 0;
}


#include <ctype.h>
#include <string.h>

int getch(void);
int m_getline(void);

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
  return NUMBER;
}

#define LINE_LIMIT 100
char line[LINE_LIMIT];
unsigned long int str_length = 0;
unsigned long int line_index = 0;

int getch(void) /* get a character */
{
  if (line_index >= str_length || line[line_index] == '\0') {
    m_getline();
    line_index = 0;
  }
  return line[line_index++];
}

int m_getline(void)
{
  int c, i, lim = LINE_LIMIT;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    line[i++] = c;
  if (c == '\n')
    line[i++] = c;
  line[i++] = '\0';
  str_length = i;
  return i;
}
