#include <stdio.h>
#include <math.h>

double det(double a[][2])
{
	return a[0][0] * a[1][1] - a[0][1] * a[1][0];
}  
void sprawdzenie2 (double a[][2], double b[], double x[], double r[]) 
{ 

	r[0] = (a[0][0] * x[0] + a[0][1] * x[1]) - b[0];
	r[1] = (a[1][0] * x[0] + a[1][1] * x[1]) - b[1];

	for (int i = 0; i < 2;  i++)
		printf("%f \n", r[i]);
}
void uklad2(double a[][2], double b[], double x[])
{
	double W = det(a);

	double tt[2][2];

	tt[0][0] = b[0];
	tt[1][0] = b[1];
	tt[0][1] = a[0][1];
	tt[1][1] = a[1][1];

	double Wx = det(tt);
	
	
	tt[0][1] = b[0];
	tt[1][1] = b[1];
	tt[0][0] = a[0][0];
	tt[1][0] = a[1][0];

	double Wy = det(tt);
	double r[] = {0, 0};
	if(W != 0)
{
		x[0] = Wx / W;
		x[1] = Wy / W;
		printf("układ ma rozwiązanie w punkcie (%f, %f)\n", x[0], x[1]);
		sprawdzenie2(a, b, x, r); 
	return;
}
	else if (W == 0 && (Wx == 0 && Wy == 0))
	{x[0] = 99;
	printf("%f \n", x[0]);
	return;}

	else
	return;
	
}
int main_uklad_2x2()
{
	char str[80];
	double a[2][2];
	double x[2], b[2];

	printf("podaj układ równań postaci: \n");
	printf("a11x+a12y=b1 \n");
	scanf("%s", str);
	sscanf(str, "%lgx%lgy=%lg \n", &a[0][0], &a[0][1], &b[0]);

	printf("podaj układ równań postaci: \n");
	printf("a21x+a22y=b2 \n");
	scanf("%s", str);
	sscanf(str, "%lgx%lgy=%lg \n", &a[1][0], &a[1][1], &b[1]);

	uklad2(a,b,x);
	return 0;
}
