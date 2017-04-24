#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
	int gd=DETECT,gm;
	float b,d,a,x,y,xc,yc,c=1,e=1;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	printf("Enter center of ellipse and major and minor axis\n");
	scanf("%f%f%f%f",&xc,&yc,&a,&b);
	x=0;
	y=b;
       //	if( (b*b*((2*x)+2)) - (a*a*((2*y)-1)) >=0 )
	while(y!=0)
	{
		if( (b*b*(x+1)) - (a*a*(y-1/2)) < 0 )
		{       if(c==1)
			{
				d=(b*b) + ((a*a)*(1/4-b));
				c--;
			}
			if(d<0)
			{
				d=d+(b*b)*((2*x)+3);
				x++;
			}
			else
			{
				d=d+((b*b)*(2*x+3)) + (a*a*(2-2*y));
				x++;
				y--;
			}
		}
		else if( (b*b*(x+1)) - (a*a*(y-1/2)) >= 0 )
		{
			if(e==1)
			{
				d=(b*b*(x+1/2)*(x+1/2))+(a*a*(y-1)*(y-1))-a*a*b*b;
				e--;
			}
			if(d>0)
			{
				d=d+a*a*(3-2*y);
				y--;
			}
			else
			{
				d=d+(b*b*(2*x+2))+(a*a*(3-2*y));
				x++;
				y--;
			}
		}
		putpixel(xc+x,yc+y,WHITE);
		putpixel(xc-x,y+yc,WHITE);
		putpixel(x+xc,yc-y,WHITE);
		putpixel(xc-x,yc-y,WHITE);
		//printf("\n%d %d\n",x,y);
	}
	getch();
	closegraph();
}
