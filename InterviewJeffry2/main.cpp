#include <iostream>	/* File: print-array-by-pointer.cpp */
using namespace std;
int main(void)
{
    int* x= new int[10];
    for(int j=0;j<10;j++){
    	x[j]=j;
    }
    for(int i=0;i<10;i++){
    	cout<<x[i]<<endl;
    }
    delete []x;
    x=NULL;

}
