/*
 * sll.h
 *
 *  Created on: May 23, 2015
 *      Author: user
 */

#ifndef SLL_H_
#define SLL_H_

struct sll_node
{
    int value;        // An integer stored in the node
    sll_node* next;   // A pointer to the next node in the linked list
};


// Functions to implement
sll_node* sll_create(int num);
void sll_insert(sll_node*& head, int value);
sll_node* sll_add(sll_node* p1, sll_node* p2);
sll_node *sortList(sll_node *head);
// The following functions are already given
void sll_print(const sll_node* p);



#endif /* SLL_H_ */
