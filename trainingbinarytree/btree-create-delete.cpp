/*
 * btree-create-delete.cpp

 *
 *  Created on: May 25, 2015
 *      Author: user
 */
#include "btree.h"
btree_node* create_btree_node(int data){
	btree_node *newnode=new btree_node;
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

void delete_btree(btree_node*& tree)
{
	if(tree==NULL){
		return;
	}
	delete_btree(tree->left);
	delete_btree(tree->right);
	tree=NULL;
	delete tree;
}

void print_btree(const btree_node* tree, int depth){
if(tree==NULL){
	return;}
print_btree(tree->right,depth+1);
for(int i=0;i<depth;i++){
	cout<<"\t";
}
cout<<tree->data<<endl;
print_btree(tree->left,depth+1);



}





