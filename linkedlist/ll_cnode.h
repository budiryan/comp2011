/*
 * ll_cnode.h
 *
 *  Created on: Apr 6, 2015
 *      Author: user
 */

#ifndef LL_CNODE_H_
#define LL_CNODE_H_





#endif /* LL_CNODE_H_ */
#include <iostream> /* File: ll_cnode.h */
using namespace std;

struct ll_cnode {
    char data; // contains useful information
    ll_cnode* next; // the link to the next node
};

const char NULL_CHAR = '\0';
ll_cnode* ll_create(char);
ll_cnode* ll_create(const char [ ]);
int ll_length(const ll_cnode*);
void ll_print(const ll_cnode*);
ll_cnode* ll_search(ll_cnode*, char c);
void ll_insert(ll_cnode*&, char, unsigned);
void ll_delete(ll_cnode*&, char);
void ll_delete_all(ll_cnode*&);
