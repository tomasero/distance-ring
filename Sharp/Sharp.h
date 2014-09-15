#ifndef Sharp_h
#define Sharp_h
#include <Arduino.h>

class Sharp {
	public:
		Sharp();
		void begin(int pin1, int pin2);

		int getDistance(int pin);

		void setSampleCount(int sampleCount);   

	private:
		int _map(int pin);
		int _pin1;
		int _pin2;
		int _sampleCount;
		int _transferFunctionLUT5V[];
};
#endif
