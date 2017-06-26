## ATtiny45 EverLED

Run an LED dimly on a few microamps, and you can run it for years off of a button cell.  I made one, and now I don't stub my toe on the corner of my bed at night anymore.  And then I made a few more because they're fun.

Ted Yapo has this great [TritiLED project](https://hackaday.io/project/11864-tritiled), and I basically just ripped it off with the parts that I had on hand.  While he aims at making a dim LED flashlight that will last for 10+ or even 25 years, I'm fine with two years on a 2032 coin cell.  It turns out that good enough is very easy to achieve.

![red_version](https://raw.githubusercontent.com/hexagon5un/everled/master/docs/DSCF9903.JPG)

The secret? Running the LED by putting it in flyback with an inductor.  This creates a (nearly) lossless store for the energy pulses that a) is controllable over a very wide range and b) also doubles as a step-up voltage converter so it will run almost any LED or chain. 

Varying pulse durations change the brightness and also the current consumption.  The AVR is in power-down mode, periodically woken up by the watchdog timer.  If you can tolerate some blinking, you could cut the AVR's power budget in half or less by playing with the watchdog period.  

The version I settled on uses 10 uA, and seems to run nearly every LED I've thrown at it, at various brightnesses.  The PCB in "hardware" has extra pads for testing out SMD LEDs, connecting a programmer to the ATtiny45, and tons of wasted space for you to optimize if you're into that.

The circuit couldn't be simpler.  It's meant to be adapted to parts on hand.  Build one, deploy, enjoy.  

![schematic](https://raw.githubusercontent.com/hexagon5un/everled/master/docs/everled.png)

You can read about its development over [on Hackaday.io](https://hackaday.io/project/25584-attiny45-everled).


