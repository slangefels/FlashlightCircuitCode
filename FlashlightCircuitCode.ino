//FlashlightCircuit+Code
//AME 330 Fall 2024
//Shannon Langefels

/*

  Written using my ArduinoCodingTutorial program as a reference, which in turn is based off of 
  this tutorial: https://forum.arduino.cc/t/planning-and-implementing-an-arduino-program/252364/ 


Hardware:

Arduino Mega 2650 ----> I tried to use the new SparkFun microcontroller but was having issues.
1 green LED
1 red LED
1 push button
9V battery
(2) 1k ohm resistors for LEDs
220 ohm resistor for push button
connecting wires

*/

//for push button
const byte pushButtonPin = 9; //pin that the push button is connected to
int pushButtonState; //indicates status of push button

//for LEDs
const byte greenLEDpin = 13; //pin for green LED
const byte redLEDpin = 12; //pin for red LED

//Unity
int unitySwitchStatus = 0; //indicates switch variable status in Unity, initialized to 0/off for now


void setup() {
  // put your setup code here, to run once:

  //push button
  pinMode(pushButtonPin, INPUT); //set push buttpn pin as input

  //LEDs
  pinMode(greenLEDpin, OUTPUT); //green LED set to output
  pinMode(redLEDpin, OUTPUT); //green LED set to output
  digitalWrite(greenLEDpin, LOW); //green LED is off
  digitalWrite(redLEDpin, LOW); //red LED is off


  //Serial communication used for printing test messages
  Serial.begin(9600); //start Serial communication 
  Serial.println("Starting FlashlightCircuitCode.ino"); //test print

}

void loop() {
  // put your main code here, to run repeatedly:

  checkPushButton();
  updateGreenLED();

  //test print:
  Serial.print("pushButtonState = ");
  Serial.println(pushButtonState);

  //Unity side not currently set up, but if it was we would probably:
    //send the state of the push button to Unity
    //recieve data from Unity 
    //update red LED based on data from Unity
  updateRedLED(); //unitySwitchStatus is set to a dummy value of 0 currently (because we aren't recieving data from Unity yet) so the red LED will just stay off

}

void checkPushButton() {
  //store input read from push button
  pushButtonState = digitalRead(pushButtonPin);

}

void updateGreenLED() {
  if (pushButtonState == 1) { //if push button is not pressed, green LED is off
    digitalWrite(greenLEDpin, LOW); //turn green LED off
    return;
    
  }
  //if push button is pressed (== 0), green LED is on
  digitalWrite(greenLEDpin, HIGH); //turn green LED on

}

void updateRedLED() {
  if (unitySwitchStatus == 0) { //if switch variable in Unity = 0 (virtual flashlight is off), red LED is off
    digitalWrite(redLEDpin, LOW); //turn red LED off
    return;
    
  }
  //if switch variable in Unity = 1 (virtual flashlight is on), red LED is on
  digitalWrite(redLEDpin, HIGH); //turn red LED on

}
