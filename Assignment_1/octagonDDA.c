#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

void dda(float x1, float y1, float x2, float y2){
    float dy, dx, xn, yn, p;
    int finalX, finalY;
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
		//printf("|%20f|%20f|%20d|%20d|\n", x1, y1, finalX, finalY);
		x1+=xn;
		y1+=yn;
	}
}

int main(){
    float x1, y1, xn, yn, p;
    float c2x, c2y, c3x, c3y,c4x, c4y,c5x, c5y,c6x, c6y,c7x, c7y,c8x, c8y;
    int gd=DETECT, gm, length;
    
    printf("Enter the starting coordinate of octagon: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the length of side: ");
    scanf("%d", &length);
    
    c2x = x1 + length;
    c2y = y1;
    c3x = c2x + ((sqrt(2)/2) * length);
    c3y = c2y + ((sqrt(2)/2) * length);
    c4x = c3x;
    c4y = c3y + length;
    c5x = c4x - ((sqrt(2)/2) * length);
    c5y = c4y + ((sqrt(2)/2) * length);
    c6x = c5x - length;
    c6y = c5y;
    c7x = c6x - ((sqrt(2)/2) * length);
    c7y = c6y - ((sqrt(2)/2) * length);
    c8x = c7x;
    c8y = c7y - length;
    initgraph(&gd, &gm, NULL);
    dda(x1,y1,c2x,c2y);
    dda(c2x,c2y,c3x,c3y);
    dda(c3x,c3y,c4x,c4y);
    dda(c4x,c4y,c5x,c5y);
    dda(c5x,c5y,c6x,c6y);
    dda(c6x,c6y,c7x,c7y);
    dda(c7x,c7y,c8x,c8y);
    dda(c8x,c8y,x1,y1);
    
    getch();
    
	return 0;
}
