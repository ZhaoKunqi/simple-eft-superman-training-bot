#include <Keyboard.h>;
#include <Mouse.h>;
bool alpha;
void setup(){
  attachInterrupt(1,startButton,FALLING);
  attachInterrupt(2,stopButton,FALLING);
  Mouse.begin();
  Keyboard.begin();
  alpha=false;
}
void(* resetFunc) (void) = 0;
void loop(){
  if(alpha){
    delay(50);
    Keyboard.press('w');
    delay(50);
    Keyboard.press(KEY_LEFT_SHIFT);
    delay(20000);
    Keyboard.releaseAll();
    delay(50);
    Keyboard.press('w');
    delay(20000);
    Keyboard.release('w');
    delay(50);
    turnBack();
    delay(50);
  }
}
void startButton(){
  alpha=true;
}
void stopButton(){
  alpha=false;
  delay(50);
  Keyboard.releaseAll();
  delay(50);
  resetFunc();
}
void turnBack(){
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(200,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(600,0,0);
  delayMicroseconds(10000);
  Mouse.move(1,0,0);
  delayMicroseconds(10000);
}

