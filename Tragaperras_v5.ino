/*CODIGO COMPLETO: MODO DE EMPLEO:
UNA VEZ CONECTADO EL PAD A LOS PINES (DE IZQ. A DCH.)
9-2 Y LA PANTALLA GND-->GND, VCC-->5V, SDA-->A4, SCL-->A5
PASOS A SEGUIR:
1. ESPERAR A QUE EL TEXTO SE QUITE DE LA PANTALLA
2. PRESIONAR LA OPCION QUE SALE AL INICIO DE CADA FRASE PARA ELEGIRLA
3. ANTES DE EMPEZAR A JUGAR ES NECESARIO USAR LA OPCION A. INTRODUCIR DINERO
4. SE PODRA INTRODUCIR DINERO EN CUALQUIER PARTIDA*/
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Definicion de Keypad
const byte ROWS = 4; 
const byte COLS = 4; 

//Definicion de los valores del Keypad y los pines
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

//Declaracion de variables globales
//* p --> vector que contiene el dinero (dinamico)
//opc --> variable para el switch-case
//n --> tamaño del vector que contiene el dinero (dimension)

 char opc;
 int dinero = 0, actual = 0, result, aux;
 int* p, n;

 

void setup() {
  lcd.backlight();
  lcd.init();
}

void loop() {
  //Carteles iniciales
  inicio();
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
      case '6':
      if (dinero<10){
          imprimir_f();
          break;
        }
        result = rand() % 10 +1;
                if (result == 1) {
                    actual = dinero + 10;
                    dinero = actual;
                    imprimir_g(actual);
                }
                if (result != 1) {
                    actual = dinero -10;
                    dinero = actual;
                    imprimir_p(actual);
                }
      break;
      case '7':
      if (dinero<10){
          imprimir_f();
          break;
        }
        result = rand() % 10 +1;
                if (result == 1) {
                    actual = dinero + 25;
                    dinero = actual;
                    imprimir_g(actual);
                }
                if (result != 1) {
                    actual = dinero -10;
                    dinero = actual;
                    imprimir_p(actual);
                }
      break;
      case '8':
      if (dinero<10){
          imprimir_f();
          break;
        }
        result = rand() % 10 +1;
                if (result == 1) {
                    actual = dinero + 50;
                    dinero = actual;
                    imprimir_g(actual);
                }
                if (result != 1) {
                    actual = dinero -50;
                    dinero = actual;
                    imprimir_p(actual);
                }
      break;
      case '9':
      if (dinero<100){
          imprimir_f();
          break;
        }
        result = rand() % 10 +1;
                if (result == 1) {
                    actual = dinero + 100;
                    dinero = actual;
                    imprimir_g(actual);
                }
                if (result != 1) {
                    actual = dinero -100;
                    dinero = actual;
                    imprimir_p(actual);
                }
      break;
      case '0':
      lcd.clear();
      lcd.setCrusor(0, 0);
      lcd.print("Dinero obtenido:");
      lcd.setCursor(0, 1);
      lcd.print(dinero);
      delay(1000);
      lcd.clear();
      dinero = 0;
      break;
    case 'A':
      intro();
      aux = vectent(p);
      if(dinero == 0){
        dinero = aux;
      }else if(dinero != 0)
      {
        dinero = dinero + aux;
      }
      break;
    case 'B':
      error();
      break;        
   }//Fin del switch-case
  }while (opc == NO_KEY);//Fin del do while
}//Fin del loop

void inicio(){
    lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("A. Introducir");
  lcd.setCursor(0, 1);
  lcd.print("dinero.");
  lcd.clear();
  delay(1500);
  lcd.setCursor(0, 0);
  lcd.print("0. Sacar dinero.");
  delay(1000);
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
  lcd.setCursor(0, 0);
  lcd.print("6. 10e");
  lcd.setCursor(0, 1);
  lcd.print("7. 25e");
  delay(1000);
  lcd.clear;
  lcd.setCursor(0, 0);
  lcd.print("8. 50e");
  lcd.setCursor(0, 1);
  lcd.print("9. 100e");
  delay(1000);
  lcd.clear;
}

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

int entrada()//Funcion que recoge valor del pad
{
  int a;
  do{
    a = customKeypad.getKey();
  }while(a == NO_KEY);
  return a;
}

int pad()//Funcion que depura el valor del pad
{
  int res;
  res = entrada();
  res = res - 48;
  return res;
}

int vectent(int * a){//Funcion que pasa de vector a entero
  int entero = 0, y = 1;
  for(int x = (n - 1); x >= 0; x--)
  {
    entero += *(a+x)*y;
    y = y*10;
  }
  return entero;
}

void intro(){
  int k = 0;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Numero de cifras:");
      delay(900);
      lcd.clear();
      n = pad();
      p = (int*)calloc(n, sizeof(int));
      lcd.setCursor(0, 0);
      lcd.print("Introduce el numero:");
      delay(1000);
      lcd.clear();
      do{
        *(p+k) = pad();
        k++;
      }while(k < n);
}
