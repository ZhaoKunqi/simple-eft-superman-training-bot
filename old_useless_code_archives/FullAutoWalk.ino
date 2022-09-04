#include <TimerOne.h>
#include <Keyboard.h>
#include <Mouse.h>
int timerCount;
void setup(){
  Timer1.initialize(3000000);
  delay(30);
  Timer1.attachInterrupt(timerInterrupt);
  delay(30);
  Mouse.begin();
  delay(30);
  Keyboard.begin();
  delay(30);
  timerCount=0;
  delay(3000);
  Keyboard.press('w');
}
void loop(){
  Mouse.move(1,0,0);
  delay(3);
}
void timerInterrupt(){
  if(timerCount<=6){
    timerCount++;
  }else{
    timerCount=0;
    stopAndStart;
  }
}
void stopAndStart(){
  delay(30);
  Keyboard.release('w');
  delay(500);
  Keyboard.press('w');
  delay(30);
}

