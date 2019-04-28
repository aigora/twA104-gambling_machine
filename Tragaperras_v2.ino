#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Definicion de Keypad
const byte ROWS = 4; 
const byte COLS = 4; 

//Definicion de los valores del Keypad
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'A'},
  {'7', '8', '9', 'A'},
  {'A', '0', 'A', 'A'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

//Direccion de la pantalla
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Declaracion de variables
 char opc;
 int actual = 10, result, cont = 0;

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
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Haz una apuesta");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1. 1e");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("2. 2e");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("3. 3e");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("4. 4e");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("5. 5e");
  delay(1000);
  lcd.clear();
  //Estructura del programa
  do {
  opc = customKeypad.getKey();
  switch (opc)
   {
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
      delay(100);          
      break;          
    case '2':
      if (actual<2){
          Serial.println("No hay dinero suficiente.");
          break;
        }
        result = rand() % 10 +1;
                if (result == 1) {
                    actual = actual + 2;
                    Serial.println("¡Ganas!");
                    Serial.println(actual);
                }
                if (result != 1) {
                    actual = actual - 2;
                    Serial.println("Pierdes...");
                    Serial.println(actual);
                }
      break;
    case '3':
      if (actual<3){
          Serial.println("No hay dinero suficiente.");
          break;
        }
        result = rand() % 10 +1;
                if (result == 1) {
                    actual = actual + 3;
                    Serial.println("¡Ganas!");
                    Serial.println(actual);
                }
                if (result != 1) {
                    actual = actual - 3;
                    Serial.println("Pierdes...");
                    Serial.println(actual);
                }
      break;
    case '4':
      if (actual<4){
          Serial.println("No hay dinero suficiente.");
          break;
        }
        result = rand() % 10 +1;
                if (result == 1) {
                    actual = actual + 4;
                    Serial.println("¡Ganas!");
                    Serial.println(actual);
                }
                if (result != 1) {
                    actual = actual - 4;
                    Serial.println("Pierdes...");
                    Serial.println(actual);
                }
      break;
    case '5':
      if (actual<5){
          Serial.println("No hay dinero suficiente.");
          break;
        }
        result = rand() % 10 +1;
                if (result == 1) {
                    actual = actual + 5;
                    Serial.println("¡Ganas!");
                    Serial.println(actual);
                }
                if (result != 1) {
                    actual = actual - 5;
                    Serial.println("Pierdes...");
                    Serial.println(actual);
                }
      break;
    case 'A':
      Serial.println("Valor introducido no válido.");
      break;         
   }//Fin del switch
   if (actual == 0){
    Serial.println("Ya te meto yo dineros");
    actual = 8;
   }
  }while (opc == NO_KEY);//Fin del do while
}//Fin del loop

int dinero (char ){
  do{
    
  }while(actual == NO_KEY);
}
