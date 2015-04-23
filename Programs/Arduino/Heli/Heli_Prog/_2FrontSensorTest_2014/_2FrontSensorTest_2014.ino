//This example code is in the public domain.
 
#include "DigiKeyboard.h" 
 
// New concept: "const". "const" tells the compiler that
// the thing that looks like a variable, isn't allowed to
// change. It is a CONSTant.
// The compiler will complain about any other lines of code
// that might change the value of a constant. This is useful
// for large programs.
const int redLED = 3; 
const int frontSensorAnalogPin = 2;
int front_sensor_val = 0; 

void setup() {                
  // initialize the outputs or inputs.
  pinMode(redLED,OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);  
}

// loop forever
void loop() {

  // Analog sensors read voltages as values from 0 to 1023.
  // Zero corresponds to ground. In this circuit, 1023 corresponds
  // the battery voltage. The analog circuitry is not perfect.
  // Don't be surprised if the values read change a little with
  // temperature, state of the battery, or after the helicopter
  // crashes a few times.
  
  // Rather than look for an exact value, we will just test
  // if the value is above or below about half of the battery
  // voltage.
  int front_sensor_val = analogRead(frontSensorAnalogPin);// read the sensor
  
  if (front_sensor_val > 500) // Compare that value to about half of the battery voltage.
  {    
    digitalWrite(redLED,HIGH);   // Turn the LED on.
    delay(100);  // Leave it on for a tenth of a second.
    digitalWrite(redLED,LOW);  // Turn the LED off.
    delay(100); // leave it off for a tenth of a second.
  }
  else{     //if it is < 500 do,
    digitalWrite(redLED,LOW); // Just to be sure, turn off the LED.
  }    //sets pin 3 to LOW
  
  //DigiKeyboard.println(down_sensor_val);    //prints values from var down sensor
  //DigiKeyboard.println(front_sensor_val);   //prints values from var front sensor
}
