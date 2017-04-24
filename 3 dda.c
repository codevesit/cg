#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
 int x1,x2,y1,y2,dx,dy,k,count;
 float x,y,xi,yi;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C://TURBOC3//BGI");
 printf("\nENTER THE START POINT OF THE LINE");
 scanf("%d %d",&x1,&y1);
 printf("\nENTER THE END POINT OF THE LINE");
 scanf("%d %d",&x2,&y2);
 dx=x2-x1;
 dy=y2-y1;
 if((abs(dx))>=(abs(dy)))
 count=dx;
 else
 count=dy;
 xi=(float)dx/count;
 yi=(float)dy/count;
 x=x1;
 y=y1;
 putpixel(x,y,WHITE);
  for(k=1;k<count;k++)
  {
   x=x+xi;
   y=y+yi;
   x1=x+0.5;
   y1=y+0.5;
   putpixel(x,y,7);
 }
 getch();
closegraph();	}
