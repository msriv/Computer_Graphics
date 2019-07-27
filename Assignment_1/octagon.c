#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

#define PI 3.14159265 

int main(){
    float x1, y1, xn, yn, dy, dx, xNext, yNext, xPrev, yPrev, p, lineDistance, r, t;
    int gd=DETECT, gm, finalX, finalY;
    //int rotationMatrix[2]; 
    printf("Enter the starting coordinate of octagon: ");
    scanf("%f %f", &x1, &y1);
    
    //initgraph(&gd, &gm, NULL);
    xNext = x1;
    yNext = y1;
    xPrev = x1;
    yPrev = y1;
    //printf("xNext\t\tyNext");
    for(int i = 0; i < 8; i++){
        
        printf("%f %f %f\n", xNext, yNext, lineDistance);
    
        /*xNext = (xPrev * cos((3*PI)/4)) - (yPrev*sin((3*PI)/4));
        yNext = (xPrev * sin((3*PI)/4)) + (yPrev*cos((3*PI)/4));*/
        lineDistance = sqrt(((yNext-yPrev)*(yNext-yPrev)) + ((xNext-xPrev)*(xNext-xPrev)));
    
        t = atan(y1/x1);
        r = sqrt(pow(x1,2) + pow(y1,2));
        
        xNext = (r*cos(t + i*(PI/4)));
        yNext = (r*sin(t + i*(PI/4)));
        
        
        dy = yNext - yPrev;
        dx = xNext - xPrev;
        
        p = (abs(dy) > abs(dx)) ? abs(dy) : abs(dx);
        
        xn = dx/p;
        yn = dy/p;
        
        for(int j=0; j<=p; j++){
            //putpixel(finalX, finalY, RED);
            if(xPrev < 0){
			finalX = ((xPrev*10)/10)-0.5;
            }else{
                finalX = ((xPrev*10)/10)+0.5;
            }
            if(yPrev < 0){
                finalY = ((yPrev*10)/10)-0.5;
            }else{
                finalY = ((yPrev*10)/10)+0.5;
            }
            //printf("|%20f|%20f|%20d|%20d|\n", x1, y1, finalX, finalY);
            
            xPrev+=xn;
            yPrev+=yn;
        }
        
        xPrev = xNext;
        yPrev = yNext;
        
    }
    
    
    getch();
    return 0;
    
}
