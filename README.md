# Escape from Tarkov: Super Fierce Hatchling Full-Auto training bot

[English Document(This page)](README.md) 

This bot is based on Arduino board that have USB capabilities, tested on Arduino Leonardo and Arduino Pro Micro(ATmega32u4).

# What super fierce hatchling training bot dose ?

this little project uses Arduino boards simulate Keyboards & Mice & Tablet , controlling your PC that running Escape from Tarkov game instance, mainly leveling up your in-game skills "**Endurance**", "**Strength**", "**Covert Movement**".

# How to run this bot and training your own muscle rat ?

1. You'll need a Arduino board that have ATmega32u4 processor on it(or supporting USB capabilitie), my recommendation is Arduino Leonardo(Arduino Official) or Arduino Pro Micro(3rd-party edition), because I've working on those 2 module for quite a while and all function running normal on those 2 module, if you have other Arduino board that supports USB, please feel free try it out yourself.
  
2. You'll need a PC capable to run EFT game instance at [1280x720 , minimal graphic quality, 30 FPS or higher]
  
3. You'll need Arduino IDE to upload the program into the board so your board can execute it.
  
4. No specific display resolution requirements, but must be 16:9, for example : 1280x720, 1600x900 , 1920x1080 , 2560x1440
  

# How to upload the program into Arduino board ?

1. First ,you'll need install Arduino IDE, if you don't have Arduino IDE installed or have no idea how to install it , you can check Arduino's tutorial here https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing
  
2. And then, you'll need install some additional libraries from Arduino's repository, you'll need both "HID-Project" and "elapsedMillis" libraries installed, if you don't know how to install it , you can check Arduino's tutorial here https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-installing-a-library
  
3. Now you can upload those code into your Arduino board via USB connection, if you don't know how, you can read this tutorial from Arduino here https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-uploading-a-sketch
  
  ## If it says "uploading done" , then congratulations !
  
  ## Your Arduino board will start running muscle rat about 10 second later~
  

# Tips:

1. recommend settings for EFT
  
  - [x] Display resolution - 1280x720
    
  - [x] Display method - fullscreen or windowed borderless
    
  - [x] Graphics setting - Everything to minimal
    
  - [x] Rendering scale - Lower the better
    
  - [x] Lobby FPS limit - 60 FPS
    
  - [x] Game FPS limit - 30 FPS
    
2. after tested it can run normally, you can turnoff your display for power saving
  
3. you'll need something inside your secure container to overweight your rat,if you don't have item can do that,you'll be unable to level-up your strength.
  
4. DO NOT carrying anything outside your secure container to overweight your rat, your rat will 100% lose those !!!
  

# Warning!

##### Running this might get your game account ban, because Nikita is a super sadism , if he or his puppetry saw your running this, they will very unhappy ! and very possible to ban your account !

##### if you really get a ban, no liability or warranty ! before use this ,think twice !

# For Developers that trying to tweak this bot for yourself:

You can use TarkovBotCoordinateConverter.py to calculate coordinate yourself, so when tarkov add new button or something, you can edit the main.ino file to adapt new game buttons by yourself.
