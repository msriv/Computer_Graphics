#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<X11/Xlib.h>
#include<math.h>

void drawEllipse(int xc, int yc, int a, int b, int stangle, int endangle, float alpha, int color) 
{ 
    float t = 3.14 / 180; 
    alpha = 360 - alpha; 
    setcolor(color); 
    int theta; 
  
    // Filling each pixel corresponding 
    // to every angle from 0 to 360 
    for (int i = stangle; i < endangle; i += 1) { 
        theta = i; 
        int x = a * cos(t * theta) * cos(t * alpha) 
                + b * sin(t * theta) * sin(t * alpha); 
  
        int y = b * sin(t * theta) * cos(t * alpha) 
                - a * cos(t * theta) * sin(t * alpha); 
  
        putpixel(xc + x, yc - y, color); 
    } 
} 

void main(){
    int gd=X11, gm=X11_1366x768;
    initgraph(&gd, &gm, "");
    drawEllipse(getmaxx()/2, getmaxy()/2, 20,10, 180, 360, 45, 4);
    getch();
    closegraph();
}
