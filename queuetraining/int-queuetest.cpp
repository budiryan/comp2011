/*
 * int-queuetest.cpp
 *
 *  Created on: May 24, 2015
 *      Author: user
 */

/*
 * main.cpp
 *
 *  Created on: May 22, 2015
 *      Author: user
 */
#include "int.queue.h" /* File: int-queue-test.cpp */

void print_queue_info(const int_queue& a) {
    cout << "No. of data currently on the queue = " << a.size( ) << "\t";
    if (!a.empty( )) cout << "Front item = " << a.front( );
    cout << endl << "Empty: " << boolalpha << a.empty( );
    cout << "\t\t" << "Full: " << boolalpha << a.full( ) << endl;
}

int main(void) {
    int_queue a; print_queue_info(a);
    a.enqueue(4); print_queue_info(a);
    a.enqueue(15); print_queue_info(a);
    a.enqueue(26); print_queue_info(a);
    a.enqueue(37); print_queue_info(a);
    a.dequeue( ); print_queue_info(a);
    a.enqueue(48); print_queue_info(a);
    a.enqueue(59); print_queue_info(a);
    a.dequeue( ); print_queue_info(a);
    a.dequeue( ); print_queue_info(a);
    a.dequeue( ); print_queue_info(a);
    a.dequeue( ); print_queue_info(a);
    a.dequeue( ); print_queue_info(a);
    return 0;
} /* compile: g++ -L. -o int-queue-test int-queue-test.cpp -lintqueue */



