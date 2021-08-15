#include <stdio.h>
#include <stdlib.h>

int main()
{
	int age, yrs=0,months=0, days=0;
  scanf("%d", &age);

  if (age >= 365)
  {
    yrs = age / 365;
    age -= yrs * 365;
  }
  if (age >= 30)
  {
    months = age / 30;
    age -= months * 30;
  }
  if (age > 0)
  {
    days = age;
  }
  
	printf("%d ano(s)\n", yrs);
  printf("%d mes(es)\n", months);
  printf("%d dia(s)\n", days);
	return 0;
}
