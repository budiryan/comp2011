/*
 * temperature_constructors.cpp
 *
 *  Created on: May 21, 2015
 *      Author: user
 */
#include "temperature.h" /* File: temperature_constructors.cpp */

// CONSTRUCTOR member functions
temperature::temperature(void) // Default constructor
{
    degree = 0.0;
    scale = CELSIUS;
}

temperature::temperature(double d, char s)  // A general constructor
{
    set(d, s);  // Calling another member function
}




