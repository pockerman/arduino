#ifndef UTILITIES_H
#define UTILITIES_H

namespace utils
{

	/**
		* Convert the given discrete value to a voltage
		* represenation
	  */
	inline
	float to_voltage(int value){
		return 5.0*(value/1024.0)
	}

	/**
		* Convert the given voltage to a temperature in degrees Celcius 
	  */
	inline
	float voltage_to_temp_C(float V){
		return 100.0*(V -0.5);
	}


}

#endif
