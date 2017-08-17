/*
 * pa3.cpp
 *
 *  Created on: May 23, 2015
 *      Author: user
 */
#include <iostream>
#include "sll.h"
using namespace std;


// Given one positive integer (not including zero), you need to create one linked list to represent it. The digits are stored in reverse order and each of these nodes contain a single digit.
sll_node* sll_create(int num)
{
    // TODO #1
    // ADD YOUR CODE HERE
	sll_node *head; //The head of the list
	sll_node *n; //The advancing node
	sll_node *t; //The temporary pointer
	int numstored; //Initialize last digit variable
	numstored=num%10;
	num/=10;
	n = new sll_node;
	head=n; //head is assigned to the FIRST node
	t=n; //Assigning the temporary to the first node
	n->value=numstored;
	while(num!=0){
		n= new sll_node;
		numstored=num%10;
		num/=10;
		n->value=numstored;
		t->next=n;
		t=t->next;

	}
	if(num==0){//THE ENDING CONDITION
		n->next=NULL;
		return head; //finally return the linked list
	}


}

// Given one integer and one linked list, you need to insert this integer to the beginning of the linked list and return the new linked list.
void sll_insert(sll_node*& head, int value)
{
    // TODO #2
    // ADD YOUR CODE HERE
sll_node* newnode= new sll_node;
newnode->value=value;
newnode->next=head;
head=newnode;
}


// You are given two linked lists representing two positive integers, which are stored in reverse order. You must add these two positive integers in the form of linked lists and return the result as a linked list in the order as defined in Task 1.
sll_node* sll_add(sll_node* p1, sll_node* p2)
{
    // TODO #3
    // ADD YOUR CODE HERE
	//if both node are blank:
sll_node *head=NULL;
sll_node *temp=NULL;
sll_node *traverse;
int carry=0;
int sum;
while(p1!=NULL||p2!=NULL){
	sum=(p1?p1->value:0)+(p2?p2->value:0)+carry;
	carry=(sum>=10)?1:0;
	traverse=sll_create(sum%10);
	if(head==NULL)head=traverse;
	else temp->next=traverse;
	temp=traverse;
	if(p1)p1=p1->next;
	if(p2)p2=p2->next;
	}
if (carry==1){
	traverse->next=sll_create(1);
}
return head;
}

// Given one linked list, you need to sort it in ascending order.
sll_node *sortList(sll_node *head) {
    // TODO #4
    // ADD YOUR CODE HERE
	sll_node* current;
	sll_node* insertionpointer;
	insertionpointer=current=head;
	current=current->next;
	while(current!=NULL){
		insertionpointer=head;
		while(insertionpointer!=current){
			if(insertionpointer->value>current->value){
			int temp=current->value;
			current->value=insertionpointer->value;
			insertionpointer->value=temp;}
			else insertionpointer=insertionpointer->next;
		}
	current=current->next;}
	return head;
}

/*
 * To print the linked list in the following format:
 * e.g., if the SLL contains the integers 3, 8, 9, then output
 *       (3)->(8)->(9)
 */

void sll_print(const sll_node* p)
{
    if (p == NULL)      // Base case: empty SLL
        return;

     cout << "(" << p->value << ")"; // Print the current node

    if (p->next != NULL) // This is NOT the last node
    {
        cout << "->";
        sll_print(p->next); // Recursive step!
    }
    else                // This IS the last node
        cout << endl;
}



