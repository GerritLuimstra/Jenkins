#define E1 11
#define E2 6
#include "gyro.h"

// Engine constants
const int left_wheel = 3;
const int left_wheel_backwards = 2;
const int right_wheel = 9;
const int right_wheel_backwards = 4;

void setupEngine(){
  pinMode(left_wheel, OUTPUT);
  pinMode(right_wheel, OUTPUT);
  pinMode(left_wheel_backwards, OUTPUT);
  pinMode(right_wheel_backwards, OUTPUT);
}


/*
 * Controls a given wheel
 * @param wheel The wheel to control
 * @param backwards Make the wheel drive backwards
 * @param state The wheel is spinning
 */
void control_wheel(char wheel[], boolean backwards, boolean state){
  if(wheel == "left"){
    digitalWrite((backwards == true) ? left_wheel_backwards : left_wheel, state);
  } else {
    digitalWrite((backwards == true) ? right_wheel_backwards : right_wheel, state);
  }
}

/*
 * Make all wheels stop
 */
void halt(){
  control_wheel("left", true, LOW);
  control_wheel("left", false, LOW);
  control_wheel("right", true, LOW);
  control_wheel("right", false, LOW);
}

/*
 * Make the car go straight ahead
 * (so not in reverse)
 */
void straight(){
  // Disable backwards
  control_wheel("left", true, LOW);
  control_wheel("right", true, LOW);

  // Enable going forward on both wheels
  control_wheel("left", false, HIGH);
  control_wheel("right", false, HIGH);    
}

/*
 * Make the car go left
 */
void left(){
	control_wheel("left", false, false);
	control_wheel("left", true, true);
	control_wheel("right", true, false);
	control_wheel("right", false, true);
}

/*
 * Make the car go right
 */
void right(){
	control_wheel("right", false, false);
	control_wheel("right", true, true);
	control_wheel("left", true, false);
	control_wheel("left", false, true);
}

 /*
 * Make the car go reversed
 * (so not going forward)
 */
void reverse(){
  // Disable going forward
  control_wheel("left", false, LOW);
  control_wheel("right", false, LOW);

  // Enable going backwards on both wheels
  control_wheel("left", true, HIGH);
  control_wheel("right", true, HIGH);    
}

void forwardSpeed(int speed)
{
  analogWrite(left_wheel, speed);
  digitalWrite(left_wheel_backwards, LOW);
  analogWrite(right_wheel, speed);
  digitalWrite(right_wheel_backwards, LOW);
}

void turnRight90()
{
  double startPosition = getZ();
  if(startPosition >= 0 && startPosition < 270)
  {
    while(getZ() < startPosition + 90)
    {
      right();
    }
    halt();
  }
  else
  {
    while((getZ() > startPosition) || (getZ() < (90 - (360 - startPosition))))
    {
      right();
    }
    halt();
  }
}

void turnLeft90()
{
  double startPosition = getZ();
  if(startPosition <= 360 && startPosition > 90)
  {
    while(getZ() > startPosition - 90)
    {
      left();
    }
    halt();
  }
  else
  {
    while((getZ() < startPosition) || (getZ() > (360 - (90 - startPosition))))
    {
      left();
    }
    halt();
  }
}

void turnAround180()
{
  double startPosition = getZ();
  if(startPosition >= 0 && startPosition < 180)
  {
    while(getZ() < startPosition + 180)
    {
      right();
    }
    halt();
  }
  else
  {
    while((getZ() > startPosition) || (getZ() < (180 - (360 - startPosition))))
    {
      right();
    }
    halt();
  }
}