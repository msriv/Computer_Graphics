#include<stdlib.h>
#include<stdio.h>

int main(){
    int x1, x2, y1, y2, dy, dx, c;
    printf("Enter starting points: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter ending points: ");
    scanf("%d %d", &x2, &y2);
    
    dy = y2 - y1;
    dx = x2 - x1;
    c = y1 - (dy/dx)*x1;
    
    printf("%dx-(%dy)+%d=0", dy, dx, c);
    
    return 0;
}
