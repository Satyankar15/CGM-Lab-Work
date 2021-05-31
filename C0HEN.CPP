#include<iostream>
#include<conio.h>
using namespace std;
int in=0;
int Left=1;
int Right=2;
int bottom=4;
int top=8;
int x_max=7;
int x_min=3;
int y_max=10;
int y_min= 5;
int Region(int x, int y)
{
	int region=0;
	if(x<x_min)
		region|=Left;
	else if(x>x_max)
		region|=Right;

	if(y<y_min)
		region|=bottom;
	else if(y>y_max)
		region|=top;

	return region;
}

void cohenSuther(int x1, int y1, int x2, int y2)
{
	int region1=Region(x1,y1);
	int region2=Region(x2,y2);
	int flag=0;
	while(1)
	{
		if((region1==0)&&(region2==0))
		{
			flag=1;
			break;
		}
		else if((region1!=0)||(region2!=0))
			break;
		else
		{
			int region_out;
			int x,y;
			if(region1!=0)
				region_out=region1;
			else
				region_out=region2;

			if(region_out & top)
			{
				x=x1+(x2-x1)*(y_max-y1)/(y2-y1);
				y=y_max;
			}
			else if(region_out & bottom)
			{
				x=x1+(x2-x1)*(y_min-y1)/(y2-y1);
				y=y_min;
			}
			else if(region_out & Right)
			{
				y=y1+(y2-y1)*(x_max-x1)/(x2-x1);
				x=x_max;
			}
			else if(region_out & Left)
			{
				y=y1+(y2-y1)*(x_max-x1)/(x2-x1);
				x=x_max;
			}
			else if(region_out & Left)
			{
				y=y1+(y2-y1)*(x_min-x1)/(x2-x1);
				x=x_min;
			}
			if(region_out == region1)
			{
				x1=x;
				y1=y;
				region1=Region(x1,y1);
			}
			else
			{
				x2=x;
				y2=y;
				region2=Region(x2,y2);
			}
		}
	}
	if(flag)
		cout<<"Accepted from ("<<x1<<","<<y1<<") to ("<<x2<<","<<y2<<")"<<endl;
	else
		cout<<"Line rejected"<<endl;
}

int main()
{
	cohenSuther(4,5,6,6);
	cohenSuther(7,6,5,4);
	getch();
}
