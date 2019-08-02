#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

void main(){
    int gd = X11, gm=X11_1366x768, tx, ty, x1, x2, y1, y2;
    char c;
    initgraph(&gd, &gm, "");
    x1 = 20;
    y1 = 20;
    x2 = 30;
    y2 = 30;
    tx=10;
    ty=10;
    outtextxy(0,0,"Use up, down, left, right arrow key to manuever");
    outtextxy(0,10,"Press X to escape");
    rectangle(x1, y1, x2, y2);
    do{
        c = (char) getch();
        switch(c){
                case KEY_UP:{
                    setcolor(BLACK);
                    y1 = y1-(ty-10);
                    y2 = y2-(ty-10);
                    rectangle(x1, y1, x2, y2);
                    setcolor(WHITE);
                    y1 = y1-ty;
                    y2 = y2-ty;
                    rectangle(x1, y1-ty, x2, y2-ty);
                    ty+=10;
                }break;
                case KEY_DOWN:{
                    setcolor(BLACK);
                    y1 = y1+(ty-10);
                    y2 = y2+(ty-10);
                    rectangle(x1, y1, x2, y2);
                    setcolor(WHITE);
                    y1 = y1+ty;
                    y2 = y2+ty;
                    rectangle(x1, y1, x2, y2);
                    ty+=10;
                }
                
        }
    }while((c != 'x') && (c != 'X'));
    
}
