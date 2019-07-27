#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>

void ff4(int x, int y, int oc, int nc){
    if(getpixel(x,y) == oc){
        putpixel(x,y,nc);
        ff4(x, y+1, oc, nc);
        ff4(x-1, y, oc, nc);
        ff4(x, y-1, oc, nc);
        ff4(x+1, y, oc, nc);
    }
    return;
}

void ff8(int x, int y, int oc, int nc){
    if(getpixel(x,y) == oc){
        putpixel(x,y,nc);
        ff8(x, y+1, oc, nc);
        ff8(x-1, y, oc, nc);
        ff8(x, y-1, oc, nc);
        ff8(x+1, y, oc, nc);
        ff8(x-1, y+1, oc, nc);
        ff8(x-1, y-1, oc, nc);
        ff8(x+1, y-1, oc, nc);
        ff8(x+1, y+1, oc, nc);
    }
    return;
}

void main(){
    int gd=DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int oc = getpixel(120,120);
    rectangle(100,100,200,200);
    ff8(120, 120, oc, 15);
    printf("Flood Fill 8 Neighbouring Pixels");
    getch();
    closegraph();
}
