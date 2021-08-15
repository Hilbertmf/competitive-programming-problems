#include <stdio.h>
#include <stdlib.h>


int main() {
 
    double n1,n2,n3;
    scanf("%lf", &n1);
    scanf("%lf", &n2);
    scanf("%lf", &n3);
 
    double ans = (n1*2.0 + n2*3.0 + n3*5.0) / 10.0;
    printf("MEDIA = %.1lf\n",ans);
    return 0;
}