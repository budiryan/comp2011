/*
 * btree-main.cpp
 *
 *  Created on: May 25, 2015
 *      Author: user
 */
#include "btree.h"
int main(){
	btree_node* root=create_btree_node(10);

	root->left=create_btree_node(8);
	root->left->left=create_btree_node(5);
	root->left->right=create_btree_node(9);

	root->right=create_btree_node(15);
	root->right->left=create_btree_node(12);
	root->right->right=create_btree_node(17);

	print_btree(root);
	delete_btree(root->left);

	cout<<"\n\n\n";
	print_btree(root);
	return 0;
}



