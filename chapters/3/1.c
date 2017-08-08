#include <stdio.h>


int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low+high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }

  if (x == v[mid])
    return mid;

  return -1;
}


int main()
{
  int v[] = { 0, 2, 4, 5, 9};
  printf("%d\n", binsearch(5, v, 6));
  return 0;
}
