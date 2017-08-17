/*
 * sll-main.cpp
 *
 *  Created on: Apr 22, 2015
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
    sll_node* q = sll_create(133);
    sll_node* p = sll_create(99854321);
    sll_node* h = sll_create(283955576);


    cout << endl << "Linked list p: " << endl;
    sll_print(p);
    cout << endl << "Linked list q: " << endl;
    sll_print(q);

    cout << endl << "Insert an integer to the linked list p: " << endl;
    int insnum=5;
    sll_insert(p,insnum);
    sll_print(p);

    cout << endl << "Add of p and q:" << endl;
    sll_node* m=sll_add(p, q);
    sll_print(m);

    cout << endl << "Sort a linked list h:" << endl;
    sll_print(h);
    sll_node* n = sortList(h);
    sll_print(n);

    sll_print(sortList(sll_create(51481249)));
    sll_print(sortList(sll_create(917492703)));
    sll_print(sortList(sll_create(1234567890)));
    sll_print(sortList(sll_create(987654321)));
    return 0;
}



