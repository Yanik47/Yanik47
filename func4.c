#include <stdio.h>
#include <math.h>

double Silnia (unsigned n)
	{ if (n == 0) 
		return 1.0;
	  else 
		return n*Silnia(n);
}
double sn (unsigned n, unsigned k)
	{ if (n == 0) 
		return 1.0;
	  else 
		return n*Silnia(n) / (Silnia(k) * Silnia(n - k));
}
double fL (unsigned n, double a, double b)
{
	if (n == 0) 
		return 1.0;
	else 
		return pow(a + b, n);
		
}		
double fR (unsigned n, double a, double b)
{
	 double Res = 0;
	 
	 for (int k = 0; k <= n;)
	 {   
	 Res += (sn(n, k) * pow(a, n-k) * pow(b, k)); 
	 k++;
	 }
	 return Res;	 
}

int main_dwumian_Newtona() 
{
	double a, b, L, R;
	unsigned n;
	
	printf("podaj liczbe a: \n");
	scanf("%lg", &a);
	printf("podaj liczbe b: \n");
	scanf("%lg", &b);
	printf("podaj liczbe n: \n");
	scanf("%d", &n); 

	L = fL(n, a, b);
	R = fR(n, a, b); 
	
	printf("lF = %g = %g = lR\n", L, R);   
	return 0;
}
