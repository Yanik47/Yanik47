
#include <stdio.h>
#include <math.h>

double det3(double a[][3])
{
	double x = a[0][0] * a[1][1] * a[2][2];
	double x1 = a[2][0] * a[0][1] * a[1][2];
	double x2 = a[1][0] * a[2][1] * a[0][2];
	double x3 = a[2][1] * a[1][1] * a[0][2];
	double x4 = a[0][0] * a[2][1] * a[1][2];
	double x5 = a[1][0] * a[0][1] * a[2][2];
	return x + x1 + x2 - x3 - x4 - x5;
}
 
void sprawdzenie3 (double a[][3], double b[], double x[], double r[]) 
{ 

	r[0] = (a[0][0] * x[0] + a[0][1] * x[1] + a[0][2] * x[2]) - b[0];
	r[1] = (a[1][0] * x[0] + a[1][1] * x[1] + a[1][2] * x[2]) - b[1];
	r[2] = (a[2][0] * x[0] + a[2][1] * x[1] + a[2][2] * x[2]) - b[2];

	for (int i = 0; i < 3;  i++)
		printf("%f \n", r[i]);
 
/*Функция должна подставить все значения и сравнить левую и правую сторону уравнения посредством 
вычитания правой части из левой. Результат должен быть близок к нулю. Тоже нужно сделать и в 
2х2*/ 
}
 
void uklad3(double a[][3], double b[], double x[])
{
 
	double W = det3(a);
	double Wx, Wy, Wz;
	double tt[3][3];
 
	for (int t = 0; t < 3; t++)
	{
    	for(int j = 0; j < 3; j++)
    	{
        	for(int i = 0; i < 3; i++)
        	{
            	if(t == j)
               	 {tt[i][j] = b[i];}
            	else
               	 {tt[i][j] = a[i][j];}
        	}
    	}
    	if(t == 0)
        	{Wx = det3(tt);}
    	else if(t == 1)
        	{Wy = det3(tt);}
    	else 
        	{Wz = det3(tt);}
	}
 
	double r[3];
 
	if (W != 0)
	{
    		x[0] = Wx / W;
    		x[1] = Wy / W;
    		x[2] = Wz / W;
    		printf("układ ma rozwiązanie w punkcie (%lg, %lg, %lg)\n", x[0], x[1], x[2]);
    
	}
 
	else
	{
    		printf("układ nie ma rozwiązań lub ma ich nieskonczoną ilość");
    		return;
	} 
sprawdzenie3(a, b, x, r);
}
 
 
 
int main_uklad_3x3()
{
	char str[100];
	double a[3][3];
	double b[3], x[3];
 
 
	printf("podaj układ równań postaci: \n");
	printf("a11x+a12y+a13z=b1 \n");
	scanf("%s", str);
	sscanf(str, "%lgx%lgy%lgz=%lg \n", &a[0][0], &a[0][1], &a[0][2], &b[0]);
 
	printf("podaj układ równań postaci: \n");
	printf("a21x+a22y+a23z=b2 \n");
	scanf("%s", str);
	sscanf(str, "%lgx%lgy%lgz=%lg \n", &a[1][0], &a[1][1], &a[1][2], &b[1]);
 
	printf("podaj układ równań postaci: \n");
	printf("a31x+a32y+a33z=b3 \n");
	scanf("%s", str);
	sscanf(str, "%lgx%lgy%lgz=%lg \n", &a[2][0], &a[2][1], &a[2][2], &b[2]);
 
	uklad3(a,b,x);
	return 0;
}
