

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int tempPin = 0;
int sensor=6; //The output of PIR sensor connected to pin 7
int sensor_value; //variable to hold read sensor value
int motorPin = 9;
int sensorPin = 1;
int sensorValuePhotoresistor = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600); 
  // Print a message to the LCD.
  lcd.print("TEMPERATURE = ");
   pinMode(motorPin, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(sensor,INPUT);
}

void loop() {
  
  lcd.setCursor(0, 0);
 
  
  double temp = analogRead(tempPin);
   temp = temp * 0.48828125;
  temp=temp-49.5266;
  
  Serial.print("TEMPERATURE=");
   lcd.setCursor(0, 1);
  lcd.print(temp);
  lcd.print("*C");
  lcd.println();
  Serial.println(temp);
  //--------------------

      sensorValuePhotoresistor = analogRead(sensorPin);
  			if(sensorValuePhotoresistor<100)
            {  digitalWrite(7, HIGH);
            }
            else{
              digitalWrite(7, LOW);
            }
  
            if(temp<30)
            {
              analogWrite(motorPin, 0);

            }
          else{
            analogWrite(motorPin, 255);
          }
      

  
//analogWrite(motorPin, temp);
  //lcd.println(sensorValuePhotoresistor);
  
}
 