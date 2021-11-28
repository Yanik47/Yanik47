#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main_dwumian_Newtona();
void main_rownanie_kwadratowe();
void main_uklad_2x2();
void main_uklad_3x3(); 

char menu()
{
	printf("1. Dwumian Newtona \n");
	printf("2. Rownanie kwadratowe \n");
	printf("3. Uklad 2x2 \n");
	printf("4. Uklad 3x3 \n");
	printf("5. Koniec programu \n");

	char c; 
	printf("Wybierz opcje: ");
	scanf("%s", &c);
	return c;
}

int main()
{
	while (1)
	switch (menu())
	{
		case '1':
			printf("Wybrano dwumian Newtona \n");
			main_dwumian_Newtona();
			break;
		case '2':
			printf("Wybrano rownanie kwadratowe \n");
			main_rownanie_kwadratowe();
			break; 
		case '3':
			printf("Wybrano uklad 2x2 \n");
			main_uklad_2x2();
			break; 
		case '4':
			printf("Wybrano uklad 3x3 \n");
			main_uklad_3x3();
			break; 
		case '5':
			printf("Koniec programu \n");
			exit(0);
		default :
			printf("Nie ma takiej opcji \n");
	}
	return 0;
}
