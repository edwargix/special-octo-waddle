#include <stdio.h>

unsigned rightrot(unsigned x, int n)
{
  unsigned last_bits = ~(~0 << n) & x;
  x >>= n;

  unsigned mask = ((unsigned) ~0) >> n;

  unsigned mask_length;
  for (mask_length = 0; mask > 0; ++mask_length) mask >>= 1;

  unsigned first_bits = last_bits << mask_length;

  return x + first_bits;
}

// mask
int main()
{
  unsigned x = 0b111000; // 56
  int n = 4;

  printf("(x, n) = (%u, %d)\n", x, n);

  x = rightrot(x, n);

  printf("(x, n) = (%u, %d)\n", x, n);
  // x = 2147483651 (0b10000000000000000000000000000011 on my machine)

  return 0;
}
