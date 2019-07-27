#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

void myCircle(int x, int y, int r){
    int xNext, yNext, p;
    
    p = 3 - 2*r;
    
    yNext = r;
    
    putpixel(x, y, RED);
    
    for(xNext = x; xNext <= yNext+y; xNext++){
        putpixel(xNext, yNext, RED);
        /*putpixel(-xNext+x, yNext+y, RED);
        putpixel(xNext+x, -yNext+y, RED);
        putpixel(-xNext+x, -yNext+y, RED);
        putpixel(-yNext+x, xNext+y, RED);
        putpixel(yNext+x, xNext+y, RED);
        putpixel(yNext+x, -xNext+y, RED);
        putpixel(-yNext+x, -xNext+y, RED);*/
        if(p < 0){
            p+=(4*xNext+6);
        }else{
            p+=(4*xNext-4*yNext+10);
            yNext--;
        }
    }
}

int main(){
    
    int x, y, r1, r2, gd=DETECT, gm;
    
    //printf("Enter the center of the circle: ");
    //scanf("%d %d", &x, &y);
    /*printf("Enter the radius of the first circle: ");
    scanf("%d", &r1);
    printf("Enter the radius of the second circle: ");
    scanf("%d", &r2);
     
    
    
    initgraph(&gd, &gm, NULL);
    
    
    
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    
    myCircle(x, y, r1);
    myCircle(x, y, r2);
    myCircle(getmaxx()/2, getmaxy()/2, r1);
    myCircle(getmaxx()/2, getmaxy()/2, r2);
    
    
    getch();
    return 0;
}
