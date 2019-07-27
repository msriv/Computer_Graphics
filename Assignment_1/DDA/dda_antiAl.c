/*
 *  Author: Mihir Srivastava
 *  Based on: Digital Differentiator Algorithm for Line Drawing
 *  Purpose: To understand and implement Pre Sampling methods of anti-aliasing a jagged line.
 *
 */

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
int main(){
    int gd=DETECT, gm, p, finalX, finalY, da, db, colora, colorb;
	float xn, yn, xinc, yinc, x1, x2, y1, y2, dy, dx, fa, fb;
    
    /*
     * Taking Input for starting and ending coordinates.
     */
    printf("Enter the starting point:");
	scanf("%f %f", &x1, &y1);
	printf("Enter the ending point:");
	scanf("%f %f", &x2, &y2);
	initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);
    
    /*
     * Finding difference between coordinate values and determining the number of pixels for drawing the line. 
     */
    
    dy = y2-y1;
	dx = x2-x1;
	
    p = (abs(dy) > abs(dx)) ? abs(dy) : abs(dx);
	
    xn = dx / p;
	yn = dy / p;
    
    /*
     * Plotting the pixels till the determined value of steps 'p'.
     */
    
	for(int i = 0; i<=p; i++){
        
        // Rounding the final value of x1 and y1 for plotting the actual pixel.
        
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
		
		// Getting the floating point for determining the contrast of the anti-aliased pixel.
		
		da = x1;
        fa = x1 - da;
        db = y1;
        fb = y1 - db;
        
        // Plotting the rounded points on the screen
        
        putpixel(finalX, finalY, BLACK);
        
        // Plotting the anti-aliased pixels based on the float factor from the original floating points.
        
        if(finalX > x1){
            colora=fa*10;
            putpixel(finalX-1, finalY, Color(255*colora, 0, 0));
        }else{
            putpixel(finalX+1, finalY, Color(255*colora, 0, 0));
        }
        
        if(finalY > y1){
            colorb=fb*10;
            putpixel(finalX, finalY-1, Color(255*colorb, 0, 0));
        }else{
            putpixel(finalX, finalY+1, Color(255*colorb, 0, 0));
        }
    
        
        
        x1+=xn;
		y1+=yn;
	}
	getch();
	return 0;
}
