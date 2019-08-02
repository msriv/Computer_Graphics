#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>

int main(){
    int x1, x2, y1, y2, yNext, dy, dx, pK, xNext, gd=DETECT, gm;
    printf("Enter Starting point: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter Ending point: ");
    scanf("%d %d", &x2, &y2);
    
    yNext = y1;
    dy = y2-y1;
    dx = x2-x1;
    
    if(dy > dx){
        printf("Please select other points for which difference in y is less than difference in x");
        return -1;
    }else{
        initgraph(&gd,&gm,NULL);
        pK = 2*dy - dx;         // Error: pK = 2*dx - dy;
    
        for(xNext = x1; xNext <= x2; xNext++){
            //putpixel(xNext, yNext, RED);
            printf("%d\t(%d,%d)\n", pK, xNext, yNext);
            if(pK > 0){
                pK = pK + 2*dy - 2*dx;
                yNext++;
            }else{
                pK = pK + 2*dy;
            }
            //delay(100);
            
        }
    }
    getch();
    return 0;
}
