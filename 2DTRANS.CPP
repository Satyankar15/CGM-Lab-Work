#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void drawline(float x[], float y[], int color)
{       setcolor(color);
	line(x[0],y[0],x[1],y[1]);
	line(x[1],y[1],x[0],y[0]);
	//line(x[2],y[2],x[3],y[3]);
	//line(x[3],y[3],x[0],y[0]);
}
void main()
{       clrscr();
	int gd=DETECT,gm ;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	float x[4],y[4];
	int choice,flag=1;
	for(int i=0;i<2;i++)
	{
		cout<<"Enter x and y coordinates number "<<i+1<<endl;
		cin>>x[i]>>y[i];
	}
	    line(x[0],y[0],x[1],y[1]);
	     cout<<"1.Translation"<<endl;
	     cout<<"2.Scaling"<<endl;
	     cout<<"3.Rotation"<<endl;
	    cout<<"Enter your choice"<<endl;
	    while(flag)
	    {
	     cin>>choice;
	     switch(choice)
	     {
		case 1:
		{
			int tx,ty;
			cout<<"Enter tx and ty"<<endl;
			cin>>tx>>ty;
			for(int i=0;i<2;i++)
			{
				x[i]=x[i]+tx;
				y[i]=y[i]+ty;
				cout<<x[i]<<","<<y[i]<<endl;
			}
			drawline(x,y,4);
			break;
		}
		case 2:
		{
			float sx,sy;
			cout<<"Enter sx and sy"<<endl;
			cin>>sx>>sy;
			for(int i=0;i<2;i++)
			{       cout<<"Multiplying"<<endl;
				x[i]=x[i]*sx;
				y[i]=y[i]*sy;
				cout<<x[i]<<","<<y[i]<<endl;
			}
			drawline(x,y,10);
			break;
		}
		case 3:
		{
			int theta, xpivot, ypivot;
			cout<<"Enter xpivot and ypivot"<<endl;
			cin>>xpivot>>ypivot;
			cout<<"Enter angle to rotate by"<<endl;
			cin>>theta;
			int xshifted=x[0]-xpivot;
			int yshifted=y[0]-ypivot;
			x[0]=xpivot+(xshifted*cos(theta) -yshifted*sin(theta));
			y[0]=ypivot+(xshifted*sin(theta)+yshifted*cos(theta));
			xshifted=x[1]-xpivot;
			yshifted=y[1]-ypivot;
			x[1]=xpivot+(xshifted*cos(theta) -yshifted*sin(theta));
			y[1]=ypivot+(xshifted*sin(theta)+yshifted*cos(theta));
			drawline(x,y,9);
			cout<<x[0]<<" "<<y[0];
			break;
		}
	    default:{ flag=0;}
	}
	//getch();
}
}


