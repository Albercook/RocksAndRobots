// There is a red LED on connected to a pin on the processor.
// Referring to it by number is not very informative, 
// particularly, if a future version has the red LED connected to
// another pin.
// We will give it a name, and only refer to it by that name everywhere.
// Only the next line needs to know which pin has the red LED.
int redLED = 3; // The red LED is on pin 3 in this hardware version. 

// setup() gets called once before anything else. 
// You will see it in each of these programs.
// Remember this, as we will just assume you know this
// in all of the other examples.
void setup()
{
  pinMode(redLED, OUTPUT);    //Declares the pin with the red LED to be an output   
}

// loop() gets called repeatedly.
void loop()
{
  digitalWrite(redLED, HIGH); // The LED is connected through a resistor
                              // to ground. Setting the pin high, turns
                              // the LED on.
  delay(100);    //wait one tenth of second, so the human can see the LED.
  digitalWrite(redLED, LOW);    // Setting the pin low, means this side
                                // of the LED is also electrically connected
                                // to ground. So the LED is off.
  delay(900);   //Leave it off for 9 tenths of a second.
}
