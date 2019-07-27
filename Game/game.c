// Scroll key tester
#include<stdlib.h>
#include<stdio.h>
#include "/usr/include/graphics.h"
int main()
{
int ch1, ch2;
printf("PRESS A KEY TO CONTINUE \n");
ch1 = getch();
ch2 = 0;
if (ch1 == 0xE0) { // a scroll key was pressed
ch2 = getch();
// determine what it was
switch(ch2)
{
case 72: printf("UP WAS PRESSED\n"); break;
case 80: printf("DOWN WAS PRESSED\n"); break;
case 75: printf("LEFT WAS PRESSED\n"); break;
case 77: printf("RIGHT WAS PRESSED\n"); break;
// ... we can set also others like HOME, END, PGUP, PGDOWN, ...
default:
printf("SOME OTHER SCROLL KEY PRESSED: %d %d\n", ch1, ch2); break;
};
}
else
printf("key pressed: %d %c\n", ch1, ch2);
system("pause");
return 0;
}