#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  unsigned x_mask = ~(~(~0 << n) << (p - n + 1)); // regex: 1*0{n}1*{p - n + 1}
  unsigned x_bits = x & x_mask;

  unsigned y_mask = ~(~0 << n); // regex: 0*1{n}
  unsigned y_bits = y & y_mask;

  y_bits = y_bits << (p - n + 1);

  return x_bits + y_bits;
}

// test
int main()
{
  unsigned x = 0b10101010; // 170
  int p = 5; // position of 3rd one
  int n = 3; // replace 3 bits
  unsigned y = 0b010; // 2
  printf("(x, p, n, y) = (%u, %d, %d, %u)\n", x, p, n, y);

  x = setbits(x, p, n, y);
  // x should be 0b10010010 (146)

  printf("(x, p, n, y) = (%u, %d, %d, %u)\n", x, p, n, y);

  return 0;
}
