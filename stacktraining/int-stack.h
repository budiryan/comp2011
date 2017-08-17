/*
 * int-stack.h
 *
 *  Created on: May 21, 2015
 *      Author: user
 */

#ifndef INT_STACK_H_
#define INT_STACK_H_
#include <iostream> /* File: int-stack.h */
#include <cstdlib>
using namespace std;
const int BUFFER_SIZE = 20;

class int_stack
{
  private:
    int data[BUFFER_SIZE]; // Use an array to store data
    int top_index; // Starts from 0; -1 when empty

  public:
    // CONSTRUCTOR member functions
    int_stack(void); // Default constructor
    // ACCESSOR member functions: const => won't modify data members
    bool empty(void) const; // Check if the stack is empty
    bool full(void) const; // Check if the stack is full
    int size(void) const; // Give the number of data currently stored
    int top(void) const; // Retrieve the value of the top item
    // MUTATOR member functions
    void push(int); // Add a new item to the top of the stack
    void pop(void); // Remove the top item from the stack
};





#endif /* INT_STACK_H_ */
