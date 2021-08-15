#include <stdio.h>
#include <math.h>
  
 
int main() {
    int dist;
    float fuel, con;
    scanf("%d %f", &dist, &fuel);
    con = dist/fuel;
    // con = roundf(con*1000.000f)/1000.000f
    
    printf("%.3f km/l\n", con);
    return 0;
}