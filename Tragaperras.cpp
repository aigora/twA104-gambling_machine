#include <stdio.h>
#include <stdlib.h>
float ganar (float, int);
float perder (float, int);
int main ( )
{
    float inicial, actual, mas;
    int opc, result;
    do {
        printf("Introduce dinero:\n");
        scanf ("%fl", &inicial);
        if (inicial<0) {
            printf("Valor introducido no válido\n");
        }
    } while (inicial<1);
    
    actual = inicial;
    
    do {
        printf ("Elige apuesta:\n1. 1€\n2. 2€\n3. 3€\n4. 4€\n5. Introducir más dinero\n6. Salir\n");
        scanf ("%d", &opc);
        switch (opc) {
            case 1:
                if (actual<1) {
                    printf("No hay dinero suficiente\n");
                    break;
                }
                result = rand() % 10 +1;
                if (result == 1) {
                    actual = ganar(actual, 1);
                }
                if (result != 1) {
                    actual = perder(actual, 1);
                }
                break;
            case 2:
                if (actual<2) {
                    printf("No hay dinero suficiente\n");
                    break;
                }
                result = rand() % 20 +1;
                if (result == 12) {
                    actual = ganar(actual, 2);
                }
                if (result != 12) {
                    actual = perder(actual, 2);
                }
                break;
            case 3:
                if (actual<3) {
                    printf("No hay dinero suficiente\n");
                    break;
                }
                result = rand() % 30 +1;
                if (result == 12) {
                    actual = ganar(actual, 3);
                }
                if (result != 12) {
                    actual = perder(actual, 3);
                }
                break;
            case 4:
                if (actual<4) {
                    printf("No hay dinero suficiente\n");
                    break;
                }
                result = rand() % 40 +1;
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
                    scanf("%f", &mas);
                    actual += mas;
                    printf("Dinero actual: %.2f\n", actual);
                } while (mas<=0);
                break;
            case 6:
                break;
            default:
                printf("Apuesta no válida.\n");
                break;
        }
    } while (opc !=6);
    printf("Dinero final: %.2f\n¡Gracias por jugar!\n", actual);
}

float ganar (float x, int y)
{
    float ganar;
    ganar = x+y;
    printf("¡Ganas!\n");
    printf("Dinero actual: %.2f\n", ganar);
    return ganar;
}
float perder (float y, int z)
{
    float perder;
    perder = y-z;
    printf("¡Prueba otra vez!\n");
    printf("Dinero actual: %.2f\n", perder);
    return perder;
}
