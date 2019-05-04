#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/*ganar --> Muestra el mensaje de ganar y el dinero en ese momento.
perder  --> Muestra el mensaje de perder y el dinero en ese momento.
introd  --> Recoge como un vector de dimension variable el dinero.
vectent --> Transforma unvector en un número entero.*/

float ganar(float, int);
float perder(float, int);
int introd();
int vectent(int [], int);

int main()
{
	/*inicial --> Guarda el dinero inicial.
	actual	  --> Guarda el dinero actual.
	mas		  --> Al usar la opcion de añadir mas dinero, guarda cuanto más
	se añadirá.
	opc		  --> Almacena la opción elegida.
	result	  --> Guarda el resultado final de dinero.
	n		  --> Guarda la dimension del vector dinero.
	* din	  --> Vector de dimension variable para el dinero. */

	float inicial, actual, mas;
	int opc, result, n, * din;

	//Do-while de seguridad. Para prevenir valores introducidos no aceptados.
	do {
		printf("Introduce dinero:\n");
		inicial = introd();
		if (inicial < 0) {
			printf("Valor introducido no válido\n");
		}
	} while (inicial < 1);

	//Actualizacion de dato del dinero
	actual = inicial;

	//Campo de eleccion del programa
	do {
		printf("Elige apuesta:\n1. 1€\n2. 2€\n3. 3€\n4. 4€\n5. Introducir más dinero\n6. Salir\n");
		scanf_s("%d", &opc);
		switch (opc) {
		case 1:
			if (actual < 1) {
				printf("No hay dinero suficiente\n");
				break;
			}
			result = rand() % 10 + 1;
			if (result == 1) {
				actual = ganar(actual, 1);
			}
			if (result != 1) {
				actual = perder(actual, 1);
			}
			break;
		case 2:
			if (actual < 2) {
				printf("No hay dinero suficiente\n");
				break;
			}
			result = rand() % 20 + 1;
			if (result == 12) {
				actual = ganar(actual, 2);
			}
			if (result != 12) {
				actual = perder(actual, 2);
			}
			break;
		case 3:
			if (actual < 3) {
				printf("No hay dinero suficiente\n");
				break;
			}
			result = rand() % 30 + 1;
			if (result == 12) {
				actual = ganar(actual, 3);
			}
			if (result != 12) {
				actual = perder(actual, 3);
			}
			break;
		case 4:
			if (actual < 4) {
				printf("No hay dinero suficiente\n");
				break;
			}
			result = rand() % 40 + 1;
			if (result == 12) {
				actual = ganar(actual, 4);
			}
			if (result != 12) {
				actual = perder(actual, 4);
			}
			break;
		case 5:
			do {
				printf("Introduce más dinero:\n");
				mas = introd();
				actual += mas;
				printf("Dinero actual: %.2f\n", actual);
			} while (mas <= 0);
			break;
		case 6:
			break;
		default:
			printf("Apuesta no válida.\n");
			break;
		}
	} while (opc != 6);
	printf("Dinero final: %.2f\n¡Gracias por jugar!\n", actual);
	system("PAUSE");
}//Final del Main

float ganar(float x, int y)//Imprime mensaje y dinero al ganar.
{
	float ganar;
	ganar = x + y;
	printf("¡Ganas!\n");
	printf("Dinero actual: %.2f\n", ganar);
	return ganar;
}
float perder(float y, int z)//Imprime mensaje y dinero al perder.
{
	float perder;
	perder = y - z;
	printf("¡Prueba otra vez!\n");
	printf("Dinero actual: %.2f\n", perder);
	return perder;
}
int introd() //Recoge el dinero inicial
{
	int n, * din, inicial;
	printf("Dime el numero de cifras: ");
	scanf_s("%d", &n);
	din = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		printf("Dime la %da cifra: ", i + 1);
		scanf_s("%d", &din[i]);
	}
	inicial = vectent(din, n);
	return inicial;
}
int vectent(int a[], int n)//Transforma vector en entero.
{
	int entero = 0, y = 1;
	for (int i = (n - 1); i >= 0; i--)
	{
		entero += *(a + i) * y;
		y = y * 10;
	}
	return entero;
}