// Engine constants
const int left_wheel = 3;
const int left_wheel_backwards = 2;
const int right_wheel = 9;
const int right_wheel_backwards = 4;


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