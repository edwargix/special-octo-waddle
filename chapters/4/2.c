#include <stdio.h>
#include <ctype.h>

/* atof: convert string s to double The exponent feature only works with integer
 exponents*/
double atof(char s[])
{
  double val, power;
  int i, sign, exp, exp_sign;

  for (i = 0; isspace(s[i]); ++i) /* skip whitespace */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); ++i)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); ++i) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  if (s[i] == 'e' || s[i] == 'E')
    i++;
  exp_sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+')
    i++;
  for (exp = 0; isdigit(s[i]); ++i) {
    exp = 10 * exp + (s[i] - '0');
  }
  int j;
  if (exp_sign > 0)
    for (j = 0; j < exp; ++j)
      power /= 10.0;
  else
    for (j = 0; j < exp; ++j)
      power *= 10.0;


  return sign * val / power;
}


int main()
{
  printf("%g\n", atof("   99.87E3"));
  return 0;
}
