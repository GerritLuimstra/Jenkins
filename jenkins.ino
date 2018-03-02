// Require all the libs
#include "lib/helper.h"
#include "lib/lcd.h"
#include "lib/engine.h"
#include "lib/bluetooth.h"
#include "lib/pinger.h"

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  // Enable the serial port to display log messages
  Serial.begin(9600);
    
  // initialize the LCD
  lcd.begin();
  
  // Turn on the blacklight
  lcd.backlight();
  
  // Show the init message
  lcd.print("Jenkins - Ready");
  delay(1000);
  lcd.clear();
  lcd.print("Jenkins - ");
  lcd.print("Engine booting up");
  delay(2000);
}

void loop() {
  lcd.clear();
  /*
   * Pinger code
   */
   if(object_detected(10)){
      lcd.print("Detected");
   } else {
      lcd.print("Not Detected");
   }

   delay(1000);
}
