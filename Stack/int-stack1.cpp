/*
 * int-stack1.cpp
 *
 *  Created on: May 21, 2015
 *      Author: user
 */
#include "int-stack.h" /* File: int-stack1.cpp */

          /***** Default CONSTRUCTOR member function *****/
int_stack::int_stack(void) { top_index = -1; } // Create an empty stack

          /***** ACCESSOR member functions *****/
// Check if the int_stack is empty
bool int_stack::empty(void) const { return (top_index == -1); }

// Check if the int_stack is full
bool int_stack::full(void) const { return (top_index == BUFFER_SIZE-1); }

// Give the number of data currently stored
int int_stack::size(void) const { return top_index+1; }

// Retrieve the value of the top item
int int_stack::top(void) const
{
    if ( !empty( ) )
        return data[top_index];

    cerr << "Warning: Stack is empty; can't retrieve any data!" << endl;
    exit(-1);
}




