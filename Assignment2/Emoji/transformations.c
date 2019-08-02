#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<X11/Xlib.h>
#include<math.h>

void drawEllipse(int xc, int yc, int stangle, int endangle, int a, int b,  
float alpha, int color) 
{ 
    float t = 3.14 / 180; 
    alpha = 360 - alpha; 
    setcolor(color); 
    int theta; 
  
    // Filling each pixel corresponding 
    // to every angle from 0 to 360 
    for (int i = stangle; i < endangle; i += 1) { 
        theta = i; 
        int x = a * cos(t * theta) * cos(t * alpha) 
                + b * sin(t * theta) * sin(t * alpha); 
  
        int y = b * sin(t * theta) * cos(t * alpha) 
                - a * cos(t * theta) * sin(t * alpha); 
  
        putpixel(xc + x, yc - y, color); 
    } 
} 

void outerCircle(int x, int y, int r){
    int xNext, yNext, p;
    
    p = 3 - 2*r;
    
    yNext = r;
    
    for(xNext = 0; xNext <= yNext; xNext++){
        putpixel(xNext+x, yNext+y, YELLOW);
        putpixel(-xNext+x, yNext+y, YELLOW);
        putpixel(xNext+x, -yNext+y, YELLOW);
        putpixel(-xNext+x, -yNext+y, YELLOW);
        putpixel(-yNext+x, xNext+y, YELLOW);
        putpixel(yNext+x, xNext+y, YELLOW);
        putpixel(yNext+x, -xNext+y, YELLOW);
        putpixel(-yNext+x, -xNext+y, YELLOW);
        if(p < 0){
            p+=(4*xNext+6);
        }else{
            yNext--;
            p+=(4*xNext-4*yNext+10);
        }
    }
    //bf4(x,y, 14, 14);
}

void ddaLine(float x1, float y1, float x2, float y2){
    float dy, dx, p, xn, yn, rr;
    int finalX, finalY; 
    dy = y2-y1;
	dx = x2-x1;
	p = (abs(dy) > abs(dx)) ? abs(dy) : abs(dx);
	xn = dx / p;
	yn = dy / p;
	for(int i = 0; i<=p; i++){
        putpixel(finalX, finalY, RED);
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
		x1+=xn;
		y1+=yn;
	}
}

void heartEyes(){
    ddaLine((getmaxx()/2)+30, (getmaxy()/2), (getmaxx()/2)+66, (getmaxy()/2)-27);    
    ddaLine((getmaxx()/2)+30, (getmaxy()/2), (getmaxx()/2)+12, (getmaxy()/2)-44);      
    arc((getmaxx()/2)+27, (getmaxy()/2)-43,0,180,15);          
    arc((getmaxx()/2)+53, (getmaxy()/2)-35,310,500,15);
    ddaLine((getmaxx()/2)-30, (getmaxy()/2), (getmaxx()/2)-66, (getmaxy()/2)-27);    
    ddaLine((getmaxx()/2)-30, (getmaxy()/2), (getmaxx()/2)-12, (getmaxy()/2)-44);      
    arc((getmaxx()/2)-53, (getmaxy()/2)-35,15,210,15);         
    arc((getmaxx()/2)-27, (getmaxy()/2)-43,0,180,15);
    //bf4((getmaxx()/2)+30, (getmaxy()/2)-20, 4, 4);
    //bf4((getmaxx()/2)-30, (getmaxy()/2)-20, 4, 4);
}

void heartEyesR(int r){
    float x1, x2, y1, y2, x3, x4, y3, y4, x5, x6, x7, x8, y5, y6, y7, y8, cx1, cx2, cx3, cx4, cy1, cy2, cy3, cy4;
    float rx1, rx2, ry1, ry2, rx3, rx4, ry3, ry4, rx5, rx6, rx7, rx8, ry5, ry6, ry7, ry8, rcx1, rcx2, rcx3, rcx4, rcy1, rcy2, rcy3, rcy4;
    float rr;
    int resr;
    x1 = (getmaxx()/2)+30;
    y1 = (getmaxy()/2);
    x2 = (getmaxx()/2)+66;
    y2 = (getmaxy()/2)-27;
    x3 = (getmaxx()/2)+30;
    y3 = (getmaxy()/2);
    x4 = (getmaxx()/2)+12;
    y4 = (getmaxy()/2)-44;
    x5 = (getmaxx()/2)-30;
    y5 = (getmaxy()/2);
    x6 = (getmaxx()/2)-66;
    y6 = (getmaxy()/2)-27;
    x7 = (getmaxx()/2)-30;
    y7 = (getmaxy()/2);
    x8 = (getmaxx()/2)-12;
    y8 = (getmaxy()/2)-44;
    cx1 = (getmaxx()/2)+27;
    cy1 = (getmaxy()/2)-43;
    cx2 = (getmaxx()/2)+53;
    cy2 = (getmaxy()/2)-35;
    cx3 = (getmaxx()/2)-53;
    cy3 = (getmaxy()/2)-35;
    cx4 = (getmaxx()/2)-27;
    cy4 = (getmaxy()/2)-43;
    if(r < 0){
            resr = 360 - r;
            rr = resr*(M_PI/180);
            rx1 = (x1-getmaxx()/2)*cos(rr) + (y1-getmaxy()/2)*sin(rr);
            ry1 = (y1-getmaxy()/2)*cos(rr) - (x1-getmaxx()/2)*sin(rr);
            rx2 = (x2-getmaxx()/2)*cos(rr) + (y2-getmaxy()/2)*sin(rr);
            ry2 = (y2-getmaxy()/2)*cos(rr) - (x2-getmaxx()/2)*sin(rr);
            rx3 = (x3-getmaxx()/2)*cos(rr) + (y3-getmaxy()/2)*sin(rr);
            ry3 = (y3-getmaxy()/2)*cos(rr) - (x3-getmaxx()/2)*sin(rr);
            rx4 = (x4-getmaxx()/2)*cos(rr) + (y4-getmaxy()/2)*sin(rr);
            ry4 = (y4-getmaxy()/2)*cos(rr) - (x4-getmaxx()/2)*sin(rr);
            rx5 = (x5-getmaxx()/2)*cos(rr) + (y5-getmaxy()/2)*sin(rr);
            ry5 = (y5-getmaxy()/2)*cos(rr) - (x5-getmaxx()/2)*sin(rr);
            rx6 = (x6-getmaxx()/2)*cos(rr) + (y6-getmaxy()/2)*sin(rr);
            ry6 = (y6-getmaxy()/2)*cos(rr) - (x6-getmaxx()/2)*sin(rr);
            rx7 = (x7-getmaxx()/2)*cos(rr) + (y7-getmaxy()/2)*sin(rr);
            ry7 = (y7-getmaxy()/2)*cos(rr) - (x7-getmaxx()/2)*sin(rr);
            rx8 = (x8-getmaxx()/2)*cos(rr) + (y8-getmaxy()/2)*sin(rr);
            ry8 = (y8-getmaxy()/2)*cos(rr) - (x8-getmaxx()/2)*sin(rr);
            rcx1 = (cx1-getmaxx()/2)*cos(rr) + (cy1-getmaxy()/2)*sin(rr);
            rcy1 = (cy1-getmaxy()/2)*cos(rr) - (cx1-getmaxx()/2)*sin(rr);
            rcx2 = (cx2-getmaxx()/2)*cos(rr) + (cy2-getmaxy()/2)*sin(rr);
            rcy2 = (cy2-getmaxy()/2)*cos(rr) - (cx2-getmaxx()/2)*sin(rr);
            rcx3 = (cx3-getmaxx()/2)*cos(rr) + (cy3-getmaxy()/2)*sin(rr);
            rcy3 = (cy3-getmaxy()/2)*cos(rr) - (cx3-getmaxx()/2)*sin(rr);
            rcx4 = (cx4-getmaxx()/2)*cos(rr) + (cy4-getmaxy()/2)*sin(rr);
            rcy4 = (cy4-getmaxy()/2)*cos(rr) - (cx4-getmaxx()/2)*sin(rr);
        }else{
            rr = r*(M_PI/180);
            rx1 = (x1-getmaxx()/2)*cos(rr) - (y1-getmaxy()/2)*sin(rr);
            ry1 = (y1-getmaxy()/2)*cos(rr) + (x1-getmaxx()/2)*sin(rr);
            rx2 = (x2-getmaxx()/2)*cos(rr) - (y2-getmaxy()/2)*sin(rr);
            ry2 = (y2-getmaxy()/2)*cos(rr) + (x2-getmaxx()/2)*sin(rr);
            rx3 = (x3-getmaxx()/2)*cos(rr) - (y3-getmaxy()/2)*sin(rr);
            ry3 = (y3-getmaxy()/2)*cos(rr) + (x3-getmaxx()/2)*sin(rr);
            rx4 = (x4-getmaxx()/2)*cos(rr) - (y4-getmaxy()/2)*sin(rr);
            ry4 = (y4-getmaxy()/2)*cos(rr) + (x4-getmaxx()/2)*sin(rr);
            rx5 = (x5-getmaxx()/2)*cos(rr) - (y5-getmaxy()/2)*sin(rr);
            ry5 = (y5-getmaxy()/2)*cos(rr) + (x5-getmaxx()/2)*sin(rr);
            rx6 = (x6-getmaxx()/2)*cos(rr) - (y6-getmaxy()/2)*sin(rr);
            ry6 = (y6-getmaxy()/2)*cos(rr) + (x6-getmaxx()/2)*sin(rr);
            rx7 = (x7-getmaxx()/2)*cos(rr) - (y7-getmaxy()/2)*sin(rr);
            ry7 = (y7-getmaxy()/2)*cos(rr) + (x7-getmaxx()/2)*sin(rr);
            rx8 = (x8-getmaxx()/2)*cos(rr) - (y8-getmaxy()/2)*sin(rr);
            ry8 = (y8-getmaxy()/2)*cos(rr) + (x8-getmaxx()/2)*sin(rr);
            rcx1 = (cx1-getmaxx()/2)*cos(rr) - (cy1-getmaxy()/2)*sin(rr);
            rcy1 = (cy1-getmaxy()/2)*cos(rr) + (cx1-getmaxx()/2)*sin(rr);
            rcx2 = (cx2-getmaxx()/2)*cos(rr) - (cy2-getmaxy()/2)*sin(rr);
            rcy2 = (cy2-getmaxy()/2)*cos(rr) + (cx2-getmaxx()/2)*sin(rr);
            rcx3 = (cx3-getmaxx()/2)*cos(rr) - (cy3-getmaxy()/2)*sin(rr);
            rcy3 = (cy3-getmaxy()/2)*cos(rr) + (cx3-getmaxx()/2)*sin(rr);
            rcx4 = (cx4-getmaxx()/2)*cos(rr) - (cy4-getmaxy()/2)*sin(rr);
            rcy4 = (cy4-getmaxy()/2)*cos(rr) + (cx4-getmaxx()/2)*sin(rr);
        }
    line(rx1+getmaxx()/2, ry1+getmaxy()/2, rx2+getmaxx()/2, ry2+getmaxy()/2);    
    line(rx3+getmaxx()/2, ry3+getmaxy()/2, rx4+getmaxx()/2, ry4+getmaxy()/2);      
    arc(rcx1+(getmaxx()/2), rcy1+(getmaxy()/2),-r,180-r,15);          
    arc(rcx2+(getmaxx()/2), rcy2+(getmaxy()/2),310-r,500-r,15);
    line(rx5+getmaxx()/2, ry5+getmaxy()/2, rx6+getmaxx()/2, ry6+getmaxy()/2);    
    line(rx7+getmaxx()/2, ry7+getmaxy()/2, rx8+getmaxx()/2, ry8+getmaxy()/2);      
    arc(rcx3+(getmaxx()/2), rcy3+(getmaxy()/2),15-r,210-r,15);         
    arc(rcx4+(getmaxx()/2), rcy4+(getmaxy()/2),-r,180-r,15);
    //bf4((getmaxx()/2)+30, (getmaxy()/2)-20, 4, 4);
    //bf4((getmaxx()/2)-30, (getmaxy()/2)-20, 4, 4);
}

void mouth(){
    setcolor(15);
    drawEllipse(getmaxx()/2, (getmaxy()/2)+30, 175,360, 60, 40, 0, 15);
    drawEllipse(getmaxx()/2, (getmaxy()/2)+27, 180,360, 60, 20,0, 15);
    setcolor(4);
    drawEllipse(getmaxx()/2, (getmaxy()/2)+68, 0, 180, 20, 12,0, 15);
    //ff4((getmaxx()/2)+10,(getmaxy()/2)+50, 14, 0);
    //ff4((getmaxx()/2)+10,(getmaxy()/2)+60, 14, 4);
}



void mouthr(int r){
    int resr;
    float rr, rx1, ry1, rx2, ry2, rx3, ry3, x1, y1, x2, y2, x3, y3;
    x1 = getmaxx()/2;
    y1 = (getmaxy()/2)+30;
    x2 = getmaxx()/2;
    y2 = (getmaxy()/2)+27;
    x3 = getmaxx()/2;
    y3 = (getmaxy()/2)+68;
    resr = 360 - r;
    if(r < 0){
            rr = resr*(M_PI/180);
            rx1 = (x1-getmaxx()/2)*cos(rr) + (y1-getmaxy()/2)*sin(rr);
            ry1 = (y1-getmaxy()/2)*cos(rr) - (x1-getmaxx()/2)*sin(rr);
            rx2 = (x2-getmaxx()/2)*cos(rr) + (y2-getmaxy()/2)*sin(rr);
            ry2 = (y2-getmaxy()/2)*cos(rr) - (x2-getmaxx()/2)*sin(rr);
            rx3 = (x3-getmaxx()/2)*cos(rr) + (y3-getmaxy()/2)*sin(rr);
            ry3 = (y3-getmaxy()/2)*cos(rr) - (x3-getmaxx()/2)*sin(rr);
        }else{
            rr = r*(M_PI/180);
            rx1 = (x1-getmaxx()/2)*cos(rr) - (y1-getmaxy()/2)*sin(rr);
            ry1 = (y1-getmaxy()/2)*cos(rr) + (x1-getmaxx()/2)*sin(rr);
            rx2 = (x2-getmaxx()/2)*cos(rr) - (y2-getmaxy()/2)*sin(rr);
            ry2 = (y2-getmaxy()/2)*cos(rr) + (x2-getmaxx()/2)*sin(rr);
            rx3 = (x3-getmaxx()/2)*cos(rr) - (y3-getmaxy()/2)*sin(rr);
            ry3 = (y3-getmaxy()/2)*cos(rr) + (x3-getmaxx()/2)*sin(rr);
        }
    setcolor(15);
    drawEllipse(rx1+getmaxx()/2, ry1+(getmaxy()/2), 175,360,  60, 40, resr, 15);
    drawEllipse(rx2+getmaxx()/2, ry2+(getmaxy()/2), 180,360, 60, 20, resr, 15);
    setcolor(4);
    drawEllipse(rx3+getmaxx()/2, ry3+(getmaxy()/2), 0, 180, 20, 12, resr, 15);
    //ff4((getmaxx()/2)+10,(getmaxy()/2)+50, 14, 0);
    //ff4((getmaxx()/2)+10,(getmaxy()/2)+60, 14, 4);
}

void demoji(){		      //default emoji
      //draws face
      int bc, e1, e2, ;
      circle(x1+screenx/2,y1+screeny/2,r1);                      //circle drawn
      bc = getpixel(x1+screenx/2+3,y1+screeny/2+3);             //gets the color from the circle to fill
      fill(x1+10+screenx/2+3,y1+10+screeny/2+3,bc,YELLOW);      //fills color

      //function to draw ellipse
      ellipse((x1+10+screenx/2)-25,(y1+10+screeny/2)-15,0,360,3,6);
      ellipse((x1+10+screenx/2)+3,(y1+10+screeny/2)-15,0,360,3,6);

      //gets the color inside ellipse to change the old color
      e1 = getpixel((x1+10+screenx/2)-25,(y1+10+screeny/2)-15);
      e2 = getpixel((x1+10+screenx/2)+3,(y1+10+screeny/2)-15);

      //fills the eye with black color
      fill((x1+10+screenx/2)-25,(y1+10+screeny/2)-20,e1,BLACK);
      fill((x1+10+screenx/2)+3,(y1+10+screeny/2)-20,e2,BLACK);

      //draws the mouth
      setcolor(BLACK);
      line((x1+screenx/2)-15,(y1+screeny/2)+12,(x1+screenx/2)+15,(y1+screeny/2)+12);
}

void main(){
    int r, x1, x2, y1, y2, rx1, ry1, rx2, ry2, gd=X11, gm=X11_1366x768, resr;
    float rr;
    printf("Enter angle: ");
    scanf("%d", &r);
    printf("Enter starting point: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter ending point: ");
    scanf("%d %d", &x2, &y2);
    initgraph(&gd, &gm, "");
    ddaLine(x1, y1, x2, y2);
    getch();
    if(r < 0){
            resr = 360 - r;
            rr = resr*(M_PI/180);
            rx1 = (x1-(x1+x2)/2)*cos(rr) + (y1-(y1+y2)/2)*sin(rr);
            ry1 = (y1-(y1+y2)/2)*cos(rr) - (x1-(x1+x2)/2)*sin(rr);
            rx2 = (x2-(x1+x2)/2)*cos(rr) + (y2-(y1+y2)/2)*sin(rr);
            ry2 = (y2-(y1+y2)/2)*cos(rr) - (x2-(x1+x2)/2)*sin(rr);
        }else{
            rr = r*(M_PI/180);
            rx1 = (x1-(x1+x2)/2)*cos(rr) - (y1-(y1+y2)/2)*sin(rr);
            ry1 = (y1-(y1+y2)/2)*cos(rr) + (x1-(x1+x2)/2)*sin(rr);
            rx2 = (x2-(x1+x2)/2)*cos(rr) - (y2-(y1+y2)/2)*sin(rr);
            ry2 = (y2-(y1+y2)/2)*cos(rr) + (x2-(x1+x2)/2)*sin(rr);
        }
    ddaLine(rx1+(x1+x2)/2, ry1+(y1+y2)/2, rx2+(x1+x2)/2, ry2+(y1+y2)/2);
    ellipse(300, 300, 0, 180, 30, 30);
    ellipse(300, 500, r, 180+r, 30, 30);
    heartEyes();
    mouth();
    getch();
    cleardevice();
    heartEyesR(r);
    mouthr(r);
    getch();
    closegraph();
}
