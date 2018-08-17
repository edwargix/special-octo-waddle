#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
  int allocatedc = 10, linec = 0, cur_i = 0;
  int i, j, ret;
  size_t len = 0;

  /* Determine how many lines should be kept track of */
  if (argc > 1 && *argv[1] == '-')
    allocatedc = atoi(argv[1] + 1);

  char *lines[allocatedc];
  for (i = 0; i < allocatedc; ++i)
    lines[i] = NULL;

  while (1) {
    printf("in: ");
    ret = getline(&lines[cur_i], &len, stdin);
    printf("\"%s\"", lines[cur_i]);
    if (linec < allocatedc)
      ++linec;
    if (++cur_i >= allocatedc)
      cur_i = 0;
    if (ret == EOF)
      break;
    len = 0;
  }

  printf("heyo");

  for (i=0, j=cur_i; i < linec; ++i) {
    fputs(lines[j], stdout);

    if (++j >= linec)
      j = 0;
  }

  for (j = 0; j < linec; ++j)
    free(lines[j]);
}
