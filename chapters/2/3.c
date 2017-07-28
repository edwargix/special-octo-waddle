#include <stdbool.h>
#include <stdio.h>


bool is_hex_char(char c) {
  return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
    (c >= 'A' && c <= 'F');
}


int get_hex(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  else if (c >= 'a' && c <= 'f')
    return c - 'a' + 10;
  else if (c >= 'A' && c <= 'F')
    return c - 'A' + 10;

  // if `c` is not a valid hex char
  return 0;
}


int htoi(char s[]) {
  int i, n;
  char c;
  bool pref;

  i = 0;
  pref = false;
  while ((c = s[i]) != '\0')
    if (++i > 1) {
      if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        pref = true;
      break;
    }

  if (!pref) i = 0;

  n = 0;
  for (; is_hex_char(s[i]); ++i)
    {
      printf("hex: %d\n", get_hex(s[i]));
      n = 0x10 * n + get_hex(s[i]);
    }

  return n;
}


int main(int argc, char** argv)
{
  printf("%d\n", htoi(argc > 1 ? argv[1] : "0xff"));
  return 0;
}
