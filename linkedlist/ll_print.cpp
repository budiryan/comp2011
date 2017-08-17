/*
 * ll_print.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: user
 */
#include "ll_cnode.h" /* File: ll_print.cpp */

void ll_print(const ll_cnode* head)
{
    for (const ll_cnode* p = head; p != NULL; p = p->next)
        cout << p->data;
    cout << endl;
}




