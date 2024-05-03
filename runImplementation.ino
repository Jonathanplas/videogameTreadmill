#include <Keyboard.h>

// use this option for OSX:
char ctrlKey = KEY_LEFT_GUI;

int ir_pin = 8;
int counter = 0;
int state = HIGH;
int spokePass = false;
int blipsPerRev = 8;
unsigned long timeOne = 0;
unsigned long timeTwo = 0;

void setup(){

  Serial.begin(9600);
  pinMode(ir_pin,INPUT);

  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {

  timeTwo = millis();

  
  int val = digitalRead(ir_pin);

  if( (val == 0) && (spokePass == false) ){

    counter++;
    spokePass = true;
    Serial.print ("Counter = ");
    Serial.println( counter );
    
    if (timeTwo - timeOne <= 88) { //I think about 67 milliseconds between each spoke at 3 miles an hour
        Keyboard.press('u');
        delay(250);
        Keyboard.releaseAll();
        delay(10);    
    } else {

      Keyboard.press('w');
      delay(100);
      Keyboard.releaseAll();
      delay(10);
    }  
    
  } else if ( (val == 1) && (spokePass == true) ) {
    
    spokePass = false;
  }

  timeOne = timeTwo;
}
