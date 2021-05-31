#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	int x1,y1,x2,y2,xmax,xmin,ymax,ymin;
	int xx1, yy1, xx2, yy2, dx, dy;
	int p[4],q[4];
	float t1,t2,t[4];
	cout<<"Enter the bottom left coordinates of window"<<endl;
	cin>>xmin>>ymin;
	cout<<"Enter the top right coordinates of the window"<<endl;
	cin>>xmax>>ymax;
	rectangle(xmin,ymin,xmax,ymax);
	cout<<"Enter x1, y1"<<endl;
	cin>>x1>>y1;
	cout<<"Enter x2,y2"<<endl;
	cin>>x2>>y2;
	line(x1,y1,x2,y2);
	dx=x2-x1;
	dy=y2-y1;
	p[0]=-dx;
	p[1]=dx;
	p[2]=-dy;
	p[3]=dy;
	q[0]=x1-xmin;
	q[1]=xmax-x1;
	q[2]=y1-ymin;
	q[3]=ymax-y1;
	for(int i=0;i<4;i++)
	{
		if(p[i]!=0)
			t[i]=(float)q[i]/p[i];
		else if(p[i]==0 && q[i]<0)
			cout<<"Line outside of window"<<endl;
		else if(p[i]==0 && q[i]>=0)
			cout<<"Line completely inside of the window"<<endl;
	}
	if(t[0]>t[2])
		t1=t[0];
	else
		t1=t[2];
	if(t[1]<t[3])
		t2=t[1];
	else
		t2=t[3];
	if(t1<t2)
	{
		xx1=x1+t1*dx;
		xx2=x1+t2*dx;
		yy1=y1+t1*dy;
		yy2=y1+t2*dy;
		cout<<"Line after clipping"<<endl;
		setcolor(YELLOW);
		line(xx1,yy1,xx2,yy2);
	}
	else
		cout<<"Line is outside of window"<<endl;
	getch();
}