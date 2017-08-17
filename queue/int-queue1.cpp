#include "int-queue.h" /* File: int-queue1.cpp */

          /***** Default CONSTRUCTOR member function *****/
// Create an empty queue
int_queue::int_queue(void) { first = 0; num_items = 0; }

          /***** ACCESSOR member functions *****/
// Check if the int_queue is empty
bool int_queue::empty(void) const { return (num_items == 0); }

// Check if the int_queue is full
bool int_queue::full(void) const { return (num_items == BUFFER_SIZE); }

// Give the number of data currently stored
int int_queue::size(void) const { return num_items; }

// Retrieve the value of the front item
int int_queue::front(void) const
{
    if ( !empty( ) ) return data[first];
    cerr << "Warning: Queue is empty; can't retrieve any data!" << endl;
    exit(-1);
}
