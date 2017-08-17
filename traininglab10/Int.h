/*
 * Int.h
 *
 *  Created on: May 23, 2015
 *      Author: user
 */

#ifndef INT_H_
#define INT_H_

enum Sign { positive, negative };

class Int
{
  private:
    Sign sign;
    short num_digits;   // strlen(digit); should be at least 1
    char* digit;        // digit only stored the absolute value of the
                        // number and digit[0] is the most significant digit

  public:
    // Constructors
    Int(long);
    Int(const char*);

    // Destructor
    ~Int( );

    // Accessors
    Int* add(const Int&) const; // Return by pointer the sum which is a new Int
    void print() const;         // Print with a comma for every 3 digits
    void reverse();     // Reverse a number
    bool is_positive() const;
};




#endif /* INT_H_ */
