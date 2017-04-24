#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int x[10],y[10];
unsigned far getpixel(int x, int y);
void boundaryFill(int x, int y, int fillColor, int borderColor)
{
  int interiorColor;
  interiorColor=getpixel(x,y);
  if ((interiorColor!=borderColor)&&(interiorColor!=fillColor)) {
    putpixel(x,y,fillColor);
    boundaryFill(x+1,y,fillColor,borderColor);
    boundaryFill(x-1,y,fillColor,borderColor);
    boundaryFill(x,y+1,fillColor,borderColor);
    boundaryFill(x,y-1,fillColor,borderColor);
  }
}
void main()
{
	int gd=DETECT,gm,i;
	int n,a,b;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	printf("enter the no. of points");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("enter coordinates of point %d",i+1);
	scanf("%d %d",&x[i],&y[i]);
	}
	for(i=0;i<n-1;i++)
    {
	line(x[i],y[i],x[i+1],y[i+1]);
    }
    line(x[0],y[0],x[n-1],y[n-1]);
    printf("enter a point inside the polygon");
    scanf("%d %d",&a,&b);
    boundaryFill(a,b,RED,WHITE);
	getch();
	closegraph();

}
