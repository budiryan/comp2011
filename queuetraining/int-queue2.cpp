/*
 * int-queue2.cpp
 *
 *  Created on: May 24, 2015
 *      Author: user
 */




/*
 * int-queue2.cpp
 *
 *  Created on: May 22, 2015
 *      Author: user
 */
#include "int.queue.h" /* File: int-queue2.cpp */

void int_queue::enqueue(int x)  // Add a new item to the back of the queue
{
	if(!full()){
data[(first+num_items)%BUFFER_SIZE]=x;
num_items++;}
	else{
		cerr<<"QUEUE IS FULL BRO";
		exit(-1);
	}

}

void int_queue::dequeue(void) // Remove the front item from the queue
{
first=(first+1)%BUFFER_SIZE;
}




