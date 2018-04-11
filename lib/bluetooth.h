// Setup the Bluetooth serial object
extern SoftwareSerial mySerial(A0, A1); // RX, TX

// Constants (commands for the robots)
boolean wPressed, aPressed, sPressed, dPressed, 
        controlSignal, goToNextGame, dance,
        AutonomousMode;
char gameNumber;

void prepareBluetooth(){
	// Begin the serial transmission of data
	mySerial.begin(38400);
	// Enable smooth data recieval
	mySerial.setTimeout(0);
}


// Checks whether there is bluetooth is available
boolean bluetoothAvailable() { return mySerial.available(); };

// Reads the info from the server (bluetooth) and sets the command variables accordingly
extern void setCommandVariables(){
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