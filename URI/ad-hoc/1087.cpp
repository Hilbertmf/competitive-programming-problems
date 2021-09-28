#include <iostream>

 
using namespace std;
 
int main() {
 
    int y1, y2, x1, x2;
    
    while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2) && x1 != 0)
    {
        //same position
        if(x1 == x2 && y1 == y2)
            printf("0\n");
        //same column or row
        else if(x1 == x2 || y1 == y2)
            printf("1\n");
        //same diagonal
        else if(abs(x1-x2) == abs(y1-y2))
            printf("1\n");
        else
            printf("2\n");
    }
 
    return 0;
}