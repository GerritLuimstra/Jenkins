// Require all them libs
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include "lib/infrared.h"
#include "lib/helper.h"
#include "lib/engine.h"
#include "lib/pinger.h"
#include "lib/bluetooth.h"
#include "lib/lcd.h"
#include "lib/games.h"

void setup() {

  // Give that good ol' engine a swing
  setupEngine();

  // Initialize the LCD
  initLCD();

  // Prepare the bluetooth module for receiving data
  prepareBluetooth();

  // Prepare the infra red sensors
  prepareInfraRed();

  // Enable the printing of messages in the console
  Serial.begin(38400);
  Serial.setTimeout(0);
}

void loop() {
  
  // If there is new bluetooth data, set the new commands
  while(bluetoothAvailable()) setCommandVariables();

  /*
   * Available variables (commands):
   * - wPressed : Is the W key being pressed on the website?
   * - aPressed : Is the A key being pressed on the website?
   * - sPressed : Is the S key being pressed on the website?
   * - dPressed : Is the D key being pressed on the website?
   * - AutonomousMode : Should the car do something on its own?
   * - goToNextGame : Is the car constructed to go to the next game?
   * - gameNumber : The number the game should play when it is in autonomous mode
   *   - This will be '1' for the Maze and '2' for the Rat Race
   */

  // If we are in autonomous mode (we are NOT controlling)
  if(AutonomousMode){

      // If the go to the next game bit is active
      if(goToNextGame){

        // We should just go straight
        straight();
        
      } else {
         if(gameNumber == '1'){
            theMaze();
         }
         if(gameNumber == '2'){
            ratRace();
         }
      }
      
   } else {
      // Self explanatory control code
      if(wPressed) straight();
      if(sPressed) reverse();
      if(aPressed) left();
      if(dPressed) right();
      if(!wPressed and !sPressed and !aPressed and !dPressed) halt();
   }
}
