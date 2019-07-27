#include<stdlib.h>
#include<stdio.h>
#include "/usr/include/graphics.h"

void bf4(int x, int y, int cc, int nc){
    if(getpixel(x,y) != cc && getpixel(x,y) != nc){        // Boundary color must not match the pixel color.
        putpixel(x,y,nc);
        bf4(x, y+1, cc, nc);
        bf4(x-1, y, cc, nc);
        bf4(x, y-1, cc, nc);
        bf4(x+1, y, cc, nc);
    }
    return;
}


void bf8(int x, int y, int cc, int nc){
    if(getpixel(x,y) != cc && getpixel(x,y) != nc){        // Boundary color must not match the pixel color.
        putpixel(x,y,nc);
        bf8(x, y+1, cc, nc);
        bf8(x-1, y, cc, nc);
        bf8(x, y-1, cc, nc);
        bf8(x+1, y, cc, nc);
        bf8(x-1, y+1, cc, nc);
        bf8(x-1, y-1, cc, nc);
        bf8(x+1, y-1, cc, nc);
        bf8(x+1, y+1, cc, nc);
    }
    return;
}


void main(){
    int gd=DETECT, gm=X11_640x480, x, y;
    initgraph(&gd, &gm, "");
    int cc = 15;
    rectangle(100,100,250,250);
    bf8(120, 120, cc, 5);
    printf("Boundary Fill 8 Neighbouring Pixels");
    //lineto(getmaxy()/2, getmaxx());
    getmouseclick(WM_LBUTTONDOWN, x, y);
    printf("%d %d", x, y);
    getch();
    closegraph();
}
