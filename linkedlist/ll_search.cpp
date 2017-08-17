/*
 * ll_search.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: user
 */
#include "ll_cnode.h" /* File: ll_search.cpp */

// The returned pointer may be used to change the content
// of the found ll_cnode. Therefore, the return type
// should not be const ll_cnode*.

ll_cnode* ll_search(ll_cnode* head, char c)
{
    for (ll_cnode* p = head; p != NULL; p = p->next)
    {
        if (p->data == c)
            return p;
    }

    return NULL;
}




