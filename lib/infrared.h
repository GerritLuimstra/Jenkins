const int leftIRPin = 10;
const int rightIRPin = 11;

void prepareInfraRed(){
	pinMode(leftIRPin, INPUT);
	pinMode(rightIRPin, INPUT);
}

boolean leftInfraRed(){
	return digitalRead(leftIRPin);
}

boolean rightInfraRed(){
	return digitalRead(rightIRPin);
}