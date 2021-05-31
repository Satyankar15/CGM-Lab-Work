#include<iostream.h>
#include<graphics.h>
#include<conio.h>
void drawcircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
	putpixel(x0 + x, y0 + y, 7);
	putpixel(x0 + y, y0 + x, 7);
	putpixel(x0 - y, y0 + x, 7);
	putpixel(x0 - x, y0 + y, 7);
	putpixel(x0 - x, y0 - y, 7);
	putpixel(x0 - y, y0 - x, 7);
	putpixel(x0 + y, y0 - x, 7);
	putpixel(x0 + x, y0 - y, 7);

	if (err <= 0)
	{
	    y += 1;
	    err += 2*y + 1;
	}

	if (err > 0)
	{
	    x -= 1;
	    err -= 2*x + 1;
	}
    }
}

int main()
{
	clrscr();
	int gdriver=DETECT, gmode, error, x=100, y=100, r=25;
	initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
	drawcircle(x, y, r);
	getch();
	return 0;
}
