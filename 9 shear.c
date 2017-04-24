#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

void shearing(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int ch,i,n,shx,shy,ax,ay;
    printf("\nEnter the type of shearing:\n1.X-shear\n2.Y-shear\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: {
                    printf("\nEnter the shearing value : ");
                    scanf("%d",&shx);
                    x1=x1+(y1*shx);
                    x2=x2+(y2*shx);
                    x3=x3+(y3*shx);
                    line(x1,y1,x2,y2);
                    line(x2,y2,x3,y3);
                    line(x3,y3,x1,y1);
                    break;
                }
        case 2: {
                    printf("\nEnter the shearing value : ");
                    scanf("%d",&shy);
                    y1=y1+(x1*shy);
                    y2=y2+(x2*shy);
                    y3=y3+(x3*shy);
                    line(x1,y1,x2,y2);
                    line(x2,y2,x3,y3);
                    line(x3,y3,x1,y1);
                    break;
                }
    }
}

void main()
{
    int gd=DETECT,gm,x1,y1,x2,y2,x3,y3,c;
    initgraph(&gd,&gm,"C:\\tc\\bgi");
    printf("\nEnter the points of triangle\n");
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);
    printf("Select : 1. Shearing\t2. Exit\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1: shearing(x1,y1,x2,y2,x3,y3);
                break;
        case 2: break;
    }
    getch();
    closegraph();
}
