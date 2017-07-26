#include <stdio.h>
#include <stdbool.h>

#define OUT 0
#define IN_SHORT 1
#define IN_LONG 2

int main()
{
  int c, p;
  bool in_string = false;
  int status = OUT;

  while ((c = getchar()) != EOF) {
    if (status == IN_SHORT) {
      if (c == '\n') {
        status = OUT;
      }
    } else if (status == IN_LONG) {
      if (c == '/' && p == '*') {
        c = '\0';
        status = OUT;
      }
    } else {

      if (c == '/') {
        if (in_string) {
          putchar('/');
        } else if (p == '/') {
          status = IN_SHORT;
        }
      } else if (c == '*') {
        if (in_string) {
          putchar('*');
        } else if (p == '/') {
          status = IN_LONG;
        } else {
          putchar('*');
        }
      } else {
        if (p == '/' && !in_string) {
          putchar('/');
        }

        if (c == '"') {
          in_string = in_string ? (p == '\\' ? true : false) : true;
        }

        putchar(c);
      }

    }

    p = c;
  }

  return 0;
}
