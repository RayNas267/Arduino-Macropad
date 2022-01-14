# Quad-Profile Macropad

## Introduction

After browsing through various project ideas, we decided on this one because we thought it would be a fun way to practice the skills we gained in my Digital Electronics class as well as create something we could use in my day to day life. Furthermore, the customizable nature of this project made it something that we could continue to improve for my use in the future; thus, we decided to create the Quad-Profile Programmable Keypad. 

![image](https://user-images.githubusercontent.com/75506860/149467141-fce9367c-0101-465c-8d46-ae691f0a9bba.png)![image](https://user-images.githubusercontent.com/75506860/149467186-e9e70b88-b959-47b1-9bac-b2b50e576839.png)

## Part Selection

First we needed to decide on the switches that we were going to use. Taking into account the use of this as an everyday item, we chose switches that were on the quieter side. The source that we referenced in creating this project also had a knob on their keypad, and so we got this rotary encoder for that purpose. Finally, the board we used was the Arduino Pro Micro--it was perfect in the sense that it was compact and capable of supporting the various libraries necessary.

![image](https://user-images.githubusercontent.com/75506860/149284897-bcbd84eb-63aa-4d56-8cb0-28fd5df1fab5.png)

## CAD Model

This is the completed CAD model that would house all my components and wiring. On the top there are four small circular holes for the LEDs, 11 square holes for the keys, and a large circular hole for the knob. On the side, there is a hole for the USB to plug into. This design is more intended to simply contain all the wiring and components rather than hold them in place; in fact, only the top plate really holds things in place (the switches, LEDs, and rotary encoder).

![image](https://user-images.githubusercontent.com/78373556/149567221-95abbedb-3877-4c70-9c34-980b2d0c6316.png)


## Manufacturing

### 3D Printing

We had to begin by 3D printing the top plate first, as this was where all the components were fastened to initially, a necessary step before we could begin the wiring process in earnest. Once we had completed all of the wiring, we was able to go forth and print the bottom half, which simply allowed everything to be contained. Below are two images of the top plate with the components on it and the bottom half on its own.

![image](https://user-images.githubusercontent.com/75506860/149285208-238d3bab-b4b3-4506-a2ac-ebd031e27e33.png)

### Wiring

This was by far the most complex portion of the project. Due to choosing to create this keypad in the manner of an array rather than utilizing a PCB, we had to do a lot of soldering in order to have everything connect properly. Below is a wiring diagram, and next to it is the wiring with all of the soldering completed. Some issues that we came across was accidentally having the diodes facing the wrong way, or how some of the soldered wires would accidentally interact with each other once we pushed the wiring down to have it fit inside of our housing container. In order to remedy this issue, we had to ensure that the wires were oriented in a way that they avoided touching each other, and was able to get it successfully in the container and functioning properly.

![image](https://user-images.githubusercontent.com/75506860/149280266-92cd7773-f6e2-4f8d-90a3-e38c987e9077.png)


## User Guide

The keypad must first be plugged into the device you want to use it on, presumable a computer, via the USB connector. Once the power is supplied, it goes through a little start animation with LEDs, and is ready for use. The first thing to note is that there are four different profiles--what this means is that by pressing the button to the right of the rotart encoders, you can alternate between four different sets of preprogrammed keypad configurations, and the 4 leds on the bottom signify which profile you are in. For instance, in the third basic profile, the 10 keys (setting aside the one key that is used for switching profiles) are just 0-9, and the knob can be used to adjust volume. Then, when you switch to the fourth profile, the 10 keys now function as a-j. In the second profile, some keys have a shortcut within it--for instance, one key might copy highlighted text, and another might paste it. Another key could open a new tab while a different key could close the current window you're on. The first profile is left blank with instructions on how to test their own key functions. The best part about this project is that these four profiles are easily and completely customizable--so, if you ever decide you want a different functionality, you can simply edit the code for one of the profiles. For instance, a student that finds themselves writing a lot might want to have keybinds that are more directed towards word-processing--things like copy/paste, word count shortcuts, and so on. In the video below, we demonstrate how this project could be utilized by different users.

## Code Implementation

### Technical Challenges
The first challenge was soldering all of the componenets together. Unlike regular keyboards or keypads, our MacroPad doesn't use a PCB. In order to circumvent this, the mechanical switches need to be soldered to wires directly. This proved to be very difficukt because we didn't have much experience with soldering wires, diodes, and resistors together directly. However, as the project progressed and we got more experience, it became much easier.
The second challenge, was using the correct libraries. The code for the arduino used 4 external libraries: Keypad, Encoder, Bounce2, and HID-Project. We needed to figure out which versions of the libraries to use as well as the functions of each library. This consisted of a lot of trial and error, as well as a lot of testing and debugging. Thankfully, like the previous challege, this was solved with time.

### Organization

#### setup()
The initial setup() function is used to setup the keyboard, rotary encoder, and the pins for the LEDs. It also activates the starting animation.

#### loop()
The main loop() functions constantly checks for 3 things: if a key was pressed, if the rotary encoder was presses, and if the rotary encoder was turned.
