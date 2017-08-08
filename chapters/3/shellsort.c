#include <stdio.h>

void shellsort(int v[], int n)
{
  int gap, i, j, temp;

  for (gap = n/2; gap > 0; gap /= 2) // gap = {3}
    for (i = gap; i < n; i++) // i = {(3),(4),(5),(6)}
      for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) { // j = {(0),(1),(2),(3,0)}
        temp = v[j];
        v[j] = v[j+gap];
        v[j+gap] = temp;
      }
}


int main()
{
  int i, x[] = { 8, 6, 7, 5, 3, 0, 9 };

  shellsort(x, 7);

  for (i = 0; i < 7; ++i) {
    printf("%d ", x[i]);
  }

  printf("\n");

  return 0;
}
