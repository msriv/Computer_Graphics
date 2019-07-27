#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
int radius(int x, int y);
void checkPoint(int x, int y);
void myCircle(int x, int y, int r){
    int xNext, yNext, prevX, prevY,  p, nnextX, nnextY, a, b, c, d;
    
    p = 3 - 2*r;
    
    yNext = r;
    
    //putpixel(x, y, RED);
    
    
    for(xNext = 0; xNext <= yNext; xNext++){
        //delay(100); 
        //putpixel(xNext+x, yNext+y, RED);
        /*checkPoint(xNext+x, yNext+y);
        //putpixel(-xNext+x, yNext+y, RED);
        checkPoint(-xNext+x, yNext+y);
        //putpixel(xNext+x, -yNext+y, RED);
        checkPoint(xNext+x, -yNext+y);
        //putpixel(-xNext+x, -yNext+y, RED);
        checkPoint(-xNext+x, -yNext+y);
        //putpixel(-yNext+x, xNext+y, RED);
        checkPoint(-yNext+x, xNext+y);
        //putpixel(yNext+x, xNext+y, RED);
        checkPoint(yNext+x, xNext+y);
        //putpixel(yNext+x, -xNext+y, RED);
        checkPoint(yNext+x, -xNext+y);
        //putpixel(-yNext+x, -xNext+y, RED);
        checkPoint(-yNext+x, -xNext+y);*/
        
        if(p < 0){
            p+=(4*xNext+6);
        }else{
            yNext--;
            p+=(4*xNext-4*yNext+10);
            prevY = yNext+y;
        }
        prevX = xNext+x;
    }
}

void checkPoint(int x, int y){
    int n1, n2, min1, min2, arr[8][8], x1, x2, y1, y2;
    
    if(radius(x,y) == 0){
        printf("Point is on the circle.\n");
        arr[0][0] = x-1;
        arr[0][1] = y-1;
        arr[0][2] = abs(radius(x-1,y-1));
        arr[1][0] = x-1;
        arr[1][1] = y;
        arr[1][2] = abs(radius(x-1,y));
        arr[2][0] = x-1;
        arr[2][1] = y+1;
        arr[2][2] = abs(radius(x-1,y+1));
        arr[3][0] = x;
        arr[3][1] = y+1;
        arr[3][2] = abs(radius(x, y+1));
        arr[4][0] = x;
        arr[4][1] = y-1;
        arr[4][2] = abs(radius(x, y-1));
        arr[5][0] = x+1;
        arr[5][1] = y+1;
        arr[5][2] = abs(radius(x+1, y+1));
        arr[6][0] = x+1;
        arr[6][1] = y;
        arr[6][2] = abs(radius(x+1, y));
        arr[7][0] = x+1;
        arr[7][1] = y-1;
        arr[7][2] = abs(radius(x+1, y-1));
        
        min1 = min2 = arr[0][2];
        
        for(int i=0; i<8; i++){
            if(min1 > arr[i][2]){
                min2 = min1;
                min1 = arr[i][2];
            }else if(min2 > arr[i][2] && min1 != arr[i][2]){
                min2 = arr[i][2];
            }
        }
        
        
        
        for(int h = 0; h < 8; h++){
            if(min1 == arr[h][2]){
                x1 = arr[h][0];
                y1 = arr[h][1];
            }
            if(min2 == arr[h][2]){
                x2 = arr[h][0];
                y2 = arr[h][1];
            }
        }
        printf("The neighbouring points are: \n");
        printf("(%d, %d): %d\n",x1,y1, min1);
        printf("(%d, %d): %d\n",x2,y2, min2);
        
        
   /*     printf("The neighbouring points are: (%d,%d), (%d,%d)", x1, y1, x2, y2);
    }else if(radius(x,y) > 0){
        printf("Point is outside the circle");
        return;
    }else{
        printf("Point is inside the circle");
        return;
        
    }*/
    
}
    
}

int radius(int x, int y){
    int a = pow((x),2) + pow((y),2) - pow(5,2);
    printf("(%d,%d), %d\n",x,y, a);
    return (a);
}

int main(){
    
    int x, y, r1, r2, gd=DETECT, gm;
    
    //printf("Enter the center of the circle: ");
    //scanf("%d %d", &x, &y);
    //printf("Enter the radius of the first circle: ");
    //scanf("%d", &r1);
    //printf("Enter the radius of the second circle: ");
    //scanf("%d", &r2);
     
    printf("Enter the point: ");
    scanf("%d %d", &x, &y);
    
    //initgraph(&gd, &gm, NULL);
    
    
    //printf("%d %d", getmaxx()/2, getmaxy()/2);
    //line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    //line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    
    checkPoint(x, y);
    myCircle(319, 239, 100);
    //printf("%d %d", getmaxx()/2, getmaxy()/2);
    //myCircle(getmaxx()/2, getmaxy()/2, 100, x, y);
    /*if(checkPoint(x, y)){
        
    }*/
    
    getch();
    return 0;
}
