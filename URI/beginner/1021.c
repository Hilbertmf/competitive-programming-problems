#include <stdio.h>
#include <stdlib.h>

int main()
{
	int bill100=0, bill50=0, bill20=0, bill10=0, bill5=0, bill2=0;
  int coin100=0, coin50=0, coin25=0, coin10=0, coin5=0;
  float coin1=0;
  double value;
  scanf("%lf", &value);

  if (value >= 100)
  {
    bill100 = value/100;
    value -= bill100*100;
  }
  if (value >= 50)
  {
    bill50 = value/50;
    value -= bill50*50;
  }
  if (value >= 20)
  {
    bill20 = value/20;
    value -= bill20*20;
  }
  if (value >= 10)
  {
    bill10 = value/10;
    value -= bill10*10;
  }
  if (value >= 5)
  {
    bill5 = value/5;
    value -= bill5*5;
  }
  if (value >= 2)
  {
    bill2 = value/2;
    value -= bill2*2;
  }
  if (value >= 1)
  {
    coin100 = abs(value);
    value -= coin100*1;
  }
  if (value >= 0.5)
  {
    coin50 = value / 0.5;
    value -= coin50*0.5;
  }
  if (value >= 0.25)
  {
    coin25 = value / 0.25;
    value -= coin25*0.25;
  }
  if (value >= 0.1)
  {
    coin10 = value / 0.1;
    value -= coin10*0.1;
  }
  if (value >= 0.05)
  {
    coin5 = value / 0.05;
    value -= coin5*0.05;
  }
  if (value)
  {
    coin1 = value / 0.01;
    value -= coin1*0.01;
  }	
  printf("NOTAS:\n");
  printf("%d nota(s) de R$ 100.00\n", bill100);
  printf("%d nota(s) de R$ 50.00\n", bill50);
  printf("%d nota(s) de R$ 20.00\n", bill20);
  printf("%d nota(s) de R$ 10.00\n", bill10);
  printf("%d nota(s) de R$ 5.00\n", bill5);
  printf("%d nota(s) de R$ 2.00\n", bill2);
  printf("MOEDAS:\n");
  printf("%d moeda(s) de R$ 1.00\n", coin100);
  printf("%d moeda(s) de R$ 0.50\n", coin50);
  printf("%d moeda(s) de R$ 0.25\n", coin25);
  printf("%d moeda(s) de R$ 0.10\n", coin10);
  printf("%d moeda(s) de R$ 0.05\n", coin5);
  printf("%.0f moeda(s) de R$ 0.01\n", coin1);
  
	return 0;
}
