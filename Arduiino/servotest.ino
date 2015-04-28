#include <Servo.h>

Servo servoG;
Servo servoC;
Servo servoF;
Servo servoAm;

int pos = 0; // todo: might need min/max angles

void setup() {
  // todo: check these pins will work
  servoG.attach(9);
  servoC.attach(10);
  servoF.attach(11);
  servoAm.attach(12);
  
  // make sure in the right positions
  servoG.write(0);
  servoC.write(0);
  servoF.write(0);
  servoAm.write(0);
}

void loop() 
{
  // todo: read in an actual chord value here
  char chord = 'C';
  
  setUpChord(chord);
  delay(100); // however long we will be playing that chord
  stopChord(chord);
 }

// move into position to play chord
void setUpChord(char chord) {
  Servo s = servoG;
  if (chord == 'C')
    s = servoC;
  else if (chord == 'F')
    s = servoF;
  else if (chord == 'Am')
    s = servoAm;

  for (pos = 0; pos <= 180; pos++) {
    s.write(pos);
    delay(5);
  }
}

// move back to neutral position
void stopChord(char chord) {
  Servo s = servoG;
  if (chord == 'C')
    s = servoC;
  else if (chord == 'F')
    s = servoF;
  else if (chord == 'Am')
    s = servoAm;

  for (pos = 180; pos >= 0; pos--) {
    s.write(pos);
    delay(5);
  }
}

