/*
 * Author: Mihir Srivastava
 * Assignment 1: Comparison of line generation algorithms
 * 
 * 
 * Subject: Computer Graphics
 * 
 */

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<X11/Xlib.h>
void options();

void dda(float x1, float y1, float x2, float y2){
    
    // Variable declaration
    
    int gd=DETECT, gm, p, finalX, finalY;
    float xn, yn, xinc, yinc, dy, dx, c, d;
    initgraph(&gd, &gm, NULL);
    printf("Digital Differentiator Algorithm");
    
    /*
     * Finding the difference between X and Y coordinates for finding 'p' 
     * that is the number of steps required to generate line
     *
     */ 
    
	dy = y2-y1;
	dx = x2-x1;
	p = (abs(dy) > abs(dx)) ? abs(dy) : abs(dx);
	xn = dx / p;
	yn = dy / p;
    
    // Calculating the rounded values for each pixel to plot on the screen.
    
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
		putpixel(finalX, finalY, WHITE);
		x1+=xn;
		y1+=yn;
	}
	getch();
    closegraph();
}

void bresenham(int x1, int y1, int x2, int y2){
    int yNext, dy, dx, pK, xNext, gd=DETECT, gm;
    yNext = y1;
    
    /*
     * Finding the difference between X and Y coordinates for finding 'pK' 
     * that is used as a decision factor in plotting the next pixel if the 
     * line is over two pixels.
     *
     */
    
    dy = y2-y1;
    dx = x2-x1;
    
    if(dy > dx){
        printf("Please select other points for which difference in y is less than difference in x");
        options();
        
    }else{
        initgraph(&gd,&gm,NULL);
        printf("Bresenham's Line Drawing Algorithm");
        pK = 2*dy - dx;         // Error: pK = 2*dx - dy;
    
        for(xNext = x1; xNext <= x2; xNext++){
            putpixel(xNext, yNext, YELLOW);
            //printf("%d\t%d\t%d\n", pK, xNext, yNext);
            if(pK > 0){
                pK = pK + 2*dy - 2*dx;
                yNext++;
            }else{
                pK = pK + 2*dy;
            }
            //delay(100);
            
        }
        getch();
        closegraph();
    }
}

void midpoint(int x1, int y1, int x2, int y2){
    int yNext, xNext, dy, dx, gd=DETECT, gm, q, decisionFactor;
    float mX, mY;
    dy = y2 - y1;
    dx = x2 - x1;
     if(dy > dx){
        printf("Please select other points for which difference in y is less than difference in x");
        options();
    }else{
        initgraph(&gd,&gm,NULL);
        printf("Midpoint Line Drawing Algorithm");
    yNext = y1;
    
    q = dy - dx;
    
    decisionFactor = dy-(dx/2);
    //printf("decisionFactor\t\txNext\t\tyNext\t\t(Mx,My)\n");
    for(xNext=x1;xNext<=x2;xNext++){
        
        mX = xNext+1;
        mY = yNext+0.5;
        //printf("%d\t\t%d\t\t%d\t\t(%f, %f)\n", decisionFactor, xNext, yNext, mX, mY);
        putpixel(xNext, yNext, RED);
        if(decisionFactor > 0){
            yNext++;
            decisionFactor+=q;
        }else{
            decisionFactor+=dy;
        }
    }
    getch();
    closegraph();
    }
}

void options(){
    int option;
    
    printf("\n----------------------------------------------------------------\nPlease select any of the following options\n\n");
    printf("1. Digital Differentiator Algorithm\n");
    printf("2. Bresenham's Line Drawing Algorithm\n");
    printf("3. Midpoint Line Algorithm\n");
    printf("4. Exit\n");
    printf(">>\t");
    scanf("%d", &option);

    switch(option){
        case 1: {
            
            float x1, x2, y1, y2;
            printf("Enter a starting point: ");
            scanf("%f %f", &x1, &y1);
            printf("Enter the ending point: ");
            scanf("%f %f", &x2, &y2);
            
            dda(x1, y1, x2, y2);
            options();
        }break;
        
        case 2: {
            
            int x1, x2, y1, y2;
            printf("Enter a starting point: ");
            scanf("%d %d", &x1, &y1);
            printf("Enter the ending point: ");
            scanf("%d %d", &x2, &y2);
            
            bresenham(x1, y1, x2, y2);
            options();
        }break;
        
        case 3: {
            
            int x1, x2, y1, y2;
            printf("Enter a starting point: ");
            scanf("%d %d", &x1, &y1);
            printf("Enter the ending point: ");
            scanf("%d %d", &x2, &y2);
            
            midpoint(x1, y1, x2, y2);
            options();
        }break;
        
        case 4: {
            return;
        }break;
    }
}

int main(){
    XInitThreads();
    printf("Author: Mihir Srivastava\nDate_of_submission: 19/07/2019\nAssignment: Comparison of algorithms for Line generation\n------------------------------------------------------------\n\n");
    options();
}
