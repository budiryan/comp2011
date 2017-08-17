/*
 * ll_length.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: user
 */

#include "ll_cnode.h" /* File: ll_length.cpp */

int ll_length(const ll_cnode* head)
{
    int length = 0;
    for (const ll_cnode* p = head; p != NULL; p = p->next)
        ++length;
    return length;
}



