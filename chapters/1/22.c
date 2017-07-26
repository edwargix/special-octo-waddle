/* fold long lines */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 16
#define COLUMN_LENGTH 8

char buf[MAX_LENGTH], last_blank = '\0';
int bufl = 0, linel = 0;


void dispense_buffer(void) {
  for (int i = 0; i < bufl; ++i) {
    putchar(buf[i]);
  }

  bufl = 0;
}


void update(void) {
  if(linel + bufl + (last_blank == '\t' ? (COLUMN_LENGTH - (linel % COLUMN_LENGTH)) : (last_blank == '\0' ? 0 : 1)) <= MAX_LENGTH) {
    if (last_blank != '\0')
      putchar(last_blank);

    linel += bufl + (last_blank == '\t' ? (COLUMN_LENGTH - (linel % COLUMN_LENGTH)) : (last_blank == '\0' ? 0 : 1));

    dispense_buffer();
  } else {

    putchar('\n');

    linel = bufl;

    dispense_buffer();
  }
}


int main(int argc, char** argv)
{
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      update();

      last_blank = c;
    } else {
      if (bufl >= MAX_LENGTH - 1) {
        if (linel > 0)
          putchar('\n');

        dispense_buffer();

        putchar('-');

        putchar('\n');

        last_blank = '\0';

        linel = 0;
      }

      buf[bufl++] = c;
    }
  }


  if (bufl > 0)
    update();


  return 0;
}
