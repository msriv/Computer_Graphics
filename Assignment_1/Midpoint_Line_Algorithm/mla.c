#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

int main(){
    int x1, x2, y1, y2, yNext, xNext, dy, dx, gd=DETECT, gm, q, decisionFactor;
    float mX, mY;
    printf("Enter the starting point: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the ending point: ");
    scanf("%d %d", &x2, &y2);
    
    dy = y2 - y1;
    dx = x2 - x1;
     if(dy > dx){
        printf("Please select other points for which difference in y is less than difference in x");
        return -1;
    }else{
        //initgraph(&gd,&gm,NULL);
    yNext = y1;
    
    q = dy - dx;
    
    decisionFactor = dy-(dx/2);
    printf("decisionFactor\t\txNext\t\tyNext\t\t(Mx,My)\n");
    for(xNext=x1;xNext<=x2;xNext++){
        
        mX = xNext+1;
        mY = yNext+0.5;
        printf("%d\t\t%d\t\t%d\t\t(%f, %f)\n", decisionFactor, xNext, yNext, mX, mY);
        //putpixel(xNext, yNext, RED);
        if(decisionFactor > 0){
            yNext++;
            decisionFactor+=q;
        }else{
            decisionFactor+=dy;
        }
    }
    }
    
    //getch();
    return 0;
    
}
