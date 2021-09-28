#include <stdio.h>
   
int main() {
    double radius, pi;
    double vol;
    pi=3.14159;
    scanf("%lf", &radius);
    vol = (4/3.0)*pi*(radius*radius*radius);
    printf("VOLUME = %.3lf\n", vol);
    return 0;
}