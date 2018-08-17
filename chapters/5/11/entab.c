#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  char c;
  int tab_stops[argc + 1];
  int *next_tab;

  { // set tab stops from arguments
    int *p;
    for (p = tab_stops; --argc > 0; )
      *p++ = atoi(*++argv); // ++argv to skip program name
    *p = 0;
  }

  int spacec, pos;

  /* Main loop */
  for (spacec = 0, pos = 0, next_tab = tab_stops;
       (c = getchar()) != EOF; ) {

    if (c == ' ') {
      ++spacec;
      if (++pos == *next_tab) {
	putchar('\t');
	spacec = 0;
	/* pos = 0; */
	if (*next_tab != 0)
	  next_tab++;
      }
    }
    else if (c == '\t') {
      /* putchar(c); */
      /* pos = 0; */
      if (*next_tab != 0)
	next_tab++;
      /* spacec = 0; */
      /* spacec = *next_tab - pos; */
      pos = *next_tab;
    }
    else {
      for ( ; spacec > 0; --spacec)
	putchar(' ');

      if (c == '\n') {
	pos = 0;
	next_tab = tab_stops;
      }
      else
	if (*next_tab != 0 && ++pos >= *next_tab)
	  /* pos = 0; */
	  next_tab++;

      putchar(c);
    }

  }

  return 0;
}
