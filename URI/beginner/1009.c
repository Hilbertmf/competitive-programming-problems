#include <stdio.h>
#include <math.h>
 
int main() {
    float wage,amount, total;
    char name[255];
    scanf("%s %f %f", &name, &wage, &amount);
    total = wage + (0.15*amount);
    // you gotta round the floating number for 2 decimal places
    total = roundf(total*100.00f)/100.00f;
    printf("TOTAL = R$ %.2f\n", total);
    return 0;
}