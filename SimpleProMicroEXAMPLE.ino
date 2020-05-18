
// ____  ____  ____  ____  ____  ____  ____  ____  ____  ____ 
//||D ||||I ||||Y ||||C ||||h ||||a ||||r ||||l ||||e ||||s ||
//||__||||__||||__||||__||||__||||__||||__||||__||||__||||__||
//|/__\||/__\||/__\||/__\||/__\||/__\||/__\||/__\||/__\||/__\|
//
//


// To wire up a key connect one of the pins of
// the momentary switch to ground and the other pin
// to a digital pin 2,3,4,5,6,7,8,9,10,16,14,15,18,19,20,21
// The switch will activate the key when the pin is shorted
// to ground then it will delay so that the key is not input
// more times than desired.
// To program click the verify and upload then quickly 
// enter bootloader mode. If you don't do it fast enough
// it will not connect.
// To enter bootloader mode on the pro micro
// short the rst pin to the ground pin twice quickly.
// This will keep it in bootloader mode for 8s.

#include <Keyboard.h>

char ctrlKey = KEY_LEFT_GUI; //sets the left ctrl key for windows

void setup()
{ 
//  pinMode(6,INPUT_PULLUP);  // sets pin 6 to input & pulls it high w/ internal resistor
  pinMode(6,INPUT_PULLUP);  // z key
  pinMode(7,INPUT_PULLUP);  // ctrl+v paste shortcut 
  pinMode(8,INPUT_PULLUP);  // "hello world"

  Serial.begin(9600);       // begin serial comms for debugging
  Keyboard.begin();
    
}

void loop()
{
  if (digitalRead(6) == 0)  // the button is pressed and shorts to ground
    {
      Keyboard.write('z');  // send a 'z' to the computer via Keyboard HID
      delay(200);  // delay so you have time to release the key to only print once you can hold down the key to input multiple times
    }
    
  if (digitalRead(7) == 0)  // the button is pressed and shorts to ground
    {
      Keyboard.press(KEY_LEFT_CTRL); // inputs the ctrl key and holds
      Keyboard.press('v');  // inputs v in addition to ctrl
      delay(100); // delay to register combined keys
      Keyboard.releaseAll(); // releases the held keys
      delay(200);  // delay so you have time to release the key to only print once
    }

if (digitalRead(8) == 0)  // the button is pressed and shorts to ground
  {
    Keyboard.print("Hello, world");  // prints the string "Hello, world" with a single click
    delay(1000);  // delay so you have time to release the key to only print once

}



////  else if (digitalRead(5) == 0){  //if button 5 is pressed
////    Keyboard.write(0xB0);         // send Hex value for RETURN key
////    delay(200);
////  }
