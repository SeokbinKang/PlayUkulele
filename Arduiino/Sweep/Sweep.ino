// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.
#include <Servo.h>

Servo servoG;
Servo servoC;
Servo servoF;
Servo servoA;
Servo servoString1;
Servo servoString2;
int pos = 0; // todo: might need min/max angles

int stringinPlay=0;
int stringpos1=0;
int stringpos2=0;

void setup() {
  // todo: check these pins will work
  servoG.attach(9);
  servoC.attach(10);
  servoF.attach(11);
  servoA.attach(12);
  servoString1.attach(3);
  servoString2.attach(5);
  // make sure in the right positions
  servoG.write(0);
  servoC.write(180);
  servoF.write(170);
  servoA.write(180);
  servoString1.write(0);  
  servoString1.write(0);
  Serial.begin(115200);
}
char testc = 'C';
void loop() 
{
  // todo: read in an actual chord value here
  char chord = 'C';
  
  while (Serial.available() > 0) {
      int play = Serial.parseInt();
      int chord_i = Serial.parseInt();
      if (Serial.read() == '\n') {
         switch (chord_i) {
        case 1:
          // statements
          chord = 'C';
          break;
        case 2:
          chord = 'F';
          // statements
          break;
        case 3:
          chord = 'A';
          break;
        case 4:
          chord = 'A';
          break;
        default: 
          chord = 'X';
        // statements
      }
       if(play>0) loopString();
       if(chord != 'X') {
          setUpChord(chord);      
       } 
      }
  }
  //loopString();
  //setUpChord(testc);
  if(testc=='C') testc='F'; 
    else if(testc=='F')testc='A';
    else if(testc=='A')testc='C';
  //delay(1000); 

  return ;
  setUpChord(chord);
  delay(100); // however long we will be playing that chord
  stopChord(chord);
 }

int state=0;
void loopString() {
  if(state==0){
/*  for(pos = 0; pos < 70; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servoString1.write(pos);              // tell servo to go to position in variable 'pos' 
     servoString2.write(pos);
    delay(1);                       // waits 15ms for the servo to reach the position 
  }*/
   servoString1.write(70);
   state=1; 
  } else {
  /*for(pos = 70; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servoString1.write(pos);              // tell servo to go to position in variable 'pos' 
     servoString2.write(pos);
    delay(1);                       // waits 15ms for the servo to reach the position 
  }*/
   servoString1.write(1);
  
   state=0;
  }
}
// move into position to play chord
void setUpChord(char chord) {
  Servo s = servoG;
  if (chord == 'C'){
    servoC.write(120);
    servoF.write(160);
    servoA.write(150);
    
    s = servoC;
  }
  else if (chord == 'F'){
    servoC.write(180);
    servoF.write(145);
    servoA.write(150);    
    s = servoF;}
  else if (chord == 'A'){
    servoC.write(180);
    servoF.write(160);
    servoA.write(95);
    s = servoA;
  }

  /*for (pos = 0; pos <= 180; pos++) {
    s.write(pos);
    delay(5);
  }*/
}

// move back to neutral position
void stopChord(char chord) {
  Servo s = servoG;
  if (chord == 'C')
    s = servoC;
  else if (chord == 'F')
    s = servoF;
  else if (chord == 'A')
    s = servoA;

  for (pos = 180; pos >= 0; pos--) {
    s.write(pos);
    delay(5);
  }
}


