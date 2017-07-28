#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
  // char
  printf("signed char min: %d\n", SCHAR_MIN);
  printf("signed char max: %d\n", SCHAR_MAX);
  printf("unsigned char min: %u\n", 0);
  printf("unsigned char max: %u\n", UCHAR_MAX);

  // short (aka short int)
  printf("signed short [int] min: %d\n", SHRT_MIN);
  printf("signed short [int] max: %d\n", SHRT_MAX);
  printf("unsigned short [int] min: %u\n", 0);
  printf("unsigned short [int] max: %u\n", USHRT_MAX);

  // long (aka long int)
  printf("signed long [int] min: %ld\n", LONG_MIN);
  printf("signed long [int] max: %ld\n", LONG_MAX);
  printf("unsigned long [int] min: %lu\n", 0);
  printf("unsigned long [int] max: %lu\n", ULONG_MAX);

  // float
  printf("float min (fixed-point notation): %f\n", FLT_MIN);
  printf("float max (fixed-point notation): %f\n", FLT_MAX);
  printf("float min (exponential notation): %e\n", FLT_MIN);
  printf("float max (exponential notation): %e\n", FLT_MAX);

  // double
  printf("double min (fixed-point notation): %f\n", DBL_MIN);
  printf("double max (fixed-point notation): %f\n", DBL_MAX);
  printf("double min (exponential notation): %e\n", DBL_MIN);
  printf("double max (exponential notation): %e\n", DBL_MAX);

  return 0;
}
