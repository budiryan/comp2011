#include <iostream>	 /* File: palindrome.cpp */
using namespace std;
const char NULLCHAR='\0';
struct ll_cnode{
	ll_cnode* next;
	char value;
};
//Function to Create a linked list:
ll_cnode* create(char a){
	ll_cnode* p=new ll_cnode;
	p->value=a;
	p->next=NULLCHAR;

	return p;
}
ll_cnode* create(const char s[]){
	if(s[0]==NULLCHAR)return NULL;
	ll_cnode* head=NULLCHAR;
	head= create(s[0]);
	ll_cnode* h=head;
	for(int i=1;s[i]!=NULLCHAR;++i){
	h->next=create(s[i]);
	h=h->next;

	}
	return head;
}
//Function to print the linked list
void ll_print(ll_cnode* head){
	if(head==NULL){
		cout<<"NOTHING TO PRINT HERE!"<<endl;
	}
	for(;head!=NULL;head=head->next){
		cout<<head->value;
	}
	cout<<endl;
}
//Function to count the length of the linked list
int ll_printlength(const ll_cnode* head){
	int length=0;
	for(;head!=NULL;head=head->next){
		length++;
	}
	return length;

}
//Function to search the list
const ll_cnode* ll_search(ll_cnode* head, char c){
	for(ll_cnode *p=head;p!=NULL;p=p->next){
		if(p->value==c){
			return p;
		}
	}
return NULL;}
// Function to insert the list
void ll_insert(ll_cnode* head, int a, char b){
	//Create a new temp cnode with the inserted value
	ll_cnode* newcnode=create(b);
	//If the length of the list is 0 or nothing, just return
	if((head==NULL)||a==0){
		newcnode->next=head;//Points to NULL
		head=newcnode;
		return;}
	ll_cnode *p=head;
	for(int position=0;position<a-1&&p->next!=NULL;p=p->next,++position);

		newcnode->next=p->next;
		p->next=newcnode;


}
//code to delete a particular node in a linked list
void ll_delete(ll_cnode* head, char b){
	//error if the corresponding character is not found
ll_cnode *previous=NULL;
ll_cnode *current=head;
while(current!=NULL && current->value!=b){
	previous=current;
	current=current->next;
}
//OK, now the data is already found
//advance the data
//special case, what if the designated char is the first item?

if(current==head){
	head=head->next;
}
else previous->next=current->next;
delete current;
}
void ll_delete_all(ll_cnode* head){

	ll_cnode *current=head;
	ll_cnode *temp;

while(current!=NULL){
	cout<<"deleting "<<current->value<<endl;
	temp=current;

	current=current->next;
	delete temp;
	temp=NULL;
}
if(current==NULL){
	return;
}


}

int main(void)
{
ll_cnode* newlinked = create("met");
ll_insert(newlinked,2,'a');
ll_print(newlinked);
ll_delete(newlinked,'a');
ll_print(newlinked);
ll_delete_all(newlinked);








return 0;
}
