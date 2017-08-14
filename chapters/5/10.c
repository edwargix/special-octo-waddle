#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#define MAXSTACK 100
double stack[MAXSTACK];
int stackp = 0;


double pop(void)
{
  if (stackp < 1) {
    printf("error: pop: stack empy\n");
    return 0;
  }
  return stack[--stackp];
}


void push(double d)
{
  stack[stackp++] = d;
}

int isnumber(char *s)
{
  for ( ; *s != '\0'; ++s)
    if (!isdigit(*s)) {
      printf("%c\n", *s);
      return 0;
    }

  return 1;
}

int main(int argc, char *argv[])
{
  while (--argc > 0) {
    double o2;
    ++argv;

    if (!strcmp(*argv, "+"))
      push(pop() + pop());
    else if (!strcmp(*argv, "-")) {
      o2 = pop();
      push(pop() - o2);
    } else if (!strcmp(*argv, "*"))
      push(pop() * pop());
    else if (!strcmp(*argv, "/")) {
      o2 = pop();
      if (o2 == 0)
        printf("error: main: divide by zero\n");
      else
        push(pop() / o2);
    } else if (isnumber(*argv))
      push(atof(*argv));
    else
      printf("error: main: unknown command: %s\n", *argv);
  }

  printf("%g\n", stack[stackp - 1]);

  return 0;
}
