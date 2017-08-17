/*
 * temperature.h
 *
 *  Created on: Apr 23, 2015
 *      Author: user
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

class temperature{
private:
	char scale;
	double degree;
public:
	temperature(void);
	temperature(double d, char s);
	char get_scale(void)const;//ACCESSOR
	double get_degree(void)const;
	void print(void)const;
	void set(double d,char s);
	void fahrenheit(void);
	void celcius(void);
};



#endif /* TEMPERATURE_H_ */
