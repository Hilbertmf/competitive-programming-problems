#include <stdio.h>
  
 
int main() {
    int timeInSeconds, hours=0, minutes=0, seconds=0;
    scanf("%d", &timeInSeconds);
    
    if (timeInSeconds >= 3600)
    {
      hours = timeInSeconds / 3600;
      timeInSeconds -= hours*3600;
    }
    if (timeInSeconds >= 60)
    {
      minutes = timeInSeconds / 60;
      timeInSeconds -= minutes*60;
    }
    if (timeInSeconds > 0)
    {
      seconds = timeInSeconds;
    }
    
    
    printf("%d:%d:%d\n", hours, minutes, seconds);
    return 0;
}