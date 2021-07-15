#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int sensorPin = 1;
int sensorValuePhotoresistor = 0;
void setup() {
  Serial.begin(9600);
  dht.begin(); // initialize the sensor
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2,INPUT);
  dht.begin();
}

void loop() {
//  digitalWrite(4, HIGH);
      sensorValuePhotoresistor = analogRead(sensorPin);
      Serial.println(sensorValuePhotoresistor);
        if(sensorValuePhotoresistor<4)
            {  digitalWrite(6, HIGH);
            }
            else{
              digitalWrite(6, LOW);
            }
           
  int tempC = dht.readTemperature();

  // check if any reads failed
  if (isnan(tempC)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
  Serial.print("Temperature: ");
    Serial.println(tempC);

            if(tempC<29)
            {
              digitalWrite(4, LOW);

            }
          else{
            digitalWrite(4, HIGH);
          }

  }

    
  }


  
