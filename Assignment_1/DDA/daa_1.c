#include<math.h>
#include<stdio.h>
#include<stdlib.h>

void main(){
	float xn, yn, xinc, yinc, x1, x2, y1, y2, dy, dx, c, d;
	int p, finalX, finalY, a, b;

	printf("Enter the starting point:\n");
	scanf("%f %f", &x1, &y1);
	printf("Enter the starting point:\n");
	scanf("%f %f", &x2, &y2);
	//printf("%f %f %f %f", x1, x2, y1, y2);	
	dy = y2-y1;
	dx = x2-x1;
	//printf("%d %d", dy, dx);
	p = (abs(dy) > abs(dx)) ? abs(dy) : abs(dx);
	//printf("%d", p);
	xn = dx / p;
	yn = dy / p;
	printf("\tx\t\t    y\t\t\txnew\t\t\tynew\n");
	for(int i = 0; i<=p; i++){
		/*a = (x1*10);
		b = (y1*10);
		c = a;
		d = b;
		finalX = (c/10)+0.5;
		finalY = (d/10)+0.5;*/
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
		printf("|%20f|%20f|%20d|%20d|\n", x1, y1, finalX, finalY);
		x1 += xn;
		y1+=yn;
	}
}
