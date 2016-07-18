#ifndef _DEBOUNCER_H_
#define _DEBOUNCER_H_

#define DEFAULT_SETTLE_TIME 20
#define DEFAULT_INITIAL_VALUE LOW

#include <Arduino.h>
class Debouncer {
	private:
		unsigned char _pin;
		int _settle_time_millis;
		unsigned char _stable_value;
		unsigned char _last_reading;
		unsigned long _last_change;	

	public:
		Debouncer(unsigned char pin, unsigned long settle_time_millis = DEFAULT_SETTLE_TIME, unsigned char initial_value = DEFAULT_INITIAL_VALUE);
		unsigned char read();	
		unsigned long held();
};

#endif
