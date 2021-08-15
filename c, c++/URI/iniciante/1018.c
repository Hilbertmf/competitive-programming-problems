#include <stdio.h>
   
int main() {
    int value, n100=0, n50=0, n20=0, n10=0, n5=0, n2=0, n1=0, remainder;
    scanf("%d", &value);
    printf("%d\n", value);
    
    if (value >= 100)
    {
      n100 = value / 100;
      remainder = value - n100*100;
      value = remainder;
    }
    if (value >= 50)
    {
      n50 = value / 50;
      remainder = value - n50*50;
      value = remainder;
    }
    if (value >= 20)
    {
      n20 = value / 20;
      remainder = value - n20*20;
      value = remainder;
    }
    if (value >= 10)
    {
      n10 = value / 10;
      remainder = value - n10*10;
      value = remainder;
    }
    if (value >= 5)
    {
      n5 = value / 5;
      remainder = value - n5*5;
      value = remainder;
    }
    if (value >= 2)
    {
      n2 = value / 2;
      remainder = value - n2*2;
      value = remainder;
    }
    if (value >= 1)
    {
      n1 = value;
      remainder = value - n1;
      value = remainder;
    }
    printf("%d nota(s) de R$ 100,00\n", n100);
    printf("%d nota(s) de R$ 50,00\n", n50);
    printf("%d nota(s) de R$ 20,00\n", n20);
    printf("%d nota(s) de R$ 10,00\n", n10);
    printf("%d nota(s) de R$ 5,00\n", n5);
    printf("%d nota(s) de R$ 2,00\n", n2);
    printf("%d nota(s) de R$ 1,00\n", n1);
    return 0;
}