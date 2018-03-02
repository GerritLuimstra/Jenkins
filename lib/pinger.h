// Constants
const int pingOut = 13;
const int pingIn = 12;

// The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
void pulse_ping(){
  pinMode(pingOut, OUTPUT);
  digitalWrite(pingOut, LOW);
  delayMicroseconds(2);
  digitalWrite(pingOut, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingOut, LOW);
}

// The same pin is used to read the signal from the PING))): a HIGH pulse
// whose duration is the time (in microseconds) from the sending of the ping
// to the reception of its echo off of an object.
long get_ping_duration(){
  // Pulse first to get the best results
  pulse_ping();

  pinMode(pingIn, INPUT);
  return pulseIn(pingIn, HIGH);
}

bool object_detected(int threshold_cm){
    long duration = get_ping_duration();
    int cm = microsecondsToCentimeters(duration);
    return cm < threshold_cm;
}