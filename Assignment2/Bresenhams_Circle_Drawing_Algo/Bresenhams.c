#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

int main(){
    
    int x, y, r, xNext, yNext, p, gd=DETECT, gm;
    
    printf("Enter the center of the circle: ");
    scanf("%d %d", &x, &y);
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);
    
    p = 3 - 2*r;
    
   
    
    
    initgraph(&gd, &gm, NULL);
    
    yNext = r;
    
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    
    for(xNext = 0; xNext <= yNext; xNext++){
        putpixel(xNext+x, yNext+y, RED);
        //printf("%d %d\n", xNext+(getmaxx()/2), yNext+(getmaxy()/2));
        if(p < 0){
            p+=(4*xNext+6);
        }else{
            yNext--;
            p+=(4*xNext-4*yNext+10);
        }
        
    }
    
    getch();
    return 0;
}
