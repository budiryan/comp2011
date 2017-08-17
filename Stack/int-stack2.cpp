/*
 * int-stack2.cpp
 *
 *  Created on: May 21, 2015
 *      Author: user
 */
#include "int-stack.h" /* File: int-stack2.cpp */

        /***** MUTATOR member functions *****/
void int_stack::push(int x) // Add a new item to the top of the stack
{
    if ( !full( ) )
        data[++top_index] = x;
    else
    {
        cerr << "Error: Stack is full; can't add (" << x << ")!" << endl;
        exit(-1);
    }
}

void int_stack::pop(void) // Remove the top item from the stack
{
    if ( !empty( ) )
        --top_index;
    else
    {
        cerr << "Error: Stack is empty; can't remove any data!" << endl;
        exit(-1);
    }
}




