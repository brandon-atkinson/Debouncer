#include "Debouncer.h"

Debouncer::Debouncer(unsigned char pin, unsigned long settle_time_millis, unsigned char initial_value) : 
	_pin(pin), 
	_settle_time_millis(settle_time_millis), 
	_stable_value(initial_value) {
}

unsigned char Debouncer::read() {
	unsigned long now = millis();
	unsigned char reading = digitalRead(_pin);
	
	if (reading != _last_reading) {
		_last_change = now;
		_last_reading = reading;
	}
	
	unsigned char next_stable_state = _stable_value;
	if (now >= (_last_change + _settle_time_millis)) {
		next_stable_state = reading;
	} 
	return next_stable_state;
}

unsigned long Debouncer::held() {
	return millis() - _last_change;
}
