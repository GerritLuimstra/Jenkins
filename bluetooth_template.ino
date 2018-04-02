/**
 * Powered by Jenkins (c)
 * 
 * Remote controllable robot template
 * NOTE: The server only sends CHANGES in commands (to reduce latency), so it's NOT a continous stream of data
 */

#include <Wire.h>
#include <SoftwareSerial.h>

// Setup the Bluetooth serial object
SoftwareSerial mySerial(A0, A1); // RX, TX

// Constants (commands for the robots)
boolean wPressed, aPressed, sPressed, dPressed;

void setup()
{
  // Begin the serial transmission of data
  mySerial.begin(38400);
  Serial.begin(38400);

  // Required for 'smoother' control of the robot
  mySerial.setTimeout(0);
  Serial.setTimeout(0);
}

// Checks whether there is bluetooth is available
boolean bluetoothAvailable() { return mySerial.available(); };

// Reads the info from the server (bluetooth) and sets the command variables accordingly
void setCommandVariables(){
  String data = mySerial.readString();
  data = data.substring(data.length() - 4);

  wPressed = data[0] == '1';
  aPressed = data[1] == '1';
  sPressed = data[2] == '1';
  dPressed = data[3] == '1';
}

void loop() {
   // Read bluetooth data 
   while(bluetoothAvailable()) setCommandVariables();
       
   if(wPressed){
      // Magic here!
   }
}
