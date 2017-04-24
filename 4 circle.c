#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void circlepoint(int x,int y,int xc,int yc);
void circlepoint(int x,int y,int xc,int yc)
{
	putpixel(x+xc,y+yc,WHITE);
	putpixel(x+xc,-y+yc,WHITE);
	putpixel(-x+xc,y+yc,WHITE);
	putpixel(-x+xc,-y+yc,WHITE);
	putpixel(y+xc,x+yc,WHITE);
	putpixel(y+xc,-x+yc,WHITE);
	putpixel(-y+xc,x+yc,WHITE);
	putpixel(-y+xc,-x+yc,WHITE);
}
void main()
{
	int gm=DETECT,gd,x,xc,y,yc,p,rad;
	initgraph(&gm,&gd,"C:\\TC\\BGI");
	printf("Enter the center in x and y and the radius");
	scanf("%d",&xc);
	scanf("%d",&yc);
	scanf("%d",&rad);
	x=0;
	y=rad;
	p=1-rad;
	while(x<y)
	{
		x++;
		if(p>0)
		{
			p=p+2*(x-y)+1;
			y--;
		}
		else
		{
			p=p+2*x+1;
		}
		circlepoint(x,y,xc,yc);
	}
	getch();
	closegraph();
}
