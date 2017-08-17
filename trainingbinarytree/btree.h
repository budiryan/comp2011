/*
 * btree.h
 *
 *  Created on: May 25, 2015
 *      Author: user
 */

#ifndef BTREE_H_
#define BTREE_H_
#include<iostream>
using namespace std;

struct btree_node{
	int data;
	btree_node *left;
	btree_node *right;
};
btree_node* create_btree_node(int data);
void delete_btree(btree_node*& tree);
void print_btree(const btree_node* tree,int depth=0);




#endif /* BTREE_H_ */
