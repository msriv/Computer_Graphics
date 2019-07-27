#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<X11/Xlib.h>
int main(){
	XInitThreads();
	int screenx, screeny;
	int gd=DETECT, gm;
	float xn, yn, xinc, yinc, x1, x2, y1, y2, dy, dx, c, d;
	int p, finalX, finalY, a, b;
	printf("Enter the starting point:");
	scanf("%f %f", &x1, &y1);
	printf("Enter the ending point:");
	scanf("%f %f", &x2, &y2);
	initgraph(&gd, &gm, NULL);
	dy = y2-y1;
	dx = x2-x1;
	p = (abs(dy) > abs(dx)) ? abs(dy) : abs(dx);
	xn = dx / p;
	yn = dy / p;
	for(int i = 0; i<=p; i++){
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
		putpixel(finalX, finalY, RED);
		x1+=xn;
		y1+=yn;
	}
	getch();
	closegraph();
	return 0;
}
