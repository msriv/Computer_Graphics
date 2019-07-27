#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

void dda(int x1, int y1, int x2, int y2, int color){
    float xn, yn, xinc, yinc, dy, dx;
	int gd=DETECT, gm, p, finalX, finalY;
    dy = y2-y1;
	dx = x2-x1;
	p = (abs(dy) > abs(dx)) ? abs(dy) : abs(dx);
	xn = dx / p;
	yn = dy / p;
	for(int i = 0; i<=p; i++){
        putpixel(finalX, finalY, color);
		if(x1 < 0){
			finalX = ((x1*10)/10)-0.5;
		}else{
			finalX = ((x1*10)/10)+0.5;
		}
		if(y1 < 0){
			finalY = ((y1*10)/10)-0.5;
		}else{
			finalY = ((y1*10)/10)+0.5;
		}
		x1 += xn;
		y1+=yn;
	}
}


void outerCircle(int x, int y, int r){
    int xNext, yNext, p;
    
    p = 3 - 2*r;
    
    yNext = r;
    
    //putpixel(x, y, RED);
    
    for(xNext = 0; xNext <= yNext; xNext++){
        putpixel(xNext+x, yNext+y, YELLOW);
        putpixel(-xNext+x, yNext+y, YELLOW);
        putpixel(xNext+x, -yNext+y, YELLOW);
        putpixel(-xNext+x, -yNext+y, YELLOW);
        putpixel(-yNext+x, xNext+y, YELLOW);
        putpixel(yNext+x, xNext+y, YELLOW);
        putpixel(yNext+x, -xNext+y, YELLOW);
        putpixel(-yNext+x, -xNext+y, YELLOW);
        if(p < 0){
            p+=(4*xNext+6);
        }else{
            yNext--;
            p+=(4*xNext-4*yNext+10);
        }
    }
}

void mouth(int x, int y, int r){
    int xNext, yNext, p;
    
    p = 3 - 2*r;
    
    yNext = r;
    
    putpixel(x, y, RED);
    
    for(xNext = 0; xNext <= yNext; xNext++){
        putpixel(xNext+x, yNext+y, RED);
        putpixel(-xNext+x, yNext+y, RED);
        if(p < 0){
            p+=(4*xNext+6);
        }else{
            yNext--;
            p+=(4*xNext-4*yNext+10);
        }
    }
    
}

void heartEye(int x, int y){
    dda(x,y,x+40,y+40,4);
    //dda(x,y, x+40, y+40, 4);
}

void heartEyes(int x, int y, int r){
    heartEye(140, 140);
    /*putpixel((getmaxx()/2)-(r/2), getmaxy()/2, RED);
    putpixel((getmaxx()/2)+(r/2), getmaxy()/2, RED);
    putpixel((getmaxx()/2)-(r/2)+)*/
}

int main(){
    
    int x, y, gd=DETECT, gm;

    
    
    initgraph(&gd, &gm, NULL);
    int r = 100;
    
    
    //line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    //line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    
    outerCircle(getmaxx()/2, getmaxy()/2, r);
    mouth(getmaxx()/2, getmaxy()/2, 70);
    heartEyes(100, 100, r);
    
    getch();
    return 0;
}
