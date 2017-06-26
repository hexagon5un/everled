#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define LED      PB4
#define LED_DDR  DDRB
#define LED_PORT PORTB

#define setBit(sfr, bit)     (_SFR_BYTE(sfr) |= (1 << bit))
#define clearBit(sfr, bit)   (_SFR_BYTE(sfr) &= ~(1 << bit))

ISR(WDT_vect){
	setBit(LED_PORT, LED);
	// can use _delay_us() here to make brighter  
	_delay_us(15); 
	// 6 us / 8 = 7.8 uA  // 60 us / 8 = 60 uA
	// 15 us / 8 = 10.7 uA  (measured 2.1 us) 
	clearBit(LED_PORT, LED);
}

int main(void) {
    // Just in case watchdog gets used as reset source, turn it off	
	wdt_disable();
	
	// init WDT for interrupts, not reset
	setBit(WDTCR, WDIE); // interrupt enable
	sei();
	
	// Init
	setBit(LED_DDR, LED);                      /* set LED pin for output */
	
	// Turn off all peripherals
	power_all_disable();
	// Max sleep mode for max power savings
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sleep_enable();

	// Mainloop
	while (1) {
		sleep_mode();
	}
	return 0;                                          /* end mainloop */
}
