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
if(!full()){
top_index++;
data[top_index]=x;
}
else {
	cerr<<"FULL!";exit(-1);
}
}

void int_stack::pop(void) // Remove the top item from the stack
{
 if(!empty()){
	 top_index--;
 }
 else {
	 cerr<<"EMPTY!";exit(-1);
 }
}




