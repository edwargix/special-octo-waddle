#include <stdio.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
  int leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

  if (month < 1 || month > 12) {
    printf("error: day_of_year: month must lie in the range [1, 12]\n");
    return -1;
  } if (day < 1 || day > daytab[leap][month]) {
    printf("error: day_of_year: day must lie in the range [%d, %d] for month %d\n", 1, daytab[leap][month], month);
    return -1;
  }

  int i;
  for (i = 1; i < month; i++)
    day += *(daytab[leap] + i);
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
#define YEARLENGTH 365
#define LYEARLENGTH 366
  int leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

  if (yearday < 1 || yearday > (leap ? LYEARLENGTH : YEARLENGTH))
    printf("error: month_day: yearday must lie in the range [%d, %d] for the year %d\n", 1, (leap ? LYEARLENGTH : YEARLENGTH), year);

  int i;
  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= *(daytab[leap] + i);
  *pmonth = i;
  *pday = yearday;
}

int main()
{
  printf("day_of_year(1900, 12, 30): %d\n", day_of_year(1900, 12, 30));
  int month[2], day[2];
  month_day(2017, 365, month, day);
  printf("month_day(2017, 365): month: %d, day: %d\n", *month, *day);
  return 0;
}
