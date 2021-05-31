#include<graphics.h>
#include<conio.h>
int main()
{       clrscr();
	int gd= DETECT, gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	circle(250,200,50);
	getch();
	closegraph();
	return 0;
}