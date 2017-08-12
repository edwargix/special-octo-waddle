#include <string.h>

#define MAXLEN 1000 /* max length of any input line */
int getline(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *mem[])
{
  int len, nlines;
  char line[MAXLEN];

  nlines = 0;
  while ((len = getline(line, MAXLEN)) > 0)
    if (nlines >= maxlines)
      return -1;
    else {
      line[len - 1] = '\0'; /* delete newline */
      strcpy(mem[nlines], line);
      lineptr[nlines] = mem[nlines];
      nlines++;
    }
  return nlines;
}
