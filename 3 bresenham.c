#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
    int gd=DETECT,gm,x,y,x1,y1,x2,y2,dy,dx,ds,de,dne;
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    printf("enter the starting point");
    scanf("%d",&x1);
    scanf("%d",&y1);
    printf("\n enter the ending point");
    scanf("%d",&x2);
    scanf("%d",&y2);
    x=x1;
    y=y1;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    ds=2*dy-dx;
    de=2*dy;
    dne=2*(dy-dx);
    while(x<x2)
    {
        if(ds<=0)
        {
            ds=ds+de;
        }
        else
        {
            ds=ds+dne;
            y=y+1;
        }
        x=x+1;
        putpixel(x,y,WHITE);
    }
    getch();
    closegraph();
}
