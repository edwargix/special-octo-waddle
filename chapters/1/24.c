#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_ORPHANS 2000

#define OUT 0
#define IN_SHORT 1
#define IN_LONG 2
#define IN_STRING 3
#define IN_CHAR 4

int main()
{
  int c, p, i;

  bool in_string = false, in_char = false;
  int status = OUT;

  int orphans_count = 0;
  char orphans[MAX_ORPHANS];

#define wrapper_count 3
  char openers[] = {'(', '[', '{'};
  char closers[] = {')', ']', '}'};

  while ((c = getchar()) != EOF) {
    if (status == IN_SHORT) {
      if (c == '\n')
        status = OUT;
    } else if (status == IN_LONG) {
      if (c == '/' && p == '*') {
        c = '\0';
        status = OUT;
      }
    } else if (status == IN_STRING) {
      if (c == '"' && p != '\\')
        status = OUT;
    } else if (status == IN_CHAR) {
      if (c == '\'' && p != '\\')
        status = OUT;
    } else {

      if (c == '/') {
        if (p == '/')
        status = IN_SHORT;
      } else if (c == '*') {
        if (p == '/')
          status = IN_LONG;
      } else if (c == '"') {
        if (p != '\\')
          status = IN_STRING;
      } else if (c == '\'') {
        if (p != '\\')
          status = IN_CHAR;
      } else {

        bool found = false;
        for (i = 0; i < wrapper_count; ++i) {
          if (c == closers[i]) {
            found = true;
            if (openers[i] == orphans[orphans_count - 1]) {
              orphans_count--;
            } else {
              printf("Unmatched %c\n", c);
              exit(0);
            }
          }
        }

        if (!found)
          for (i = 0; i < wrapper_count; ++i) {
            if (c == openers[i]) {
              orphans[orphans_count++] = c;
              break;
            }
          }

      }

    }

    p = c;
  }

  if (orphans_count > 0) {
    printf("Unmatched %c\n", orphans[orphans_count - 1]);
  }

  return 0;
}
