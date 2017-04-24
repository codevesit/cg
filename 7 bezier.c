#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

float xCurvePoint(int a[][2], int n, float u);
float yCurvePoint(int a[][2], int n, float u);
int fact(int n);

void main() {
	int gd = DETECT, gm;
	int a[100][2], i, n;
	float u, x, y;
	clrscr();
	printf("*****BEZIER*****");
	printf("\nEnter the number of points: ");
	scanf("%d", &n);
	printf("\nEnter the points: \n");
	for(i = 0; i < n; i++) {
		printf("[x%d, y%d]: ", i, i);
		scanf("%d%d", &a[i][0], &a[i][1]);
	}
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	for(u = 0; u < 1; u += 0.000005)
{
		x = xCurvePoint(a, n, u);
		y = yCurvePoint(a, n, u);
		putpixel(x, y, CYAN);
	}
	getch();
	closegraph();
}
float xCurvePoint(int a[][2], int n, float u) {
	int i;
	float x;
	x = 0;
	for(i = 0; i < n; i++) {
		x += nCr(n - 1, i) * pow((1 - u), (n - 1 - i)) * pow(u, i) * a[i][0];
	}
	return x;
}
float yCurvePoint(int a[][2], int n, float u) {
	int i;
	float y;
	y = 0;
	for(i = 0; i < n; i++) {
		y += nCr(n - 1, i) * pow((1 - u), (n - 1 - i)) * pow(u, i) * a[i][1];
	}
	return y;
}
int nCr(int n, int r) {
	return ((fact(n)) / (fact(n-r) * fact(r)));
}

int fact(int n) {
	if(n == 0) {
		return 1;
	} else {
		return n * fact(n - 1);
	}
}
