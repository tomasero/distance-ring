#include <Arduino.h>
#include <Sharp.h>
#include <Sharp_LUTs.h>

Sharp::Sharp() {
}

void Sharp::begin(int pin1, int pin2) {
	pinMode(pin1, INPUT);
	_pin1 = pin1;
	pinMode(pin2, INPUT);
	_pin2 = pin2;
	setSampleCount(100); //setting number of samples before taking an average		  		      
}

void Sharp::begin(int pin1) {
    pinMode(pin1, INPUT);
    _pin1 = pin1;
    setSampleCount(100); //setting number of samples before taking an average
}

void Sharp::setSampleCount(int sampleCount) {
	_sampleCount = sampleCount;
}

int Sharp::getDistance(int pin) {
	return _map(pin);
}

int Sharp::_map(int pin) {
	int sum = 0;
	for (int i = 0; i < _sampleCount; i++) {
		sum = sum + pgm_read_byte_near (transferFunctionLUT5V + analogRead(pin)/4);
	}
	int avg = sum/_sampleCount*2.54;
	if (avg < 10) {
		return(10);
	} else if (avg > 80) {
		return(80);
	} else {
		return(avg);
	}
}