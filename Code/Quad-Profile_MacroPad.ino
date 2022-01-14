/*   Rayyan Nasser & Gabe Cordova
 *   Digital Electronics Final Project
 *   Quad-Profile MacroPad
 */

//libraries
#include <Keypad.h>
#include <Encoder.h>
#include <Bounce2.h>
#include "HID-Project.h"

//Creating the Keypad
byte R1 = 21;
byte R2 = 20;
byte R3 = 5;
byte R4 = 6;
byte C1 = 7;
byte C2 = 8;
byte C3 = 9;
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'0','*','X'},
  {'9','8','7'},
  {'6','5','4'},
  {'3','2','1'}
};
byte rowPins[ROWS] = {R1, R2, R3, R4};
byte colPins[COLS] = {C1, C2, C3};
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//Profile LED
int S1 = 15;
int S2 = 14;
int S3 = 16;
int S4 = 10;
const int numStates = 4;
const int States[numStates] = {S1, S2, S3, S4};
int currentState = 0;

//Rotary Encoder
int SW = 19;
int DT = 2;
int CLK = 3;
Encoder volumeKnob(DT,CLK);
Bounce encoderButton = Bounce(SW,10);
int timeLimit = 500;
long oldPosition = -999;

void setup() {
  
  Serial.begin(9600);
  
  for (int i = 0; i < numStates; i++){
    pinMode(States[i], OUTPUT);
    digitalWrite(States[i], LOW);
  }

  pinMode(CLK, INPUT_PULLUP);
  Keyboard.begin();
  StartAnimation();
  digitalWrite(States[currentState], HIGH);
}

//Start LED Animation
void StartAnimation(){
  int waitTime = 250;
  digitalWrite(S1, HIGH);
  delay(waitTime);
  digitalWrite(S2, HIGH);
  delay(waitTime);
  digitalWrite(S3, HIGH);
  delay(waitTime);
  digitalWrite(S4, HIGH);
  delay(waitTime);
  digitalWrite(S1, LOW);
  delay(waitTime);
  digitalWrite(S2, LOW);
  delay(waitTime);
  digitalWrite(S3, LOW);
  delay(waitTime);
  digitalWrite(S4, LOW);
  delay(waitTime);
  return;
}

//Change Profiles
void ChangeState(){
  digitalWrite(States[currentState], LOW);
  currentState++;
  if (currentState == numStates){
    currentState = 0;
  }
  digitalWrite(States[currentState], HIGH);
  delay(100);
  return;
}

/*  You can freely change the function of each button
 *  Use Keyboard.print() for single words/characters (Examples in profiles 3 and 4)
 *  Use Keyboard.press() and Keyboard.releaseAll() keyboard shortcuts (Example in profile 2)
 */
//Profile 1
void Layout1(char button){
  switch(button){
    case '1':
      //put button function here
      break;
    case '2':
      
      break;
    case '3':
      
      break;
    case '4':
      
      break;
    case '5':
      
      break;
    case '6':
      
      break;
    case '7':
      
      break;
    case '8':
      
      break;
    case '9':
      
      break;
    case '0':
      
      break;
  };
}

//Profile 2
void Layout2(char button){
  switch(button){
    case '1':
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('c');
      delay(150);
      Keyboard.releaseAll();
      break;
    case '2':
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('v');
      delay(150);
      Keyboard.releaseAll();
      break;
    case '3':
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('t');
      delay(150);
      Keyboard.releaseAll();
      break;
    case '4':
      
      break;
    case '5':
      
      break;
    case '6':
      
      break;
    case '7':
      
      break;
    case '8':
      
      break;
    case '9':
      
      break;
    case '0':
      
      break;
  };
}

//Profile 3
void Layout3(char button){
  switch(button){
    case '1':
      Keyboard.print('1');
      break;
    case '2':
      Keyboard.print('2');
      break;
    case '3':
      Keyboard.print('3');
      break;
    case '4':
      Keyboard.print('4');
      break;
    case '5':
      Keyboard.print('5');
      break;
    case '6':
      Keyboard.print('6');
      break;
    case '7':
      Keyboard.print('7');
      break;
    case '8':
      Keyboard.print('8');
      break;
    case '9':
      Keyboard.print('9');
      break;
    case '0':
      Keyboard.print('0');
      break;
  };
}

//Profile 4
void Layout4(char button){
  switch(button){
    case '1':
      Keyboard.print('a');
      break;
    case '2':
      Keyboard.print('b');
      break;
    case '3':
      Keyboard.print('c');
      break;
    case '4':
      Keyboard.print('d');
      break;
    case '5':
      Keyboard.print('e');
      break;
    case '6':
      Keyboard.print('f');
      break;
    case '7':
      Keyboard.print('g');
      break;
    case '8':
      Keyboard.print('h');
      break;
    case '9':
      Keyboard.print('i');
      break;
    case '0':
      Keyboard.print('j');
      break;
  };
}

void loop() {
  //check the button matrix
  char key = kpd.getKey();
  if(key) {
    switch(key){
      case '*':
        ChangeState();
        break;
      default:
        switch(currentState){
          case 0:
            Layout1(key);
            break;
          case 1:
            Layout2(key);
            break;
          case 2:
            Layout3(key);
            break;
          case 3: 
            Layout4(key);
            break;
        }
    }
  }

  //Rotary Encoder Button
  if(encoderButton.update()) {
    if(encoderButton.fallingEdge()) {
      int fall = millis();
      while(!encoderButton.update()){}
      if(encoderButton.risingEdge()){
        int rise = millis();
        if(rise - fall > timeLimit){
          Consumer.write(MEDIA_NEXT);
        } else {
          Consumer.write(MEDIA_PLAY_PAUSE);
        }
      }
      Keyboard.releaseAll();
    }
  }

  //Rotary Encoder Rotation
  long newPosition;
  newPosition = volumeKnob.read();
  if(newPosition != oldPosition){
    if(newPosition > oldPosition) {
      //volumeup
      Consumer.write(MEDIA_VOLUME_UP);
    } 
    else if(newPosition < oldPosition) {
      //volumedown
      Consumer.write(MEDIA_VOLUME_DOWN);
    }
    oldPosition = newPosition;
    Keyboard.releaseAll();
    delay(200);
  }  
}
