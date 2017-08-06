#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
  unsigned x_mask = ~(~0 << n) << (p - n + 1);

  unsigned inverted_bits = ~(x & x_mask) & x_mask;

  unsigned other_bits = x & ~x_mask;

  return inverted_bits + other_bits;
}

// test
int main()
{
  unsigned x = 0b10101010; // 170
  int p = 5; // position of 3rd one
  int n = 3; // invert three bits

  printf("(x, p, n) = (%u, %d, %d)\n", x, p, n);

  x = invert(x, p, n);
  // x should be 0b10010010 (146)

  printf("(x, p, n) = (%u, %d, %d)\n", x, p, n);

  return 0;
}
