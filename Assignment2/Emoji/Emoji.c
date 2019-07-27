/*
 * Assignment 2: Creating a emoticon using Built-in Graphics.h functions and functions defined using algorithms
 * Author: Mihir Srivastava
 * Selected Emoticon: Heart Eyes Emoticon
 */

#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<X11/Xlib.h>

// Declaring fill functions so that they can be used throughout the code.
 
void ff4(int x, int y, int oc, int nc);
void bf4(int x, int y, int cc, int nc);

// To Draw the arcs of the heart eyes in the emoticon.
void heartArc1(int x, int y, int r){
    int xNext, yNext, p;
    
    p = 3 - 2*r;
    
    yNext = r;
    
    for(xNext = 0; xNext <= yNext; xNext++){
        putpixel(xNext+x, -yNext+y, RED);
        putpixel(-xNext+x, -yNext+y, RED);
        putpixel(yNext+x, -xNext+y, RED);
        putpixel(-yNext+x, -xNext+y, RED); 
        if(p < 0){
            p+=(4*xNext+6);
        }else{
            yNext--;
            p+=(4*xNext-4*yNext+10);
        }
    }
}

void heartArc2(int x, int y, int r){
    int xNext, yNext, p;
    
    p = 3 - 2*r;
    
    yNext = r;
    
    for(xNext = 0; xNext <= yNext; xNext++){
        putpixel(xNext+x, -yNext+y, RED);
        putpixel(-xNext+x, -yNext+y, RED);
        putpixel(yNext+x, xNext+y, RED);
        putpixel(yNext+x, -xNext+y, RED);
        if(p < 0){
            p+=(4*xNext+6);
        }else{
            yNext--;
            p+=(4*xNext-4*yNext+10);
        }
    }
}

void heartArc3(int x, int y, int r){
    int xNext, yNext, p;
    
    p = 3 - 2*r;
    
    yNext = r;
    
    for(xNext = 0; xNext <= yNext; xNext++){
        putpixel(xNext+x, -yNext+y, RED);
        putpixel(-xNext+x, -yNext+y, RED);
        putpixel(-yNext+x, xNext+y, RED);
        putpixel(-yNext+x, -xNext+y, RED); 
        if(p < 0){
            p+=(4*xNext+6);
        }else{
            yNext--;
            p+=(4*xNext-4*yNext+10);
        }
    }
}

void heartArc4(int x, int y, int r){
    int xNext, yNext, p;
    
    p = 3 - 2*r;
    
    yNext = r;
    
    //putpixel(x, y, RED);
    
    for(xNext = 0; xNext <= yNext; xNext++){
        putpixel(xNext+x, -yNext+y, RED);
        putpixel(-xNext+x, -yNext+y, RED);
        putpixel(yNext+x, -xNext+y, RED);
        putpixel(-yNext+x, -xNext+y, RED); 
        if(p < 0){
            p+=(4*xNext+6);
        }else{
            yNext--;
            p+=(4*xNext-4*yNext+10);
        }
    }
}

// Using Bresenham's Circle Drawing Algorithm to draw the outside circle of the emoji. 

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
    bf4((getmaxx()/2)+10, (getmaxy()/2)+10, 14, 14);
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
    ddaLine((getmaxx()/2)+30, (getmaxy()/2), (getmaxx()/2)+66, (getmaxy()/2)-27);    
    ddaLine((getmaxx()/2)+30, (getmaxy()/2), (getmaxx()/2)+12, (getmaxy()/2)-44);      
    heartArc1((getmaxx()/2)+27, (getmaxy()/2)-43,15);          
    heartArc2((getmaxx()/2)+53, (getmaxy()/2)-35,15);
    ddaLine((getmaxx()/2)-30, (getmaxy()/2), (getmaxx()/2)-66, (getmaxy()/2)-27);    
    ddaLine((getmaxx()/2)-30, (getmaxy()/2), (getmaxx()/2)-12, (getmaxy()/2)-44);      
    heartArc3((getmaxx()/2)-53, (getmaxy()/2)-35,15);         
    heartArc4((getmaxx()/2)-27, (getmaxy()/2)-43,15);
    bf4((getmaxx()/2)+30, (getmaxy()/2)-20, 4, 4);
    bf4((getmaxx()/2)-30, (getmaxy()/2)-20, 4, 4);
}

/*
 * Function to generate the heart eyes of the emoticon using the
 * built in functions of the library. 
 * 
 */

void heartEyesnB(){
    setcolor(4);
    line((getmaxx()/2)+30, (getmaxy()/2), (getmaxx()/2)+66, (getmaxy()/2)-27);    
    line((getmaxx()/2)+30, (getmaxy()/2), (getmaxx()/2)+12, (getmaxy()/2)-44);      
    arc((getmaxx()/2)+27, (getmaxy()/2)-43,0, 180, 15);
    arc((getmaxx()/2)+53, (getmaxy()/2)-35,-33, 140,  15);
    line((getmaxx()/2)-30, (getmaxy()/2), (getmaxx()/2)-66, (getmaxy()/2)-27);    
    line((getmaxx()/2)-30, (getmaxy()/2), (getmaxx()/2)-12, (getmaxy()/2)-44);      
    arc((getmaxx()/2)-53, (getmaxy()/2)-34, 33, 210 , 15);
    arc((getmaxx()/2)-27, (getmaxy()/2)-43, 0,180, 15);
    
    bf4((getmaxx()/2)+30, (getmaxy()/2)-20, 4, 4);
    bf4((getmaxx()/2)-30, (getmaxy()/2)-20, 4, 4);
}

/*
 * Generating the mouth of the emoticon using Built-in functions.
 * 
 */

void mouth(){
    setcolor(0);
    ellipse(getmaxx()/2, (getmaxy()/2)+30, 175,360,  60, 40);
    ellipse(getmaxx()/2, (getmaxy()/2)+27, 180,360, 60, 20);
    setcolor(4);
    ellipse(getmaxx()/2, (getmaxy()/2)+68, 0, 180, 20, 12);
    ff4((getmaxx()/2)+10,(getmaxy()/2)+50, 14, 0);
    ff4((getmaxx()/2)+10,(getmaxy()/2)+60, 14, 4);
}

void options(){
    int choice=0;
    printf("\tPlease select from the following options: \n");
    printf("\t1. Heart Eyes Emoji");
    printf("\t2. Kiss Emoji");
    printf("\t3. Volcano Head Emoji");
    printf("\t4. Exit");
    printf("\n>>\t");
    scanf("%d", &choice);
    
    
    int gd = X11, gm=VGAMED;
    switch(choice){
        case 1: {
            int c;
            printf("\n-------------------------------------------------------\n");
            printf("\t\t1. Using Algorithms");
            printf("\t\t2. Using the Built-In Functions");
            printf("\n>>\t");
            scanf("%d", &c);
            switch(c){
                case 1: {
                    initgraph(&gd, &gm, "");
                    outerCircle(getmaxx()/2, getmaxy()/2, 100); // Function using Bresenhams Algorithm for generating circle.
                    heartEyes();    // Generate the heart eyes for the emoticon using the Bresenhams Algorithm and DDA
                    mouth();    // Generate the mouth of emoticon using Built-In Functions
                    getch();
                    closegraph();
                    options();
                }break;
                case 2: {
                    initgraph(&gd, &gm, "");
                    setcolor(14);
                    circle(getmaxx()/2, getmaxy()/2, 100);      // Using the Built-In Circle method to generate the outer circle
                    bf4((getmaxx()/2)+10, (getmaxy()/2)+10, 14, 14);
                    heartEyesnB();      // Generating the Heart Eyes of the emoticon using the arc method and line method. 
                    mouth();        // Using the same mouth method as above.
                    getch();
                    closegraph();
                    options();
                }break;
            }
        }break;
        case 2: {
            initgraph(&gd, &gm, "");
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
            getch();
            closegraph();
            options();
        }break;
        case 3: {
            // Volcano Head Emoji
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
