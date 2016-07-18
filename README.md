# Debouncer - A tiny Arduino library to read digital pins cleanly when connected to push buttons and other things that bounce (transition quickly between high and low many times due to a single event)

## Installing

* copy (or clone) this project to your Arduino 'libraries' folder (~/Documents/Arduino/libraries on Mac OS)
* include the header in your sketch: `#include <Debouncer.h>`

## Usage

### Construction

Each debouncer is meant to manage a single digital pin. You simply instantiate a Debouncer by constructing one, giving it the pin number it should manage. 

	pinMode(1, INPUT)
	Debouncer debounced_pin1 = Debouncer(1);

### Reading

To get the debounced state of the pin, simply call the `Debouncer::read()`:

	char pin1_state = debounced_pin1.read();
	
	if (pin1_state == LOW) {
		//do something when low
	} else if (pin1_state == HIGH) {
		//do somthing when high
	}

### Getting time held

The debouncer allows access to the time when the last state transition occurred, which can be of some interest at times: 

	unsigned long held_millis = debounced_pin1.held(); 
