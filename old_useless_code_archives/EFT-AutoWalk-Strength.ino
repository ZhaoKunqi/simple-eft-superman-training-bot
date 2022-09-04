/*
 * This is a sketch that can upload to Arduino Leonardo
 * Use for Strength Skill training in PC video game <Escape From Tarkov>
 * All function in this sketch is make overweight PMC keep walking in a small space
 * Keep using this sketch 10 min,the overweight PMC's Strength skill will increase 2.5
 * Keep using this sketch 20 min,the overweight PMC's Strength skill will increase 5.0
 * Keep using this sketch 30 min,the overweight PMC's Strength skill will increase 7.5
 */
#include <Keyboard.h>
#include <Mouse.h>
bool alpha; //Setup a public bool var for interrupt button status
void setup(){
  attachInterrupt(1,startButton,FALLING); //Blue button for start walking
  attachInterrupt(2,stopButton,FALLING); //Red button for stop walking
  Mouse.begin();
  Keyboard.begin();
  alpha=false; //Setup default vaule as false make working will not start automatic
}
void loop(){
  if(alpha){
    Mouse.move(1,0,0); //If Blue button been hit before,this will running
  }
}
void startButton(){
  alpha=true; //Set alpha as true make loop enable
  Keyboard.press('w'); //Press and hold the 'w' on keyboard to start walking
}
void stopButton(){
  alpha=false; //Set alpha as false make loop disable
  Keyboard.release('w'); //Release 'w' on keyboard to stop walking 
  Keyboard.releaseAll(); //Release all button to make sure walking are stoped
}

