## Notes on the Code

The basic AVR code doesn't do much: it sleeps and the watchdog timer wakes up, blinks, and it sleeps again.  Doing so makes it draw 5-6 microamps on average.

The Makefile should compile things for you if you have the standard AVR-GCC + AVR lib + AVRDUDE combo.

I've even included the .hex files if you just want to run it, and don't want to tweak.  It's like 150 bytes.  Why not?

### Microseconds 

There's one trick: I wanted sub-microsecond pulses for experimentation, and the AVR's `_us_delay` function has one microsecond as the lower bound.  The solution is to tell the delay function that we're running the CPU at 1 MHz, and then actually run the CPU at 8 MHz.  (If you want more resolution, you can play around with other combinations.)

So, in the Makefile, you'll find `F_CPU` defined as 1 MHz, and in the code you'll see that I've set the clock prescaler to 1, which means the chip is running at the full 8 MHz. 

But caveat: the routines for calculating the baud rates on the serial hardware also rely on `F_CPU` .  If you're using that peripheral, you'll need to adjust things accordingly.  

Anyway, if you want a nominal 1 us pulse, you'll need to call `_delay_us(8)`.  There's some function-call overhead that makes this not work out exactly, so check out the pulses on a scope if you've got one.  Otherwise, that's all there is to it.

