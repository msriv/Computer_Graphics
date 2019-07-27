#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>

int circleEquation(int x, int y, int r);

void bresenhams(int x, int y, int r){
        int xNext, xNext1, yNext, yNext1, p, p1;
        int a=1;
        p = 3 - (2 * r);
        yNext1 = r;
        xNext1 = 0;
        xNext = 0;
        if(p > 0){
            p1=p+(4*xNext1-4*yNext1+10);
            yNext1--;
            xNext1++;
        }else{
            p1=p+(4*xNext1+6);
            xNext1++;
        }
        
        yNext = r;
        //printf("p = %d, p1 = %d, yNext1 = %d, xNext1 = %d, yNext = %d, xNext = %d", p, p1, yNext1, xNext1, yNext, xNext);
        for(xNext = 0; xNext <= yNext; xNext++){
            //printf("%d\t%d\n", xNext, yNext);
            /*putpixel(xNext+x, yNext+y, RED);
            putpixel(-xNext+x, yNext+y, RED);
            putpixel(xNext+x, -yNext+y, RED);
            putpixel(-xNext+x, -yNext+y, RED);
            putpixel(-yNext+x, xNext+y, RED);
            putpixel(yNext+x, xNext+y, RED);
            putpixel(yNext+x, -xNext+y, RED);
            putpixel(-yNext+x, -xNext+y, RED);*/
            //printf("x = %d, y = %d", x, y);
            //printf("(%d, %d)\t (%d, %d)\n", xNext*(x/abs(x)), yNext*(y/abs(y)), xNext1*(x/abs(x)), yNext1*(y/abs(y)));
            if(xNext1 == abs(x) && yNext1 == abs(y) && y >= x){
                printf("Previous Point: (%d, %d)\n", xNext*(x/abs(x)), yNext*(y/abs(y)));
                printf("Current Point: (%d, %d)\n", xNext1*(x/abs(x)), yNext1*(y/abs(y)));
                a=0;
            }else if(yNext1 == abs(x) && xNext1 == abs(y) && y < x){
                printf("Previous Point: (%d, %d)\n", yNext*(y/abs(y)), xNext*(x/abs(x)));
                printf("Current Point: (%d, %d)\n", yNext1*(y/abs(y)), xNext1*(x/abs(x)));
                a=3;
            }
            if(p1 > 0){
                p1=p1+4*xNext1-4*yNext1+10;
                yNext1--;
                xNext1++;
            }else{
                p1=p1+4*xNext1+6;
                xNext1++;
            }
            
            
            if(p > 0){
                p+=(4*xNext-4*yNext+10);
                yNext--;
            }else{
                p+=(4*xNext+6);
            }
            
            if(a == 0){
                printf("1.Next Point: (%d, %d)\n", xNext1*(x/abs(x)), yNext1*(y/abs(y)));
                a=2;
            }else if(a == 3){
                printf("2.Next Point: (%d, %d)\n", yNext1*(y/abs(y)), xNext1*(x/abs(x)));
                a=2;
            }
        }
        if(a==1){
            if(circleEquation(x,y,r) > 0){
                printf("Point lies outside the circle.");
            }else if(circleEquation(x,y,r) < 0){
                printf("Point lies inside the circle.");
            }else {
                printf("Problem");
            }
        }
}

int circleEquation(int x, int y, int r){
    return(x*x + y*y - r*r);
}

void main(){
    int x, y, r, gd=DETECT, gm;
    
    printf("Enter the point: ");
    scanf("%d %d", &x, &y);
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);
    //initgraph(&gd, &gm, NULL);
    
    //line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    //line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    //x = x+(getmaxx()/2);
    //y = y+(getmaxy()/2);
    bresenhams(x, y, r);
    
    getch();
    
}
