/*
 * temperature_accessors.cpp
 *
 *  Created on: May 21, 2015
 *      Author: user
 */
#include "temperature.h" /* File: temperature_accessors.cpp */

// ACCESSOR member functions
char temperature::get_scale(void) const
{
    return scale;
}

double temperature::get_degree(void) const
{
    return degree;
}

void temperature::print(void) const
{
    cout << degree << " " << scale;
}



