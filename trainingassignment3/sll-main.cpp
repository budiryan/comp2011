/*
 * sll-main.cpp
 *
 *  Created on: May 23, 2015
 *      Author: user
 */

/*
 *
 ************** YOU DO NOT NEED TO SUBMIT THIS FILE **************
 **** THE MAIN FUNCTION WILL BE MODIFIED TO TEST YOUR PROGRAM ****
 *
 */
#include <iostream>
#include "sll.h"
using namespace std;


int main()
{
    sll_node* p = sll_create(271);
    sll_node* q = sll_create(345);
    sll_node* h = sll_create(6892);

    cout << endl << "Linked list p: " << endl;
    sll_print(p);
    cout << endl << "Linked list q: " << endl;
    sll_print(q);

    cout << endl << "Insert an integer to the linked list p: " << endl;
    int insnum=2;
    sll_insert(p,insnum);
    sll_print(p);

    cout << endl << "Add of p and q:" << endl;
    sll_node* m=sll_add(p, q);
    sll_print(m);

    cout << endl << "Sort a linked list h:" << endl;
    sll_print(h);
    sll_node* n = sortList(h);
    sll_print(n);
    return 0;
}


