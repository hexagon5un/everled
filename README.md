## ATtiny45 EverLED

Run an LED dimly on a few microamps, and you can run it for years off of a button cell.  I made one, and now I don't stub my toe on the corner of my bed at night anymore.  And then I made a few more because they're fun.

Ted Yapo has this great [TritiLED project](https://hackaday.io/project/11864-tritiled), and I basically just ripped it off with the parts that I had on hand.  While he aims at making a dim LED flashlight that will last for 10+ or even 25 years, I'm fine with two years on a 2032 coin cell.  It turns out that good enough is very easy to achieve.

![red_version](https://raw.githubusercontent.com/hexagon5un/everled/master/docs/DSCF9903.JPG)

The secret? Running the LED by putting it in flyback with an inductor.  This creates a (nearly) lossless store for the energy pulses that a) is controllable over a very wide range b) also doubles as a step-up voltage converter so it will run almost any LED or chain and c) provides short pulses of comparatively high current, which might run your LED more efficiently that simple PWM.  

Varying the pulse duration changes the current consumption, which is almost entirely independent of the LED that you connect.  How bright the LED is depends on it's particulars.  See Ted's project for great detail on LED efficiency curves. Short version: around a milliamp is good for many LEDs.

The AVR draws as little current as possible by spending almost all of the time in power-down mode, being periodically woken up by the watchdog timer.  The ATtiny45 is not a particularly low-power chip, but it's almost always sleeping, so meh.  You can probably trim a few more microamps (25% of the power budget?!?!) by using a better chip.   

The version I settled on uses 10 uA, and seems to run nearly every LED I've thrown at it, at various brightnesses.  The PCB in "hardware" has extra pads for testing out SMD LEDs, connecting a programmer to the ATtiny45, and tons of wasted space for you to optimize if you're into that.

The circuit couldn't be simpler.  It's meant to be adapted to parts on hand.  Build one, deploy, enjoy.  

![schematic](https://raw.githubusercontent.com/hexagon5un/everled/master/docs/everled.png)

You can read about its development over [on Hackaday.io](https://hackaday.io/project/25584-attiny45-everled).


