#include <stdio.h>
#include <stdlib.h>
 
int max(int n1, int n2) {
    return (n1 + n2 + abs(n1-n2))/2;
} 
 
int main() {
    int n1,n2,n3,res;
    scanf("%d %d %d", &n1, &n2, &n3);
    
    res = max(max(n1,n2),n3);
    printf("%d eh o maior\n", res);
    return 0;
}