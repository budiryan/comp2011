/*
 * temperature_test.cpp
 *
 *  Created on: May 21, 2015
 *      Author: user
 */
#include "temperature.h" /* File: temperature_test.cpp */

int main(void)
{
    char scale;
    double degree;

    temperature x; // Use default constructor
    x.print( ); cout << endl; // Check the default values

    cout << "Enter temperature (e.g., 98.6 F): ";
    while (cin >> degree >> scale)
    {
        x.set(degree, scale);
        x.fahrenheit( ); x.print( ); cout << endl; // Convert to Fahrenheit format
        x.celsius( ); x.print( ); cout << endl; // Convert to Celsius format

        cout << endl << "Enter temperature (e.g., 98.6 F): "; // Next input
    };

    return 0;
}




