// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void initLCD(){
	// initialize the LCD
	lcd.begin();
	// Turn on the blacklight
	lcd.backlight();
}

void lcdPrint(char message[]){
	lcd.print(message);
}

void lcdClear(){
	lcd.clear();
}