# Flourometer

This repository contains everything related to the construction of a fluorometer, using a TCS230 color sensor.

Instructions

1. Plug The machine to a USB port, or a 9V batery or a 9 to 12 V wall adapter.
  - The machine should now be on Displaying information.
  
2. Push the button to cycle between different modes of operation (in fact this might be a bit slow since the arduino needs to run the entire code for one reding in a given mode to jump to the next one).

3. When you've found the mode you want to use stop pushin the button, and read the instructions in the screen.

4. As simple as that.

*****REMEMBER******

1. Modes in this machine are cyclical so if you for some reason messed up in some part of the procedure just wait for a couple of seconds for the machine to go back to the start of the mode, which is the title of the mode in the screen.


*****WHAT NOT TO DO******

1. Please do not plug it into the wall using a USB phone adapter since the voltage supplied might be to low and the fluorometer might stop working (In previous experiences we had to re upload the code to the arduino when we did this, so this probably erased the code in it).

2. Please do not Panic and start pushing the button over and over again if a push doesn't instantly change the mode, It can take up to a second to do so.

