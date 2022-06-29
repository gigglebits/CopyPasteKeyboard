#include <Keyboard.h>

#define C_KEY 'c'
#define V_KEY 'v'
char ctrlKey = KEY_LEFT_GUI;
#define C_KEY_PIN A1
#define V_KEY_PIN A0

bool cPressed = 0;
bool vPressed = 0;

void setup() {
  Serial.begin(9600);

  pinMode(C_KEY_PIN, INPUT_PULLUP);
  pinMode(V_KEY_PIN, INPUT_PULLUP);
}

void loop() {
  bool cPressed = digitalRead(C_KEY_PIN);
  bool vPressed = digitalRead(V_KEY_PIN);

  if(!cPressed){
    Keyboard.press(ctrlKey);
    Keyboard.press(C_KEY);
  }else{
    Keyboard.releaseAll();
  }
  
  if(!vPressed){
    Keyboard.press(ctrlKey);
    Keyboard.press(V_KEY);
  }else{
    Keyboard.releaseAll();
  }
  
  if(vPressed && cPressed){
    delay(10);
  }
}
