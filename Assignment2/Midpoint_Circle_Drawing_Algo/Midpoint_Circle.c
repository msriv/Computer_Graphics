#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>

void myCircle(int x, int y, int r){
    int xNext, yNext, p;
    p = (5/4) - r;
    yNext = r;
    putpixel(x,y,RED);
    
    for(xNext = 0; xNext <= yNext; xNext++){
        putpixel(xNext+x, yNext+y, RED);
        putpixel(-xNext+x, yNext+y, RED);
        putpixel(xNext+x, -yNext+y, RED);
        putpixel(-xNext+x, -yNext+y, RED);
        putpixel(-yNext+x, xNext+y, RED);
        putpixel(yNext+x, xNext+y, RED);
        putpixel(yNext+x, -xNext+y, RED);
        putpixel(-yNext+x, -xNext+y, RED);
        if(p >= 0){
            p+=(2*xNext-2*yNext+5);
            yNext--;
        }else{
            p+=(2*xNext+3);
        }
    }
}

void main(){
    int x, y, r1, r2, gd=DETECT, gm;
    printf("Enter the radius of the circle 1: ");
    scanf("%d", &r1);
    printf("Enter the radius of the circle 2: ");
    scanf("%d", &r2);
    printf("Enter the coordinates for center: ");
    scanf("%d %d", &x, &y);
    
    initgraph(&gd, &gm, NULL);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    
    myCircle(getmaxx()/2, getmaxy()/2, r1);
    myCircle(getmaxx()/2, getmaxy()/2, r2);
    myCircle(x,y,r1);
    myCircle(x,y,r2);
    
    
    getch();
}
