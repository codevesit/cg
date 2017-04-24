#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
int x[10],y[10],xr[10],yr[10],n,i;
float c,a,b;
void scale()
{
	printf("enter the scaling factors \'a\' and \'b\'");
	scanf("%f %f",&a,&b);
	setcolor(RED);
	for(i=0;i<n;i++)
	{
		x[i]*=a;
		y[i]*=b;
	}
	for(i=0;i<n-1;i++)
	{
		line(x[i],y[i],x[i+1],y[i+1]);
	}
	line(x[0],y[0],x[n-1],y[n-1]);
}
void translate()
{
	printf("enter the translation values");
	scanf("%f %f",&a,&b);
	setcolor(BLUE);
	for(i=0;i<n;i++)
	{
		x[i]+=a;
		y[i]+=b;
	}
	for(i=0;i<n-1;i++)
	{
		line(x[i],y[i],x[i+1],y[i+1]);
	}
	line(x[0],y[0],x[n-1],y[n-1]);
}
void rotate()
{
	printf("enter the rotation angle");
	scanf("%f",&c);
	c=3.14*c/180;
	setcolor(GREEN);
	for(i=0;i<n;i++)
	{
		xr[i]=abs(x[i]*cos(c)-y[i]*sin(c));
		yr[i]=abs((1)*x[i]*sin(c)+y[i]*cos(c));
		x[i]=xr[i];
		y[i]=yr[i];
	}
		for(i=0;i<n-1;i++)
	{
		line(x[i],y[i],x[i+1],y[i+1]);
	}
	line(x[0],y[0],x[n-1],y[n-1]);
}
void main()
{
clrscr();
int gd=DETECT,gm,ch=1;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
setfillstyle(SOLID_FILL,WHITE);
bar(0,(getmaxy()-250),getmaxx(),getmaxy());
setcolor(MAGENTA);
printf("enter the number of coordinates");
scanf("%d",&n);
printf("enter the coordinates");
for(i=0;i<n;i++)
{
	printf("x%d y%d is",i+1,i+1);
	scanf("%d %d",&x[i],&y[i]);
}
printf("the initial diagram is\n");
for(i=0;i<n-1;i++)
{
	line(x[i],y[i],x[i+1],y[i+1]);
}
line(x[0],y[0],x[n-1],y[n-1]);
do
{
printf("select the operation 1.scaling  2.translation  3.rotation 0.exit");
scanf("%d",&ch);
switch(ch)
{
	case 1:scale();
	break;
	case 2:translate();
	break;
	case 3:rotate();
	break;
	default:break;
};
}while(ch!=0);
getch();
closegraph();
}
