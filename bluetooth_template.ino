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


//int wheel_left = 3;
//int wheel_right = 9;
//int wheel_left_backward = 2;
//int wheel_right_backward = 4;

int wheel_left = 2;
int wheel_right = 4;
int wheel_left_backward = 3;
int wheel_right_backward = 9;


// Constants (commands for the robots)
boolean wPressed, aPressed, sPressed, dPressed, 
        controlSignal, goToNextGame, dance,
        AutonomousMode;
char gameNumber;

void setup()
{
  // Begin the serial transmission of data
  mySerial.begin(38400);
  Serial.begin(38400);

  pinMode(wheel_left, OUTPUT);
  pinMode(wheel_right, OUTPUT);
  pinMode(wheel_left_backward, OUTPUT);
  pinMode(wheel_right_backward, OUTPUT);

  // Required for 'smoother' control of the robot
  mySerial.setTimeout(0);
  Serial.setTimeout(0);
}

// Checks whether there is bluetooth is available
boolean bluetoothAvailable() { return mySerial.available(); };

// Reads the info from the server (bluetooth) and sets the command variables accordingly
void setCommandVariables(){
  /*
   * Format 00000000
   * 0: W
   * 1: A
   * 2: S
   * 3: D
   * 4: I want control of the robot
   * 5: Game (numerical)
   * 6: Go to next game
   * 7: Dance
   */
  String data = mySerial.readString();
  data = data.substring(data.length() - 8);

  wPressed = data[0] == '1';
  aPressed = data[1] == '1';
  sPressed = data[2] == '1';
  dPressed = data[3] == '1';
  controlSignal = data[4] == '1';
  gameNumber = data[5];
  goToNextGame = data[6] == '1';
  dance = data[7] == '1';
  AutonomousMode = !controlSignal || goToNextGame;
}

void forward(){
  digitalWrite(wheel_left, HIGH);
  digitalWrite(wheel_right, HIGH);
  digitalWrite(wheel_left_backward, LOW);
  digitalWrite(wheel_right_backward, LOW);
}

void halt(){
  digitalWrite(wheel_left, LOW);
  digitalWrite(wheel_right, LOW);
  digitalWrite(wheel_left_backward, LOW);
  digitalWrite(wheel_right_backward, LOW);
}

void back(){
  digitalWrite(wheel_left, LOW);
  digitalWrite(wheel_right, LOW);
  digitalWrite(wheel_left_backward, HIGH);
  digitalWrite(wheel_right_backward, HIGH);
}

void left()
{
  digitalWrite(wheel_left, LOW);
  digitalWrite(wheel_right, HIGH);
  digitalWrite(wheel_left_backward, HIGH);
  digitalWrite(wheel_right_backward, LOW);
}

void right()
{
  digitalWrite(wheel_left, HIGH);
  digitalWrite(wheel_right, LOW);
  digitalWrite(wheel_right_backward, HIGH);
  digitalWrite(wheel_left_backward, LOW);
}

void loop() {
   // Read bluetooth data 
   while(bluetoothAvailable()) setCommandVariables();

   if(AutonomousMode){
    
      if(goToNextGame){
        
        Serial.println("Going to next game");
        // Magic here.
        
      } else {
         Serial.print("Playing game: ");Serial.print(gameNumber); Serial.print("\n");
      }
      
   } else {
      if(wPressed) forward();
      if(sPressed) back();
      if(aPressed) left();
      if(dPressed) right();
      if(!wPressed and !sPressed and !aPressed and !dPressed) halt();    
   }
}
