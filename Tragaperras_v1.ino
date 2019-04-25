#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'E', '0', 'F', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  Serial.begin(9600);
  Serial.print("Introduce dinero:\n");
}

void loop() {
  int c;
  char inicial, opc, result, key, mas;
  do {
    char inicial = customKeypad.getKey();
    if(inicial >= 65 && inicial <= 69){
      Serial.print("Valor introducido no válido.\n");
      c = 1;
    }
    else if(inicial){
      Serial.println(inicial);
      c = 0;
    }
  }while(c == 1);
  char actual = inicial;
  
    Serial.println("Elige apuesta:\n1. 1€\n2. 2€\n3. 3€\n4. 4€\n5. Introducir más dinero\n6. Salir");
    //Hago al programa esperar a que se presione una tecla
    do {
      key = customKeypad.getKey();
      switch(customKeypad.getKey()) {
      case '1':
        if (actual<1){
          Serial.println("No hay dinero suficiente.");
          break;
        }
        result = rand() % 10 +1;
                if (result == 1) {
                    actual = actual + 1;
                    Serial.println("¡Ganas!");
                    Serial.println(actual);
                }
                if (result != 1) {
                    actual = actual - 1;
                    Serial.println("Pierdes...");
                    Serial.println(actual);
                }
       case '2':
                if (actual<2) {
                    Serial.println("No hay dinero suficiente\n");
                    break;
                }
                result = rand() % 20 +1;
                if (result == 12) {
                    actual = actual + 2;
                }
                if (result != 12) {
                    actual = actual - 2;
                }
                break;
            case '3':
                if (actual<3) {
                    Serial.println("No hay dinero suficiente\n");
                    break;
                }
                result = rand() % 30 +1;
                if (result == 12) {
                    actual = actual + 3;
                }
                if (result != 12) {
                    actual = actual - 3;
                }
                break;
            case '4':
                if (actual<4) {
                    Serial.println("No hay dinero suficiente\n");
                    break;
                }
                result = rand() % 40 +1;
                if (result == 12) {
                    actual = actual + 4;
                }
                if (result != 12) {
                    actual = actual - 4;
                }
                break;
            case '5':
                do {
                    Serial.println("Introduce más dinero:\n");
                    mas = customKeypad.getKey();
                    actual += mas;
                    Serial.println("Dinero actual: ");
                    Serial.println(actual);
                } while (mas<=0);
                break;
    }//Fin del Switch
    } while (key == NO_KEY);
    
  /*  
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
    printf("Dinero final: %.2f\n¡Gracias por jugar!\n", actual);*/
}
/*
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
}*/
