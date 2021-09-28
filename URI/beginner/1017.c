#include <stdio.h>
  
int main() {
    float liters;
    int time, vel, dist;
    scanf("%d %d", &time, &vel);
    dist = time*vel;
    liters = dist / 12.0;
    printf("%.3f\n", liters);
    return 0;
}