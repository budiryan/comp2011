/*
 * Int.cpp
 *
 *  Created on: Apr 26, 2015
 *      Author: user
 */
#include <iostream>
#include "Int.h"
using namespace std;

// TODO #1: Implement constructor1
// If the input is unsigned, it is a positive number
// Assumption: input string s is always a valid char representation of an integer
Int::Int(const char* s)
{
   cout << "Call constructor with string input: " << s << endl;

   // ADD YOUR CODE HERE
   cout << "Call constructor with string input: " << s << endl;

       // If the input is unsigned, it is a positive number
       sign = (s[0] == '-') ? negative : positive;

       if (s[0] == '+' || s[0] == '-')
           ++s;

       cout<<s<<endl;
       // Allocate memory to store the number and copy s to digit
       num_digits = strlen(s);
       digit = new char [num_digits+1];
       strcpy(digit, s);
}


// TODO #2: Implement constructor2
Int::Int(long x)
{
   cout << "Call constructor with long input: " << x << endl;

   // ADD YOUR CODE HERE
   cout << "Call constructor with long input: " << x << endl;

      if (x < 0)
      {
          sign = negative;
          x = -x;
      }
      else
          sign = positive;

      // Find the number of digits in x
      num_digits = 1;
      for (long y = x; y/=10; ++num_digits)
          ;

      // Allocate memory to store the number
      digit = new char [num_digits+1];
      digit[num_digits] = '\0';

      // Convert each digit of x to its equivalent char in digit
     // for (char* p = digit + num_digits - 1; p >= digit; --p)
    //  {
      //    *p = '0' + x%10;
       //   x /= 10;
   //   }
   for(int i=num_digits-1;i>=0;i--){
	   digit[i]='0'+(x%10);
	   x/=10;
   }


}


// TODO #3: Implement the destructor
Int::~Int()
{
   cout << "Call destructor: " << ((sign == positive) ? '+' : '-') << digit << endl;

   // ADD YOUR CODE HERE
   cout << "Call destructor: " << ((sign == positive) ? '+' : '-') << digit << endl;
       delete [] digit;

}


// TODO #4: Implement this function
// If positive, return true, otherwise false
bool Int::is_positive() const
{
   // ADD YOUR CODE HERE

	 return (sign == positive);
}

// TODO #5: Implement this function
// Reverse the number, e.g., 1234 becomes 4321
// Do not change the sign
void Int::reverse()
{
   char temp;
   int start=0;
   int end=num_digits-1;
   while(start<end){
	   temp=digit[start];
	   digit[start]=digit[end];
	   digit[end]=temp;
	   start++;
	   end--;
   }

}

/******************** This Is An Optional but Challenging Task ************/
// TODO #6: Implement the add function
// Return the sum as a new Int
Int* Int::add(const Int& x) const
{
	  return NULL;
   // ADD YOUR CODE HERE
}



// Print with a comma for every 3 digits counting from the right
// Always print out the sign
void Int::print() const
{
   // Always print out the sign
   cout << ((sign == positive) ? '+' : '-');

   for (const char *p = digit,  *last_digit_ptr = digit + num_digits - 1;
        p <= last_digit_ptr; ++p)
   {
       cout << *p;

       if (p != last_digit_ptr  &&  (last_digit_ptr - p)%3 == 0)
           cout << ',';
   }

   cout << endl;
}



