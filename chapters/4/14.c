#include <stdio.h>

#define swap(t,x,y) do{t z=x; x=y; y=z;}while(0)

int main()
{
  int x = 5;
  int y = 3;
  swap(int, x, y);
  printf("x: %d, y: %d\n", x, y);
  return 0;
}
