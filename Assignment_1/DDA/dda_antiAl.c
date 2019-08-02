/*
 *  Author: Mihir Srivastava
 *  Based on: Digital Differentiator Algorithm for Line Drawing
 *  Purpose: To understand and implement Pre Sampling methods of anti-aliasing a jagged line.
 *
 */

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include "/usr/include/graphics.h"
void main(){
    int gd=X11, gm=X11_1024x768, p, finalX, finalY, da, db, colora, colorb;
	float xn, yn, xinc, yinc, x1, x2, y1, y2, dy, dx, fa, fb;
    
    /*
     * Taking Input for starting and ending coordinates.
     */
    printf("Enter the starting point:");
	scanf("%f %f", &x1, &y1);
	printf("Enter the ending point:");
	scanf("%f %f", &x2, &y2);
	
    //setbkcolor(WHITE);
    
    /*
     * Finding difference between coordinate values and determining the number of pixels for drawing the line. 
     */
    
    dy = y2-y1;
	dx = x2-x1;
	
    //p = (abs(dy) > abs(dx)) ? abs(dy) : abs(dx);
	
    if(abs(dy) > abs(dx)){
        p = abs(dy);
    }else{
        p = abs(dx);
    }

    xn = dx / p;
	yn = dy / p;
    
    /*
     * Plotting the pixels till the determined value of steps 'p'.
     */
    initgraph(&gd, &gm, "");
    
	for(int i = 0; i<=p; i++){
        
        // Rounding the final value of x1 and y1 for plotting the actual pixel.
        //printf("%d, %d", finalX, finalY);
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
        
        putpixel(finalX, finalY, RED);
        
        // Plotting the anti-aliased pixels based on the float factor from the original floating points.
        if(finalX > x1){
            colora=fa*10;
            putpixel(finalX-1, finalY, colora);
        }else{
            putpixel(finalX+1, finalY, colora);
        }
        
        if(finalY > y1){
            colorb=fb*10;
            putpixel(finalX, finalY-1, colorb);
        }else{
            putpixel(finalX, finalY+1, colorb);
        }
    
        
        
        x1+=xn;
		y1+=yn;
	}
	getch();
}
