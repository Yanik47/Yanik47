#include <stdio.h>
#include <math.h>

void rkw (double a, double b, double c) {
	double n;
	double x1; 
	double x2;

	printf("a = %lg, b = %lg, c = %lg \n", a, b, c);
	double delta = b*b - 4*a*c;
	printf("delta = %lg \n", delta);

	if(delta < 0.0)
		n = 0;
	else if(delta == 0.0)
	{
		x1 = -b/2/a;
		n = 1;
	}
	else 
	{
		delta = sqrt(delta);
		x1 = (-b - delta)/2/a;
		x2 = (-b + delta)/2/a;
		n = 2;
	} 

	if (n == 0)
		printf("równanie nie posiada pierwiastków \n");
	else if (n == 1)
		printf("równanie posiada jeden pierwiastek: x = %lg \n", x1); 
	else if (n == 2)
		printf("równanie posiada dwa pierwiastki: x1 = %lg, x2 = %lg \n", x1, x2);

}

int main_rownanie_kwadratowe()
{ 

	char str[50]; 
	double a, b, c;

	printf("Napisz równanie typu ax^2 + bx + c = 0: \n");
	scanf("%s", str);
	sscanf(str, "%lgx^2%lgx%lg=0", &a, &b, &c);

	rkw(a, b, c);

	return 0;
}
