#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>

int main(){

    int originX, originY, length;
    
    printf("Enter the origin point: ");
    scanf("%d %d", &originX, &originY);
    printf("Enter the length of each side: ");
    scanf("%d", &length);
    
    int x[4],y[4];
    x[0] = originX;
    y[0] = originY;
    x[1] = originX + length;
    y[1] = originY;
    x[2] = originX;
    y[2] = originY + length;
    x[3] = originX + length;
    y[3] = originY + length;
    
    printf("The four points of the square are: (%d, %d), (%d, %d), (%d, %d), (%d, %d).", x[0],y[0],x[1],y[1],x[2],y[2],x[3],y[3]);
    
    return 0;
}
