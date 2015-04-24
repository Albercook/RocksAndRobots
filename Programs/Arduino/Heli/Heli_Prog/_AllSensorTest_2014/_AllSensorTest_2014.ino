//This example code is in the public domain.
 
#include "DigiKeyboard.h" 
 
// New concept: "const". "const" tells the compiler that
// the thing that looks like a variable, isn't allowed to
// change. It is a CONSTant.
// The compiler will complain about any other lines of code
// that might change the value of a constant. This is useful
// for large programs.
const int redLED = 3; 
const int gyroSensorAnalogPin = 0;
const int frontSensorAnalogPin = 2;
const int downSensorAnalogPin = 1;
int gyroMinReading = 1023;
int gyroMaxReading = 0;
unsigned long whenToStop= 0;

void setup() {                
  // initialize the outputs or inputs.
  pinMode(redLED,OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  whenToStop = millis() + 100;  
}

// Delay for a set period of time, and also check the gyro sensor.
void specialDelay(long delayms) 
{
  int gyroReading;

  // whenToStop = millis() + delayms;
  while ( delayms > 0) {
    gyroReading = analogRead(gyroSensorAnalogPin);
    if ( gyroReading > gyroMaxReading ) {
      gyroMaxReading = gyroReading;
    }
    if ( gyroReading < gyroMinReading ) {
      gyroMinReading = gyroReading;
    }
    delay(10);
    delayms = delayms - 10;
  }
}
// loop forever
void loop() {
  int i;

  // Analog sensors read voltages as values from 0 to 1023.
  // Zero corresponds to ground. In this circuit, 1023 corresponds
  // the battery voltage. The analog circuitry is not perfect.
  // Don't be surprised if the values read change a little with
  // temperature, state of the battery, or after the helicopter
  // crashes a few times.
  
  // Rather than look for an exact value, we will just test
  // if the value is above or below about half of the battery
  // voltage.
 
  if (analogRead(frontSensorAnalogPin) > 500) // Compare that value to about half of the battery voltage.
  {    
    digitalWrite(redLED,HIGH);   // Turn the LED on.
    specialDelay(100);  // Leave it on for a tenth of a second.
  }
  digitalWrite(redLED,LOW);  // Turn the LED off.
  specialDelay(100); // leave it off for a tenth of a second.
 
  if (analogRead(downSensorAnalogPin) > 500) // Compare that value to about half of the battery voltage.
  {    
    digitalWrite(redLED,HIGH);   // Turn the LED on.
    specialDelay(500);  // Leave it on for half of a second.
  }
  digitalWrite(redLED,LOW);  // Turn the LED off.
  specialDelay(100); // leave it off for a tenth of a second.
  
  if ( gyroMinReading < 200 && gyroMaxReading > 400 ) {
    analogWrite(redLED,255);
    specialDelay(20);
    for(i = 0; i<3; i++) {
    analogWrite(redLED,50);
    specialDelay(50);
    analogWrite(redLED,127);
    specialDelay(50);
    }
    analogWrite(redLED,255);
  }
}
