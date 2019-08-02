/*
 * Assignment 3: Performing transformations on the emoticon - Translation, Rotation, Scaling.
 * Author: Mihir Srivastava
 * Selected Emoticon: Heart Eyes Emoticon
 */

#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<X11/Xlib.h>
#include<math.h>

// Declaring fill functions so that they can be used throughout the code.
 
void ff4(int x, int y, int oc, int nc);
void bf4(int x, int y, int cc, int nc);

// Custom Ellipse Function. :: Source: GeeksforGeeks :: Introduced stangle and endangle to the function
void drawEllipse(int xc, int yc, int stangle, int endangle, int a, int b,  float alpha, int color) 
{ 
    float t = 3.14 / 180; 
    alpha = 360 - alpha; 
    setcolor(color); 
    int theta; 
  
    // Filling each pixel corresponding 
    // to every angle from 0 to 360 
    if(alpha == 0 || alpha == 360){
        setcolor(color);
        ellipse(xc, yc, stangle, endangle, a, b);
    }else if(alpha == 90){
        setcolor(color);
        ellipse(xc, yc, stangle-90, endangle-90, b, a);
    }else if(alpha == 180){
        setcolor(color);
        ellipse(xc, yc, 360-endangle, 360-stangle, a, b);
    }else if(alpha == 270){
        setcolor(color);
        ellipse(xc, yc, endangle+90, stangle+90, b, a);
    }
    else{
        for (int i = stangle; i < endangle; i += 1) { 
            theta = i; 
            int x = a * cos(t * theta) * cos(t * alpha) 
                    + b * sin(t * theta) * sin(t * alpha); 
    
            int y = b * sin(t * theta) * cos(t * alpha) 
                    - a * cos(t * theta) * sin(t * alpha); 
    
            putpixel(xc + x, yc - y, color); 
        }
    }
    
} 

// Using Digital Differentiator line algorithm because it overcomes the limitation of slope although it is inefficient.
void ddaLine(float x1, float y1, float x2, float y2){
    float dy, dx, p, xn, yn;
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

// Flood Fill algorithm for filling colours depending on the colour of the background.

void ff4(int x, int y, int oc, int nc){
    if(getpixel(x,y) == oc){
        putpixel(x,y,nc);
        ff4(x, y+1, oc, nc);
        ff4(x-1, y, oc, nc);
        ff4(x, y-1, oc, nc);
        ff4(x+1, y, oc, nc);
    }
    return;
}

/*
 * Boundary Fill algorithm for filling colours depending on the colour
 * of the boundary of the shape.
 */

void bf4(int x, int y, int cc, int nc){
    if(getpixel(x,y) != cc && getpixel(x,y) != nc){        // Boundary color must not match the pixel color.
        putpixel(x,y,nc);
        bf4(x, y+1, cc, nc);
        bf4(x-1, y, cc, nc);
        bf4(x, y-1, cc, nc);
        bf4(x+1, y, cc, nc);
    }
    return;
}

/*
 * Function to generate the heart eyes of the emoticon using the
 * functions defined using the algorithm
 */

void heartEyes(){
    setcolor(4);
    ddaLine((getmaxx()/2)+30, (getmaxy()/2), (getmaxx()/2)+66, (getmaxy()/2)-27);    
    ddaLine((getmaxx()/2)+30, (getmaxy()/2), (getmaxx()/2)+12, (getmaxy()/2)-44);      
    arc((getmaxx()/2)+27, (getmaxy()/2)-43,0,180,15);          
    arc((getmaxx()/2)+53, (getmaxy()/2)-35,310,500,15);
    ddaLine((getmaxx()/2)-30, (getmaxy()/2), (getmaxx()/2)-66, (getmaxy()/2)-27);    
    ddaLine((getmaxx()/2)-30, (getmaxy()/2), (getmaxx()/2)-12, (getmaxy()/2)-44);      
    arc((getmaxx()/2)-53, (getmaxy()/2)-35,15,220,15);         
    arc((getmaxx()/2)-27, (getmaxy()/2)-43,0,180,15);
    floodfill((getmaxx()/2)+30, (getmaxy()/2)-20, 4);
    floodfill((getmaxx()/2)-30, (getmaxy()/2)-20, 4);
    //bf4((getmaxx()/2)+30, (getmaxy()/2)-20, 4, 4);
    //bf4((getmaxx()/2)-30, (getmaxy()/2)-20, 4, 4);
}

// Function for the scaling the heart eyes

void heartEyesS(float sF, int tx, int ty){
    setcolor(4);
    line((getmaxx()/2)+(30*sF)+tx, (getmaxy()/2)-ty, (getmaxx()/2)+(66*sF)+tx, (getmaxy()/2)-(27*sF)-ty);    
    line((getmaxx()/2)+(30*sF)+tx, (getmaxy()/2)-ty, (getmaxx()/2)+(12*sF)+tx, (getmaxy()/2)-(44*sF)-ty);      
    arc((getmaxx()/2)+(27*sF)+tx, (getmaxy()/2)-(43*sF)-ty,0,180,(15*sF));          
    arc((getmaxx()/2)+(53*sF)+tx, (getmaxy()/2)-(35*sF)-ty,310,500,(15*sF));
    line((getmaxx()/2)-(30*sF)+tx, (getmaxy()/2)-ty, (getmaxx()/2)-(66*sF)+tx, (getmaxy()/2)-(27*sF)-ty);    
    line((getmaxx()/2)-(30*sF)+tx, (getmaxy()/2)-ty, (getmaxx()/2)-(12*sF)+tx, (getmaxy()/2)-(44*sF)-ty);      
    arc((getmaxx()/2)-(53*sF)+tx, (getmaxy()/2)-(35*sF)-ty,15,220,(15*sF));         
    arc((getmaxx()/2)-(27*sF)+tx, (getmaxy()/2)-(43*sF)-ty,0,180,(15*sF));
    floodfill((getmaxx()/2)+(30*sF)+tx, (getmaxy()/2)-(20*sF)-ty, 4);
    floodfill((getmaxx()/2)-(30*sF)+tx, (getmaxy()/2)-(20*sF)-ty, 4);
    //bf4((getmaxx()/2)+30, (getmaxy()/2)-20, 4, 4);
    //bf4((getmaxx()/2)-30, (getmaxy()/2)-20, 4, 4);
}

// Function for generating scaled heart eyes with different color

void heartEyesC(float sF, int tx, int ty, int color){
    setcolor(color);
    line((getmaxx()/2)+(30*sF)+tx, (getmaxy()/2)-ty, (getmaxx()/2)+(66*sF)+tx, (getmaxy()/2)-(27*sF)-ty);    
    line((getmaxx()/2)+(30*sF)+tx, (getmaxy()/2)-ty, (getmaxx()/2)+(12*sF)+tx, (getmaxy()/2)-(44*sF)-ty);      
    arc((getmaxx()/2)+(27*sF)+tx, (getmaxy()/2)-(43*sF)-ty,0,180,(15*sF));          
    arc((getmaxx()/2)+(53*sF)+tx, (getmaxy()/2)-(35*sF)-ty,310,500,(15*sF));
    line((getmaxx()/2)-(30*sF)+tx, (getmaxy()/2)-ty, (getmaxx()/2)-(66*sF)+tx, (getmaxy()/2)-(27*sF)-ty);    
    line((getmaxx()/2)-(30*sF)+tx, (getmaxy()/2)-ty, (getmaxx()/2)-(12*sF)+tx, (getmaxy()/2)-(44*sF)-ty);      
    arc((getmaxx()/2)-(53*sF)+tx, (getmaxy()/2)-(35*sF)-ty,15,220,(15*sF));         
    arc((getmaxx()/2)-(27*sF)+tx, (getmaxy()/2)-(43*sF)-ty,0,180,(15*sF));
    floodfill((getmaxx()/2)+(30*sF)+tx, (getmaxy()/2)-(20*sF)-ty, color);
    floodfill((getmaxx()/2)-(30*sF)+tx, (getmaxy()/2)-(20*sF)-ty, color);
    //bf4((getmaxx()/2)+30, (getmaxy()/2)-20, 4, 4);
    //bf4((getmaxx()/2)-30, (getmaxy()/2)-20, 4, 4);
}

// Function to rotate the heart eyes

void heartEyesR(int r){
    float x1, x2, y1, y2, x3, x4, y3, y4, x5, x6, x7, x8, y5, y6, y7, y8, cx1, cx2, cx3, cx4, cy1, cy2, cy3, cy4, bgx1, bgx2, bgy1, bgy2;
    float rx1, rx2, ry1, ry2, rx3, rx4, ry3, ry4, rx5, rx6, rx7, rx8, ry5, ry6, ry7, ry8, rcx1, rcx2, rcx3, rcx4, rcy1, rcy2, rcy3, rcy4, bgrx1, bgrx2, bgry1, bgry2;
    float rr;
    int resr;

    // Assigning the position of each point on the screen with respect to the center of the viewport
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
    bgx1 = (getmaxx()/2)+30;
    bgy1 = (getmaxy()/2)-20;
    bgx2 = (getmaxx()/2)-30;
    bgy2 = (getmaxy()/2)-20;
    if(r < 0){
            // Calculating the change in position of each point depending on the angle of rotation
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
            bgrx1 = (bgx1-getmaxx()/2)*cos(rr) + (bgy1-getmaxy()/2)*sin(rr);
            bgry1 = (bgy1-getmaxy()/2)*cos(rr) - (bgx1-getmaxx()/2)*sin(rr);
            bgrx2 = (bgx2-getmaxx()/2)*cos(rr) + (bgy2-getmaxy()/2)*sin(rr);
            bgry2 = (bgy2-getmaxy()/2)*cos(rr) - (bgx2-getmaxx()/2)*sin(rr);
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
            bgrx1 = (bgx1-getmaxx()/2)*cos(rr) - (bgy1-getmaxy()/2)*sin(rr);
            bgry1 = (bgy1-getmaxy()/2)*cos(rr) + (bgx1-getmaxx()/2)*sin(rr);
            bgrx2 = (bgx2-getmaxx()/2)*cos(rr) - (bgy2-getmaxy()/2)*sin(rr);
            bgry2 = (bgy2-getmaxy()/2)*cos(rr) + (bgx2-getmaxx()/2)*sin(rr);
        }
    setcolor(4);
    line(rx1+getmaxx()/2, ry1+getmaxy()/2, rx2+getmaxx()/2, ry2+getmaxy()/2);    
    line(rx3+getmaxx()/2, ry3+getmaxy()/2, rx4+getmaxx()/2, ry4+getmaxy()/2);      
    arc(rcx1+(getmaxx()/2), rcy1+(getmaxy()/2),-r,180-r,15);          
    arc(rcx2+(getmaxx()/2), rcy2+(getmaxy()/2),310-r,500-r,15);
    line(rx5+getmaxx()/2, ry5+getmaxy()/2, rx6+getmaxx()/2, ry6+getmaxy()/2);    
    line(rx7+getmaxx()/2, ry7+getmaxy()/2, rx8+getmaxx()/2, ry8+getmaxy()/2);      
    arc(rcx3+(getmaxx()/2), rcy3+(getmaxy()/2),15-r,220-r,15);         
    arc(rcx4+(getmaxx()/2), rcy4+(getmaxy()/2),-r,180-r,15);
    setcolor(4);
    bf4(bgrx1+(getmaxx()/2), bgry1+(getmaxy()/2),4, 4);
    bf4(bgrx2+(getmaxx()/2), bgry2+(getmaxy()/2),4, 4);
}

// Function for translating the heart eyes.

void heartEyest(int tx, int ty){
    setcolor(4);
    line((getmaxx()/2)+30+tx, (getmaxy()/2)-ty, (getmaxx()/2)+66+tx, (getmaxy()/2)-27-ty);    
    line((getmaxx()/2)+30+tx, (getmaxy()/2)-ty, (getmaxx()/2)+12+tx, (getmaxy()/2)-44-ty);      
    setcolor(4);
    arc((getmaxx()/2)+27+tx, (getmaxy()/2)-43-ty,0,180,15);          
    arc((getmaxx()/2)+53+tx, (getmaxy()/2)-35-ty,310,500,15);
    line((getmaxx()/2)-30+tx, (getmaxy()/2)-ty, (getmaxx()/2)-66+tx, (getmaxy()/2)-27-ty);    
    line((getmaxx()/2)-30+tx, (getmaxy()/2)-ty, (getmaxx()/2)-12+tx, (getmaxy()/2)-44-ty);      
    arc((getmaxx()/2)-53+tx, (getmaxy()/2)-35-ty,15,220,15);         
    arc((getmaxx()/2)-27+tx, (getmaxy()/2)-43-ty,0,180,15);
    floodfill((getmaxx()/2)+30+tx, (getmaxy()/2)-20-ty, 4);
    floodfill((getmaxx()/2)-30+tx, (getmaxy()/2)-20-ty, 4);
}

/*
 * Generating the mouth of the emoticon using Built-in functions.
 * 
 */

void mouth(){
    setcolor(0);
    ellipse(getmaxx()/2, (getmaxy()/2)+30, 175,360,  60, 40);
    ellipse(getmaxx()/2, (getmaxy()/2)+27, 180,360, 60, 20);
    setcolor(0);
    floodfill((getmaxx()/2)+10,(getmaxy()/2)+50, 0);
    setcolor(4);
    ellipse(getmaxx()/2, (getmaxy()/2)+68, 0, 181, 19, 12);
    ff4((getmaxx()/2)+10,(getmaxy()/2)+60, 0, 4);
}

// Function to translate the mouth 

void moutht(int tx, int ty){
    setcolor(0);
    ellipse((getmaxx()/2)+tx, (getmaxy()/2)+30-ty, 175,360,  60, 40);
    ellipse((getmaxx()/2)+tx, (getmaxy()/2)+27-ty, 180,360, 60, 20);
    setcolor(0);
    floodfill((getmaxx()/2)+10+tx,(getmaxy()/2)+50-ty, 0);
    setcolor(4);
    ellipse((getmaxx()/2)+tx, (getmaxy()/2)+68-ty, 0, 180, 19, 12);
    ff4((getmaxx()/2)+tx+10,(getmaxy()/2)+60-ty, 0, 4);
}

// Function to scale the mouth

void mouthS(float sF, int tx, int ty){
    setcolor(0);
    ellipse((getmaxx()/2)+tx, (getmaxy()/2)+(30*sF)-ty, 175,360, (60*sF), (40*sF));
    ellipse((getmaxx()/2)+tx, (getmaxy()/2)+(27*sF)-ty, 180,360, (60*sF), (20*sF));
    setcolor(0);
    floodfill((getmaxx()/2)+(10*sF)+tx,(getmaxy()/2)+(50*sF)-ty, 0);
    setcolor(4);
    ellipse((getmaxx()/2)+tx, (getmaxy()/2)+(68*sF)-ty, 0, 180, (19*sF), (12*sF));
    ff4((getmaxx()/2)+tx+(10*sF),(getmaxy()/2)+(60*sF)-ty,0, 4);
}

// Function to rotate the mouth

void mouthr(int r){
    int resr;
    float rr, rx1, ry1, rx2, ry2, rx3, ry3, x1, y1, x2, y2, x3, y3, bgx1, bgx2, bgy1, bgy2, bgrx1, bgrx2, bgry1, bgry2;
    x1 = getmaxx()/2;
    y1 = (getmaxy()/2)+30;
    x2 = getmaxx()/2;
    y2 = (getmaxy()/2)+27;
    x3 = getmaxx()/2;
    y3 = (getmaxy()/2)+68;
    bgx1 = (getmaxx()/2)+10;
    bgy1 = (getmaxy()/2)+50;
    bgx2 = (getmaxx()/2)+10;
    bgy2 = (getmaxy()/2)+60;
    resr = 360 - r;
    if(r < 0){
            rr = resr*(M_PI/180);
            rx1 = (x1-getmaxx()/2)*cos(rr) + (y1-getmaxy()/2)*sin(rr);
            ry1 = (y1-getmaxy()/2)*cos(rr) - (x1-getmaxx()/2)*sin(rr);
            rx2 = (x2-getmaxx()/2)*cos(rr) + (y2-getmaxy()/2)*sin(rr);
            ry2 = (y2-getmaxy()/2)*cos(rr) - (x2-getmaxx()/2)*sin(rr);
            rx3 = (x3-getmaxx()/2)*cos(rr) + (y3-getmaxy()/2)*sin(rr);
            ry3 = (y3-getmaxy()/2)*cos(rr) - (x3-getmaxx()/2)*sin(rr);
            bgrx1 = (bgx1-getmaxx()/2)*cos(rr) + (bgy1-getmaxy()/2)*sin(rr);
            bgry1 = (bgy1-getmaxy()/2)*cos(rr) - (bgx1-getmaxx()/2)*sin(rr);
            bgrx2 = (bgx2-getmaxx()/2)*cos(rr) + (bgy2-getmaxy()/2)*sin(rr);
            bgry2 = (bgy2-getmaxy()/2)*cos(rr) - (bgx2-getmaxx()/2)*sin(rr);
        }else{
            rr = r*(M_PI/180);
            rx1 = (x1-getmaxx()/2)*cos(rr) - (y1-getmaxy()/2)*sin(rr);
            ry1 = (y1-getmaxy()/2)*cos(rr) + (x1-getmaxx()/2)*sin(rr);
            rx2 = (x2-getmaxx()/2)*cos(rr) - (y2-getmaxy()/2)*sin(rr);
            ry2 = (y2-getmaxy()/2)*cos(rr) + (x2-getmaxx()/2)*sin(rr);
            rx3 = (x3-getmaxx()/2)*cos(rr) - (y3-getmaxy()/2)*sin(rr);
            ry3 = (y3-getmaxy()/2)*cos(rr) + (x3-getmaxx()/2)*sin(rr);
            bgrx1 = (bgx1-getmaxx()/2)*cos(rr) - (bgy1-getmaxy()/2)*sin(rr);
            bgry1 = (bgy1-getmaxy()/2)*cos(rr) + (bgx1-getmaxx()/2)*sin(rr);
            bgrx2 = (bgx2-getmaxx()/2)*cos(rr) - (bgy2-getmaxy()/2)*sin(rr);
            bgry2 = (bgy2-getmaxy()/2)*cos(rr) + (bgx2-getmaxx()/2)*sin(rr);
        }
    drawEllipse(rx1+getmaxx()/2, ry1+(getmaxy()/2), 175,360,  60, 40, resr, 0);
    drawEllipse(rx2+getmaxx()/2, ry2+(getmaxy()/2), 180,360, 60, 20, resr, 0);
    setcolor(0);
    ff4(bgrx1+(getmaxx()/2), bgry1+(getmaxy()/2), 14,0);
    drawEllipse(rx3+getmaxx()/2, ry3+(getmaxy()/2), 0, 181, 19, 12, resr, 4);
    setcolor(4);
    ff4(bgrx2+(getmaxx()/2), bgry2+(getmaxy()/2), 0, 4);
    //ff4((getmaxx()/2)+10,(getmaxy()/2)+50, 14, 0);
    //ff4((getmaxx()/2)+10,(getmaxy()/2)+60, 14, 4);
}

// Function for generating mindBlown Emoticon

void mindBlownEmoji(){
//putpixel((getmaxx()/2)+60, (getmaxy()/2)+70, COLOR(54,34,23));
        setcolor(14);
        ellipse(getmaxx()/2, getmaxy()/2, 150, 390, 100, 100);
        setcolor(14);
        ellipse(getmaxx()/2, getmaxy()/2-50, 0, 360, 87, 8);
        setcolor(14);
        ellipse(getmaxx()/2, getmaxy()/2-46, 0, 180, 70, 6);
        floodfill(getmaxx()/2, getmaxy()/2, 14);
        floodfill(getmaxx()/2, getmaxy()/2-55, 14);
        setcolor(RED);
        /* line(getmaxx()/2-70, getmaxy()/2-46, getmaxx()/2-70, getmaxy()/2-130);
        line(getmaxx()/2+70, getmaxy()/2-46, getmaxx()/2+70, getmaxy()/2-130); */
        ellipse(getmaxx()/2-55, getmaxy()/2-85, 300, 420,20, 48);
        ellipse(getmaxx()/2+55, getmaxy()/2-89, 118, 245,20, 50);
        ellipse(getmaxx()/2-45, getmaxy()/2-85, 290, 425,20, 44);
        ellipse(getmaxx()/2+45, getmaxy()/2-90, 96, 260,20, 48);
        setcolor(7);
        arc(getmaxx()/2-70, getmaxy()/2-150, 155, 300, 20);
        arc(getmaxx()/2-75, getmaxy()/2-175, 120, 250, 20);
        arc(getmaxx()/2-60, getmaxy()/2-190, 20, 180, 25);
        arc(getmaxx()/2-20, getmaxy()/2-195, 10, 160, 20);
        arc(getmaxx()/2+30, getmaxy()/2-185, 20, 150, 40);
        arc(getmaxx()/2+60, getmaxy()/2-180, 320, 460, 40);
        arc(getmaxx()/2-40, getmaxy()/2-150, 180, 330, 25);
        arc(getmaxx()/2+10, getmaxy()/2-150, 200, 350, 30);
        arc(getmaxx()/2+64, getmaxy()/2-158, 210, 360, 30);
        ff4(getmaxx()/2, getmaxy()/2-180, 0, 15);
        ff4(getmaxx()/2-28, getmaxy()/2-85, 0, 4);
        ff4(getmaxx()/2-35, getmaxy()/2-50,0, 4);
        ff4(getmaxx()/2-33, getmaxy()/2-55,14, 4);
        ff4(getmaxx()/2+28, getmaxy()/2-85, 0,4);
        ff4(getmaxx()/2+37, getmaxy()/2-50, 0,4);
        ff4(getmaxx()/2+35, getmaxy()/2-55, 14,4);
        ff4(getmaxx()/2+20, getmaxy()/2-90,0,14);
        ff4(getmaxx()/2+20, getmaxy()/2-50,0,14);
        setcolor(BLACK);
        circle(getmaxx()/2+45, getmaxy()/2-10, 15);
        ff4(getmaxx()/2+45, getmaxy()/2-10, 14, 0);
        circle(getmaxx()/2-45, getmaxy()/2-10, 15);
        ff4(getmaxx()/2-45, getmaxy()/2-10, 14, 0);
        circle(getmaxx()/2, getmaxy()/2+50, 25);
        ff4(getmaxx()/2, getmaxy()/2+50, 14, 0);
        setcolor(WHITE);
        arc(getmaxx()/2, getmaxy()/2+50, 0, 180, 20);
        line(getmaxx()/2-20, getmaxy()/2+50, getmaxx()/2+20, getmaxy()/2+50);
        ff4(getmaxx()/2-10, getmaxy()/2+40,0, 15);
}

// Function to generate the kissing emoji

void kissEmoji(){
    setcolor(14);
    circle(getmaxx()/2, getmaxy()/2, 100);
    floodfill((getmaxx()/2)+10, (getmaxy()/2)+10, 14);
    setcolor(0);
    ellipse((getmaxx()/2)-35, (getmaxy()/2)-20, 0,360,  10, 20);
    //putpixel((getmaxx()/2)-35, (getmaxy()/2)-20, BLACK);
    floodfill((getmaxx()/2)-35, (getmaxy()/2)-20, 0);
    ellipse((getmaxx()/2)+35, (getmaxy()/2)-10, 0,180,  25, 15);
    ellipse((getmaxx()/2)+35, (getmaxy()/2)-10, 10,170,  25, 5);
    floodfill((getmaxx()/2)+35, (getmaxy()/2)-20, 0);
    ellipse((getmaxx()/2), (getmaxy()/2)+40, 270, 450, 20, 10);
    ellipse((getmaxx()/2), (getmaxy()/2)+40, 270, 450, 13, 10);
    ellipse((getmaxx()/2)+12, (getmaxy()/2)+49, 180, 270, 12, 6);
    ellipse((getmaxx()/2)+12, (getmaxy()/2)+49, 180, 270, 12, 11);
    ellipse((getmaxx()/2)+10, (getmaxy()/2)+63, 220, 450, 11, 8);
    ellipse((getmaxx()/2)+10, (getmaxy()/2)+65, 215, 450, 8, 6);
    floodfill((getmaxx()/2)+15, (getmaxy()/2)+40, 0);
    //putpixel((getmaxx()/2)+15, (getmaxy()/2)+57, RED);
    floodfill((getmaxx()/2)+15, (getmaxy()/2)+57, 0);
    //putpixel((getmaxx()/2)+40, (getmaxy()/2)+70, RED);
    setcolor(4);
    line((getmaxx()/2)+60, (getmaxy()/2)+70, (getmaxx()/2)+93, (getmaxy()/2)+53);    
    line((getmaxx()/2)+60, (getmaxy()/2)+70, (getmaxx()/2)+50, (getmaxy()/2)+23);      
    arc((getmaxx()/2)+65, (getmaxy()/2)+25,0, 180, 15);
    arc((getmaxx()/2)+86, (getmaxy()/2)+40,300, 480, 15);
    floodfill((getmaxx()/2)+65, (getmaxy()/2)+20, 4);
}

// Function for animating the emoticon. Scaling up and down the heart eyes of the emoticon

void animate(){
    cleardevice();
    setcolor(14);
    circle(getmaxx()/2, getmaxy()/2, 100); 
    floodfill(getmaxx()/2, getmaxy()/2, 14);
    mouth();
    for(int s = 0; s < 10; s++){
        for(float i = 0.8; i <= 1.2; i+=0.1){
            heartEyesC(i, 0, 0, 4);
            delay(100);
            heartEyesC(i, 0, 0, 14);
            delay(100);
        }
        delay(10);
        for(float j = 1.2; j >= 0.8; j-=0.1){
            heartEyesC(j, 0, 0, 4);
            delay(100);
            heartEyesC(j, 0, 0, 14);
            delay(100);
        }
    }

    heartEyesC(0.8, 0, 0, 4);
    
}

// Function that makes the output menu driven. 

void options(){
    int choice=0;
    printf("\tPlease select from the following options: \n");
    printf("\t1. Heart Eyes Emoji\n");
    printf("\t2. Kiss Emoji\n");
    printf("\t3. Volcano Head Emoji\n");
    printf("\t4. Exit\n");
    printf("\n>>\t");
    scanf("%d", &choice);
    
    
    int gd = X11, gm=X11_1024x768;
    int tc, tx, ty, rx, ry, r, sx, sy, rr;
    float tS;
    switch(choice){
        case 1: {
                initgraph(&gd, &gm, "");
                setcolor(14);
                circle(getmaxx()/2, getmaxy()/2, 100); // Function using Bresenhams Algorithm for generating circle.
                floodfill(getmaxx()/2, getmaxy()/2, 14);
                heartEyes();    // Generate the heart eyes for the emoticon using the Bresenhams Algorithm and DDA
                mouth();    // Generate the mouth of emoticon using Built-In Functions
                getch();
                //closegraph();
                printf("\tTransformations for this emoji\n");
                printf("\t1. Translate\n");
                printf("\t2. Rotate\n");
                printf("\t3. Scale\n");
                printf("\t4. Animate\n");
                printf(">>\t");
                scanf("%d", &tc);
                switch(tc){
                    case 1: {
                        printf("Enter the translation: ");
                        scanf("%d %d", &tx, &ty);
                        //initgraph(&gd, &gm, "");
                        setcolor(14);
                        circle(getmaxx()/2+tx, getmaxy()/2-ty, 100);
                        floodfill(getmaxx()/2+tx, getmaxy()/2-ty,14);
                        heartEyest(tx, ty);
                        moutht(tx, ty);
                        getch();
                        //closegraph();
                    }break;
                    case 2:{
                        printf("Enter the rotation angle: ");
                        scanf("%d", &r);
                        cleardevice();
                        setcolor(14);
                        circle((getmaxx()/2), (getmaxy()/2), 100); // Function using Bresenhams Algorithm for generating circle.
                        floodfill(getmaxx()/2, getmaxy()/2, 14);
                        heartEyesR(r);    // Generate the heart eyes for the emoticon using the Bresenhams Algorithm and DDA
                        mouthr(r);    // Generate the mouth of emoticon using Built-In Functions
                        
                    }break;
                    case 3:{
                        printf("Enter the scale(Not more than 2): ");
                        scanf("%f", &tS);
                        setcolor(14);
                        circle((getmaxx()/2)+200, (getmaxy()/2)-200, (100*tS)); // Function using Bresenhams Algorithm for generating circle.
                        floodfill((getmaxx()/2)+200, (getmaxy()/2)-200, 14);
                        heartEyesS(tS, 200, 200);
                        mouthS(tS, 200, 200);
                    }break;
                    case 4:{
                        cleardevice();
                        outtextxy((getmaxx()/2), (getmaxy()/2), "Get ready for the animation");
                        delay(2000);
                        cleardevice();
                        animate();
                    }break;
                    
                }
                options();
        }break;
        case 2: {
            initgraph(&gd, &gm, "");
            kissEmoji();
            getch();
            closegraph();
            options();
        }break;
        case 3: {


            initgraph(&gd, &gm, "");
            mindBlownEmoji();
            getch();
            closegraph();
            options();
        }break;
        case 4: {
            return;
        }break;
    }
}

 void main(){
    printf("Assignment 2: Drawing an Emoticon using Built-In Functions and Algorithms\nAuthor: Mihir Srivastava\nDated: 26/07/2019\n----------------------------------------------------------------------------------------------------\n\n");
    options();

    //getch();
    //closegraph();
 }
