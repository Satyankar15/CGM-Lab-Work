#include<graphics.h>
#include<iostream.h>
#include<conio.h>
int main()
{
	clrscr();
	int x1,x2,y1,y2;
	cout<<"Enter first coordinates "<<endl;
	cin>>x1>>y1;
	cout<<"Enter second coordinates "<<endl;
	cin>>x2>>y2;
	int x=x1,y=y1;
	int gd= DETECT, gmode;
	initgraph(&gd,&gmode,"C://TURBOC3//BGI");
	int dx=x2-x1;
	int dy=y2-y1;
	putpixel(x1,y1,RED);
	putpixel(x2,y2,RED);
       //cout<<"dx = "<<dx;
       // cout<<" dy = "<<dy;
	if(dx>=dy)
	{
		int P=2*dy-dx;
		while(x<=x2)
		{
			putpixel(x,y,WHITE);
			if(P<0)
			{       x++;
				P=P+2*dy;
			}
			else
			{
			P=P+2*dy-2*dx;
			y++;
			}
		}
	}
	else
	{
		int P=2*dx-dy; //dy>dx
		while(y<=y2)
		{
			putpixel(x,y,WHITE);
			if(P<0)
			{       y++;
				P=P+2*dx;
			}
			else
			{
			P=P+2*dx-2*dy;
			x++;
			}
		}
	}

	putpixel(x1,y1,RED);
	putpixel(x2,y2,RED);
	cout<<"("<<x1<<","<<y1<<") ("<<x2<<","<<y2<<")"<<endl;
	getch();
	return 0;
}

