#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno (7, 6);
#define GREEN_LED     13 //D5
#define RED_LED       12 //D7
#define BLUE_LED      11
#define GREEN_LED2     10 //D5
#define RED_LED2       9 //D7
#define BLUE_LED2      8

int i, b;
int buzzer = 5; 
int buzzer2 = 4; 

void getSensorData()
{
     if (i > 2300 && i < 2400 ){
      tone(buzzer, 1000);
      delay(500);        // ...for 1 sec
      noTone(buzzer);     // Stop sound...
      delay(200);
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(RED_LED, LOW);
      digitalWrite(BLUE_LED, LOW);
    }
    else if(i > 2401 && i < 3000)
    {
      tone(buzzer, 1000);
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, HIGH);
      digitalWrite(BLUE_LED, LOW);
    }
    else {
      noTone(buzzer);
      digitalWrite(BLUE_LED, HIGH);
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
    }
}

void getSensorData2()
{
     if (b > 4300 && b < 4400 ){
      tone(buzzer2, 1000);
      delay(500);        // ...for 1 sec
      noTone(buzzer2);     // Stop sound...
      delay(200);
      digitalWrite(GREEN_LED2, HIGH);
      digitalWrite(RED_LED2, LOW);
      digitalWrite(BLUE_LED2, LOW);
    }
    else if(b > 4401 && b < 5000)
    {
      tone(buzzer2, 1000);
      digitalWrite(GREEN_LED2, LOW);
      digitalWrite(RED_LED2, HIGH);
      digitalWrite(BLUE_LED2, LOW);
    }
    else {
      noTone(buzzer2);
      digitalWrite(BLUE_LED2, HIGH);
      digitalWrite(RED_LED2, LOW);
      digitalWrite(GREEN_LED2, LOW);
    }
}

void setup() {
  Serial.begin(115200);
  ArduinoUno.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  pinMode(buzzer, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  pinMode(GREEN_LED2, OUTPUT);
  pinMode(RED_LED2, OUTPUT);
  pinMode(BLUE_LED2, OUTPUT);
  
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, LOW);

  digitalWrite(GREEN_LED2, LOW);
  digitalWrite(BLUE_LED2, LOW);
  digitalWrite(RED_LED2, LOW);
}
void loop() {
i = analogRead (A0);
  i = i + 2000;
  ArduinoUno.print(i);
  ArduinoUno.println("\n");
  Serial.println(i);

  b = analogRead (A1);
  b = b + 4000;
  ArduinoUno.print(b);
  ArduinoUno.println("\n");
  Serial.println(b);
  getSensorData();
  getSensorData2();
  delay(5000);

}
