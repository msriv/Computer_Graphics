
#include "graphics.h"

#include <stdio.h>      // Provides sprintf

  #define KEY_UP         82

  #define KEY_LEFT       81

  #define KEY_RIGHT      83

  #define KEY_DOWN       84



void outintxy(int x, int y, int value);



int main( )

{

    int i;

    char c;



    // Initialize the graphics window.

    initwindow(400, 300);



    // Convert some numbers to strings and draw them in graphics window:

    outtextxy(10, 10, "Here are some numbers:");

    for (i = 10; i <= 100; i += 10)

        outintxy(20, i+10, i);



    // Get some characters from the keyboard until an X is typed:

    outtextxy(20, 130, "Click in this graphics window,");

    outtextxy(20, 140, "and then press arrow keys.");

    outtextxy(20, 150, "Watch the console window while pressing.");

    outtextxy(20, 160, "Press X to exit.");

    do

    {

        c = (char) getch();

        if (c != 0)

            outtextxy(20,180,"That is ASCII value: 1");

        else

        {   // Process one of the special keys:

            c = (char) getch();

            switch (c)

            {

                case KEY_UP:      outtextxy(20,170,"Up key."); break;

                case KEY_LEFT:    outtextxy(20,180,"Left key."); break;

                case KEY_RIGHT:   outtextxy(20,190,"Right key."); break;

                case KEY_DOWN:    outtextxy(20,200,"Down key."); break;

                default: printf("Unknown extended key.");

            }

        }

    }   while ((c != 'x') && (c != 'X'));



    closegraph( );

}



void outintxy(int x, int y, int value)

{

   char digit_string[20];

   printf(digit_string, "%d", value);

   outtextxy(x, y, digit_string);

}
