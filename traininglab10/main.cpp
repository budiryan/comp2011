/*
 * main.cpp
 *
 *  Created on: May 23, 2015
 *      Author: user
 */
#include <iostream>
#include "Int.h"
using namespace std;


int main()
{
    char s[102]; // Allow an input of at most 100 digits plus an optional sign
    long k;

    while (true)
    {
        cout << "Enter a long signed integer as a string: ";
        cin >> s;

        cout << "Enter a long signed integer: ";
        cin >> k;

        Int x(s);
        Int y(k);

        cout << endl;
        cout << "x = "; x.print();
        cout << "y = "; y.print();

        cout << endl;
        cout << "x is positive? " << boolalpha << x.is_positive() << endl;
        cout << "y is positive? " << boolalpha << y.is_positive() << endl;

        x.reverse();
        y.reverse();

        cout << endl;
        cout << "reversed x = "; x.print();
        cout << "reversed y = "; y.print();

        cout << endl;
        Int* sum = x.add(y);
        if (sum != NULL)
        {
            cout << "Addition result = ";
            sum->print();
            delete sum;
        }


        char continueAnswer;
        cout << endl << "Continue? (y/n) " << endl;
        cin >> continueAnswer;
        if(continueAnswer == 'n') break;
    }

    return 0;
}



