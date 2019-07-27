#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>

void dda(int fx1, int fy1, int fx2, int fy2, int xMin, int xMax, int yMin, int yMax);

// Check Point function that checks whether the pixel is inside the clipping path or not. 
int checkPoint(int x, int y, int xMin, int yMin, int xMax, int yMax){
    if(x < xMin){
        return 1;
    }else if(x > xMax){
        return 2;
    }else if(y < yMin){
        return 3;
    }else if(y > yMax){
        return 4;
    }
    return 0;   // Returns 0 when the pixel is inside the clipping path.
}

void polygon(){
    // Hard coded the polygon 
    dda(100, 100,130, 350, 120, 300, 120, 470);
    dda(130, 350,270, 150, 120, 300, 120, 470);
    dda(270, 150,280, 450, 120, 300, 120, 470);
    dda(280, 450,400, 300, 120, 300, 120, 470);
    dda(400, 300,270, 150, 120, 300, 120, 470);
    dda(270, 150,100, 100,120, 300, 120, 470);
    dda(130, 350,280, 450,120, 300, 120, 470);
}

void dda(int fx1, int fy1, int fx2, int fy2, int xMin, int xMax, int yMin, int yMax){
    /*
     * Finding difference between coordinate values and determining the number of pixels for drawing the line. 
     */
    float x1, x2, y1, y2,dy, dx, xn, yn, p;
    int finalX, finalY;
    
    x1 = fx1;
    x2 = fx2;
    y1 = fy1;
    y2 = fy2;
    
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
        
        // Plotting the rounded points on the screen
        if(checkPoint(finalX, finalY, xMin, yMin, xMax, yMax) == 0){
            putpixel(finalX, finalY, RED);
        }else{
            putpixel(finalX, finalY, 0);
        }
        //delay(10);
        x1+=xn;
		y1+=yn;
	}
}

void main(){
    int x1, y1, x2, y2, xMin, yMin, xMax, yMax, gd=DETECT, gm;
    int arr[] = {100,100,130,350,270,150,280,450,400,300,270,150,100,100,130,350,280,450};
    /*
     * Taking input only in case of line clipping.
     * Hard coded the polygon and the clipping path for the polygon.
     */
    
    /*printf("Enter the starting coordinates of the line: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the ending coordinates of the line: ");
    scanf("%d %d", &x2, &y2);
    
    printf("Enter the starting coordinates of the clipping window: ");
    scanf("%d %d", &xMin, &yMin);
    printf("Enter the ending coordinates of the clipping window: ");
    scanf("%d %d", &xMax, &yMax);*/
    
    
    initgraph(&gd, &gm, NULL);
    
    // In case of line clipping we draw an initial line.
    //line(x1, y1, x2, y2);        
    
    // Clipping Path
    
    
    // Draw the clipped line using the Cohen-Sutherland Algorithm.
    //dda(x1, y1, x2, y2, xMin, xMax, yMin, yMax);
    
    // Draw the original polygon
    drawpoly(9, arr);
    getch();
    // Draw the clipping path
    rectangle(120, 120, 300, 470);
    getch();
    // Draws the polygon using the DDA Algorithm which checks the condition for the clipping path.
    polygon();
    getch();
    closegraph();
}

