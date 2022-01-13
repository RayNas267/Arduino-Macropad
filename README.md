# Quad-Profile Macropad

## Introduction

After browsing through various project ideas, I decided on this one because I thought it would be a fun way to practice the skills I gained in my Digital Electronics class as well as create something I could use in my day to day life. Furthermore, the customizable nature of this project made it something that I could continue to improve for my use in the future; thus, I decided to create the Quad-Profile Programmable Keypad. 

(insert image of final product here)

## Part Selection

First I needed to decide on the switches that we were going to use. Taking into account the use of this as an everyday item, I chose switches that were on the quieter side. (potentially insert image here of said switches). The source that I referenced in creating this project also had a knob on their keypad, and so I got this rotary encoder for that purpose (insert rotary encoder image). Finally, the board I used was the Arduino Pro Micro--it was perfect in the sense that it was compact and capable of supporting the various libraries necessary. (insert arduino pro micro image).

## CAD Model

This is the completed CAD model that would house all my components and wiring. On the top there are four small circular holes for the LEDs, 11 square holes for the keys, and a large circular hole for the knob. On the side, there is a hole for the USB to plug into. This design is more intended to simply contain all the wiring and components rather than hold them in place; in fact, only the top plate really holds things in place (the switches, LEDs, and rotary encoder).


## Manufacturing

### 3D Printing

I had to begin by 3D printing the top plate first, as this was where all the components were fastened to initially, a necessary step before I could begin the wiring process in earnest. Once I had completed all of the wiring, I was able to go forth and print the bottom half, which simply allowed everything to be contained. Below are two images of the top plate with the components on it and the bottom half on its own.

![image](https://user-images.githubusercontent.com/75506860/149283890-e00e1b0e-5700-4597-b926-1c0b02f72984.png)
![image](https://user-images.githubusercontent.com/75506860/149280958-fb9fea7c-19a2-4746-8bf9-72729a195542.png)

### Wiring

This was by far the most complex portion of the project. Due to choosing to create this keypad in the manner of an array rather than utilizing a PCB, I had to do a lot of soldering in order to have everything connect properly. Below is a wiring diagram, and next to it is the wiring with all of the soldering completed. Some issues that I came across was accidentally having the diodes facing the wrong way, or how some of the soldered wires would accidentally interact with each other once we pushed the wiring down to have it fit inside of our housing container. In order to remedy this issue, I had to ensure that the wires were oriented in a way that they avoided touching each other, and was able to get it successfully in the container and functioning properly.

![image](https://user-images.githubusercontent.com/75506860/149280266-92cd7773-f6e2-4f8d-90a3-e38c987e9077.png)


## User Guide

The keypad must first be plugged into the device you want to use it on, presumable a computer, via the USB connector. Once the power is supplied, it goes through a little start animation with LEDs, and is ready for use. The first thing to note is that there are four different profiles--what this means is that by pressing the button to the right of the rotart encoders, you can alternate between four different sets of preprogrammed keypad configurations, and the 4 leds on the bottom signify which profile you are in. For instance, in the first basic profile, the 10 keys (setting aside the one key that is used for switching profiles) are just 0-9, and the knob can be used to adjust volume. Then, when you switch to the second profile, the 10 keys now function as a-j. In the third profile, each key has a shortcut within it--for instance, one key might copy highlighted text, and another might paste it. Another key could open a new tab while a different key could close the current window you're on. Additionally, the knob can now zoom in and out when turned. Finally, in the last profile the keys are oriented towards media usage. One button plays and pauses, another one skips ahead, another one goes backwards, another skips ahead to the next video, and so on. The best part about this project is that these four profiles are easily customizable--so, if you ever decide you want a different functionality, you can simply edit the code for one of the profiles. For instance, a student that finds themselves writing a lot might want to have keybinds that are more directed towards word-processing--things like copy/paste, word count shortcuts, and so on. In the video below, I demonstrate how this project could be utilized by different users.

## Code Implementation

### Technical Challenges



### Organization

#### setup()


#### loop()


## Skills Demonstrated
