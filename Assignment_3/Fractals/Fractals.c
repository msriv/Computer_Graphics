/*
 * Assignment: Creating a fractal
 * Author: Mihir Srivastava
 * Date: 29/07/2019
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<X11/Xlib.h>
#include<math.h>


// Function to create a triangle
void triangle(int x1, int y1, int x2, int y2, int x3, int y3){
    line(x1+(getmaxx()/2)-100, y1+(getmaxy()/2), x2+(getmaxx()/2)-100, y2+(getmaxy()/2));
    line(x2+(getmaxx()/2)-100, y2+(getmaxy()/2), x3+(getmaxx()/2)-100, y3+(getmaxy()/2));
    line(x3+(getmaxx()/2)-100, y3+(getmaxy()/2), x1+(getmaxx()/2)-100, y1+(getmaxy()/2));
}

// Function that runs recursively to generate a fractal
void fractal(int x1, int y1, int x2, int y2, int x3, int y3, int size){
    if(size > size/10){     // Condition to check the size condition for generating the fractal
        triangle(x1, y1, x2, y2, x3, y3);       // Draws the triangle
        setcolor(COLOR(220, 32, 245));
        fractal((x1+x2)/2, (y1+y2)/2, (x2+x3)/2, (y2+y3)/2, (x3+x1)/2, (y3+y1)/2, size/2);      // Fractal for the center triangle
        setcolor(COLOR(245, 174, 32));
        fractal(x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y3+y1)/2,  size/2);       // Fractal for the left triangle
        setcolor(COLOR(50, 168, 82));
        fractal((x1+x3)/2, (y3+y1)/2,(x2+x3)/2,(y2+y3)/2,x3,y3, size/2);        // Fractal for the right triangle
        setcolor(COLOR(0, 255, 217));
        fractal((x1+x2)/2, (y1+y2)/2,x2,y2,(x2+x3)/2,(y2+y3)/2, size/2);        // Fractal for the top triangle
    }else{
        return;
    }
}



void main(){
    int side, gd = X11, gm=X11_1366x768;    
    
    printf("Enter the side of the triangle: ");
    scanf("%d", &side);
    
    initgraph(&gd, &gm, "");
    fractal(0,0,side/2,side/2, side,0,side);        // Initial Call to the fractal function.
    getch();
}
