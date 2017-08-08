#include <stdio.h>


void escape(char s[], char t[])
{
  // this assumes t is an appropriate size
  int c, i = 0, j = 0;
  while ((c = s[i]) != '\0') {
    // not the best way to do this, but exercise wants us to use a switch
    switch (c) {
    case '\n': {
      t[j++] = '\\';
      t[j++] = 'n';
      break;
    }
    case '\t': {
      t[j++] = '\\';
      t[j++] = 't';
      break;
    }
    default:
      t[j++] = c;
      break;
    }

    i++;
  }

  t[j] = '\0';
}


void unescape(char s[], char t[])
{
  // this assumes t is an appropriate size
  int c, i = 0, j = 0;
  while ((c = s[i]) != '\0') {
    // not the best way to do this, but exercise wants us to use a switch
    switch (c) {
    case '\\': {
      switch ((c = s[++i])) {
      case 'n': {
        t[j++] = '\n';
        break;
      }
      case 't': {
        t[j++] = '\t';
        break;
      }
      default:
        // only \t and \n for now
        t[j++] = ' ';
        break;
      }
      break;
    }
    default:
      t[j++] = c;
      break;
    }

    i++;
  }

  t[j] = '\0';
}


int main()
{
  char s[] = "he\tllo\n";
  char t[10];
  escape(s, t);
  printf("%s\n", t);

  char x[8];
  unescape(t, x);
  printf("%s\n", x);

  return 0;
}
