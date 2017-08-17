/*
 * temperature.h
 *
 *  Created on: May 21, 2015
 *      Author: user
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include <iostream> /* File: temperature.h */
#include <cstdlib>
using namespace std;
const char CELSIUS = 'C', FAHRENHEIT = 'F';

class temperature
{
  private:
    char scale;
    double degree;

  public:
    // CONSTRUCTOR member functions
    temperature(void); // Default constructor
    temperature(double d, char s);
    // ACCESSOR member functions: don't modify data
    char get_scale(void) const;
    double get_degree(void) const;
    void print(void) const;
    // MUTATOR member functions: will modify data
    void set(double d, char s);
    void fahrenheit(void); // Convert to the Fahrenheit scale
    void celsius(void); // Convert to the Celsius scale
};




#endif /* TEMPERATURE_H_ */
