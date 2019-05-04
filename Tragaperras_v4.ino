/*VERSION CON INTRODUCCION POR PARTE DEL USUARO DEL DINERO
 * FUNCIONAL AL 90%, SOLO FALTA PODER INTRODUCIR VARIOS DIGITOS.
 * ENTREGABLE YA.*/

#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Definicion de Keypad
const byte ROWS = 4; 
const byte COLS = 4; 

//Definicion de los valores del Keypad
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'B'},
  {'B', '0', 'B', 'B'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

//Direccion de la pantalla
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Declaracion de variables
 char opc;
 int dinero, actual = 0, result, cont = 0;

void setup() {
  lcd.backlight();
  lcd.init();
  Serial.begin(9600);
}

void loop() {
  /*do{
    actual = customKeypad.getKey();
    actual = actual - 48;
  }while(actual == NO_KEY);//Final del Do While*/
  //Carteles iniciales
  lcd.setCursor(0, 0);
  lcd.print("A. Introducir");
  lcd.setCursor(0, 1);
  lcd.print("dinero.");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Haz una apuesta:");
  lcd.setCursor(0, 1);
  lcd.print("1. 1e");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("2. 2e");
  lcd.setCursor(0, 1);
  lcd.print("3. 3e");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("4. 4e");
  lcd.setCursor(0, 1);
  lcd.print("5. 5e");
  delay(1000);
  lcd.clear();
  //Estructura del programa
  do {
  opc = customKeypad.getKey();
  switch (opc)
   {
    case '1':
      if (dinero<1){
          imprimir_f();
          break;
        }
        result = rand() % 10 +1;
                if (result == 1) {
                    actual = dinero + 1;
                    dinero = actual;
                    imprimir_g(actual);
                }
                if (result != 1) {
                    actual = dinero - 1;
                    dinero = actual;
                    imprimir_p(actual);
                }
      delay(100);          
      break;          
    case '2':
      if (dinero<2){
          imprimir_f();
          break;
        }
        result = rand() % 10 +1;
                if (result == 1) {
                    actual = dinero + 2;
                    dinero = actual;
                    imprimir_g(actual);
                }
                if (result != 1) {
                    actual = dinero - 2;
                    dinero = actual;
                    imprimir_p(actual);
                }
      break;
    case '3':
      if (dinero<3){
          imprimir_f();
          break;
        }
        result = rand() % 10 +1;
                if (result == 1) {
                    actual = dinero + 3;
                    dinero = actual;
                    imprimir_g(actual);
                }
                if (result != 1) {
                    actual = dinero - 3;
                    dinero = actual;
                    imprimir_p(actual);
                }
      break;
    case '4':
      if (dinero<4){
          imprimir_f();
          break;
        }
        result = rand() % 10 +1;
                if (result == 1) {
                    actual = dinero + 4;
                    dinero = actual;
                    imprimir_g(actual);
                }
                if (result != 1) {
                    actual = dinero - 4;
                    dinero = actual;
                    imprimir_p(actual);
                }
      break;
    case '5':
      if (dinero<5){
          imprimir_f();
          break;
        }
        result = rand() % 10 +1;
                if (result == 1) {
                    actual = dinero + 5;
                    dinero = actual;
                    imprimir_g(actual);
                }
                if (result != 1) {
                    actual = dinero - 5;
                    dinero = actual;
                    imprimir_p(actual);
                }
      break;
    case 'A':
      intro();
      break;
    case 'B':
      error();
      break;        
   }//Fin del switch-case
   /*if (actual == 0){
    Serial.println("Ya te meto yo dineros");
    actual = 8;
   }*/
  }while (opc == NO_KEY);//Fin del do while
}//Fin del loop

void imprimir_g(int a){//Funcion para imprimir en el LCD ganar
  lcd.setCursor(0, 0);
  lcd.print("Ganas!");
  lcd.setCursor(0, 1);
  lcd.print(a);
  delay(1000);
  lcd.clear();
}

void imprimir_p(int b){//Funcion para imrpimir en el LCD perder
  lcd.setCursor(0, 0);
  lcd.print("Pierdes!");
  lcd.setCursor(0, 1);
  lcd.print(b);
  delay(1000);
  lcd.clear();
}

void imprimir_f(){//Funcion para imprimir en el LCD falta de saldo
  lcd.setCursor(0, 0);
  lcd.print("No hay saldo");
  lcd.setCursor(0, 1);
  lcd.print("suficiente.");
  delay(1500);
  lcd.clear();
}

void error(){//Funcion para error de caracter
  lcd.setCursor(0, 0);
  lcd.print("Valor introducid");
  lcd.setCursor(0, 1);
  lcd.print("o no valido.");
  delay(2000);
  lcd.clear();
}

void intro(){
  do{
    dinero = customKeypad.getKey();
  }while(dinero == NO_KEY);
  dinero = dinero - 48;
}
