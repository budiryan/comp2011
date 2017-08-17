/*
 * int-queue.h
 *
 *  Created on: May 22, 2015
 *      Author: user
 */

#ifndef INT_QUEUE_H_
#define INT_QUEUE_H_
#include <iostream> /* File: int-queue.h */
#include <cstdlib>
using namespace std;
const int BUFFER_SIZE = 5;

class int_queue // Circular queue
{
  private:
    int data[BUFFER_SIZE]; // Use an array to store data
    int num_items; // Number of items on the queue
    int first; // Index of the first item; start from 0

  public:
    // CONSTRUCTOR member functions
    int_queue(void); // Default constructor
    // ACCESSOR member functions: const => won't modify data members
    bool empty(void) const; // Check if the queue is empty
    bool full(void) const; // Check if the queue is full
    int size(void) const; // Give the number of data currently stored
    int front(void) const; // Retrieve the value of the front item
    // MUTATOR member functions
    void enqueue(int); // Add a new item to the back of the queue
    void dequeue(void); // Remove the front item from the queue
};





#endif /* INT_QUEUE_H_ */
