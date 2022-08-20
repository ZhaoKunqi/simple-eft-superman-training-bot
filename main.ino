//Tarkov Superman Training Bot
//Version: FA.2.1
//Auther: 
//Display resolution requirements: No specific requirements, but must be 16:9, for example : (1600*900),(1920*1080),(2560*1440)
#include "HID-Project.h" 
//Declare usage of HID-Project.h library in this project. 
//This project use HID-Project.h library for controlling the movement output to USB host via features that it provided including "Absolute Positioning Mouse" "Relative Positioning Mouse" "Keyboard" 
#include <elapsedMillis.h> //Declare usage of elapsedMillis library, this project use elapsedMillis library as a simple time counter.
void setup() {
  delay(100);//Delay is required to reduce the possibility of failed execution or some USB connection problem. this also apply to all other delay in this project.
  Keyboard.begin(); //Start the virtual USB device "Keyboard"
  delay(100);
  AbsoluteMouse.begin();//Start the virtual USB device "Absolute Positioning Mouse"
  delay(100);
  Mouse.begin();//Start the virtual USB device "Mouse" aka the "Relative Positioning Mouse"
  delay(10000);//Wait 10 seconds before program execution , this reserved time is for re-uploading program or adjusting things in the USB host end before it starting pushing "W" button and running around while continually moving your mouse when you don't want it to happen.
}

void loop() {
  enterRaid(); //call enterRaid function here for condition including "First time in cycle,game still in lobby and waiting to start","PMC got KIA in raid and after backToLobby function were executed, game in lobby and needs to enter the raid again". Also If PMC still alive in raid, this function will only make PMC waving melee weapon few times.
  //beginning exercising cycle
  walkingCycle();
  runningCycle();
  covertMovementCycle();
  //end exercising cycle
  backToLobby();//call backToLobby function here for condition of PMC got KIA in raid back to game lobby,same as the enterRaid function,if PMC still alive in raid, this function will only make PMC waving melee weapon few times.
  //beginning exercising cycle
  walkingCycle();
  runningCycle();
  covertMovementCycle();
  //end exercising cycle
}

void walkingCycle(){
  // Easy walking cycle function
  startWalking(); //Press and hold "W" key to start walking
  //Set a 20 seconds timer continuously moving mouse towards right, make PMC circling in a limited area.
  elapsedMillis timeElapsed;
  unsigned int interval = 20000; //20 seconds timer
  while(timeElapsed < interval){ 
    //the following lines of codes is for a single cycle of mouse moving, it will loop and execute many cycles as possible during this 20 seconds timer.
    Mouse.move(3, 0);
    delay(2);
  }
  resetMoving(); //call resetMoving function, basically just release "W" key , and stop PMC from walking.
  delay(300); //relax 0.3 second and return to main loop, for next exercising.
}
void runningCycle(){
  startRunning(); //Similar to function "startWalking",it just added the press and hold left shift key in it.
  elapsedMillis timeElapsed; //Same as "walkingCycle" function. 20 seconds timer continuously moving mouse towards right, make PMC circling in a limited area, but running.
  unsigned int interval = 20000; //20s
  while(timeElapsed < interval){
    Mouse.move(5, 0);
    delay(1);
  }
  resetMoving();//call resetMoving function, release both "W" and "Left Shift" key , and stop PMC from running.
  delay(300);//He deserved this really short break time after running 20 seconds.
}
void covertMovementCycle(){
  //convert movement is a bit different from walking and running,it have 3 moves. The "SpeedDown","Moving Mouse","SpeedUp"
  //SpeedDown, scroll down mouse wheel to lowest walking speed, scroll many times as possible in 1.5 second.
  elapsedMillis timeElapsedSpeedDown;
  unsigned int intervalSpeedDown = 1500; //1.5s
  while(timeElapsedSpeedDown < intervalSpeedDown){
    Mouse.move(0,0,-1);
    delay(50);
  }
  //PMC walking speed now is the lowest as possible.
  startWalking();
  //and continuously moving mouse slowly after start walking in lowest speed.
  elapsedMillis timeElapsed;
  unsigned int interval = 20000; //20s
  while(timeElapsed < interval){
    Mouse.move(3, 0,0);
    delay(2);
  }
  delay(10);
  resetMoving();// release all key after 20 seconds of convert movement walking
  //SpeedUp, Similar to SpeedDown, scrolling mouse wheel up in 1.5 second.
  elapsedMillis timeElapsedSpeedUp;
  unsigned int intervalSpeedUp = 1500;
  while(timeElapsedSpeedUp < intervalSpeedUp){
    Mouse.move(0,0,1);
    delay(50);
  }
  delay(300);// The 20 seconds of ninja's walking posture is also very tired, please .
}


void startWalking(){
  Keyboard.press('w');//I am afraid that only people who have lost advanced cognitive abilities will fail to understand the meaning of this line of code.
}
void startRunning(){
  Keyboard.press('w');
  delay(100);// add some delay make it smother.
  Keyboard.press(KEY_LEFT_SHIFT);
}

void resetMoving(){
  Keyboard.releaseAll();//I am afraid that only people who have lost advanced cognitive abilities will fail to understand the meaning of this line of code.
}
void enterRaid(){
  delay(300);
  AbsoluteMouse.moveTo(0, 6000); //Move to "Escape from Tarkov" button
  clickLeftMouseButton();
  AbsoluteMouse.moveTo(0, 23210); //Move to "NEXT" button
  clickLeftMouseButton();
  AbsoluteMouse.moveTo(-13030,-1547); //Move to default "Shoreline" button
  //Also you can modified map selection movement by yourself.
  //There is a coordinate list of maps in the game:
  //Interchange (-307,-14700)
  //Woods (-9728,-12242)
  //Customs(-2688,-10922)
  //Factory(-7552,-5961) wtf ? are you sure about that ?
  //Reserve(-13030,-1547)
  //Shoreline (-9728, 10467)
  clickLeftMouseButton();
  AbsoluteMouse.moveTo(10163, 28535); //Move to "Ready" button
  clickLeftMouseButton();
}
void backToLobby(){
  delay(300);
  AbsoluteMouse.moveTo(0, 25486); //Move to "Next" button
  //Click "Next" button 4 times
  clickLeftMouseButton(); 
  clickLeftMouseButton(); 
  clickLeftMouseButton(); 
  clickLeftMouseButton(); 
  AbsoluteMouse.moveTo(-5529, -13380); //Move to "General health condition" button
  clickLeftMouseButton(); //Click "General health condition" button to deselect it, because bot only needs heal bleeding and fracture 
  AbsoluteMouse.moveTo(11136, 25486); //Move to "Apply" button 
  clickLeftMouseButton(); //Click "Apply" button to heal PMC's bleeding and fractures
  AbsoluteMouse.moveTo(0, 25486); //Move to "Next" button
  clickLeftMouseButton(); //Click "Next" button to and back to lobby
}
void clickLeftMouseButton(){
  delay(300);
  AbsoluteMouse.click();//I am afraid that only people who have lost advanced cognitive abilities will fail to understand the meaning of this line of code.
  delay(300);
}
