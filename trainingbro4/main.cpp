#include <iostream>	 /* File: fcn-var-addr.cpp */

using namespace std;



struct node{
	int data;
	node* next;
};
void change(int *a){
*a+=10;
}


int main(void){
int i=0;
cout<<i<<endl;
change(&i);
cout<<i<<endl;



return 0;
}
