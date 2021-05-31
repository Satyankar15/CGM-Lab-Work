#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void drawCircle(int x, int y, int xc, int yc);
void main()
{
	int gd = DETECT, gm;
	int r=50, xc=100, yc=100, pk, x, y;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	pk = 3 - 2*r;
	x=0; y = r;
	drawCircle(x,y,xc,yc);
	while(x < y)
	{
		if(pk <= 0)
		{
			pk = pk + (4*x) + 6;
			drawCircle(++x,y,xc,yc);
		}
		else
		{
			pk = pk + (4*(x-y)) + 10;
			drawCircle(++x,--y,xc,yc);
		}
	}

	getch();
	closegraph();
}

void drawCircle(int x, int y, int xc, int yc)
{
	putpixel(x+xc,y+yc,9);
	putpixel(-x+xc,y+yc,9);
	putpixel(x+xc, -y+yc,9);
	putpixel(-x+xc, -y+yc,9);
	putpixel(y+xc, x+yc, 9);
	putpixel(y+xc, -x+yc, 9);
	putpixel(-y+xc, x+yc, 9);
	putpixel(-y+xc, -x+yc, 9);
}
