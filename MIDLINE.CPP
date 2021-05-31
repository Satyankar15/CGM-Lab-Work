#include<graphics.h>
#include<conio.h>
#include<stdio.h>
void midPoint(int x1, int y1, int x2, int y2)
{       int gd=DETECT, gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	int dx=x2-x1;
	int dy=y2-y1;
	if(dy<=dx)
	{
		int d = dy-(dx/2);
		int x= x1, y=y1;
		putpixel(x,y,GREEN);
		while(x<x2)
		{
			x++;
			if(d<0)
				d=d+dy;
			else
			{
				d=d+(dy-dx);
				y++;
			}
			putpixel(x,y,GREEN);
		}
      /*	while(y<y2)
	{
		x++;
		if(d<0)
			d=d+dy;
		else
		{
			d=d+(dy-dx);
			y++;
		}
	}
	}

	else if(dx<dy)
	{
		int d=dx-(dy/2);
		int x=x1, y=y1;

		while(y<y2)
		{
			y++;

			if(d<0)
				d=d+dx;
		}
	} */
	}
}

	int main()
	{
		int x1=20, y1=15, x2=400, y2=100;
		midPoint(x1,y1,x2,y2);
		getch();
		return 0;
	}