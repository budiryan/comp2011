/*
 * main.cpp
 *
 *  Created on: May 21, 2015
 *      Author: user
 */
#include <iostream>
#include "int-stack.h" /* File: int-stack-test.cpp */
using namespace std;



int main(void) // Convert +ve decimal number to binary number using an stack
{
    int_stack a;
 int* x=new int[4];
 for(int i=0;i<4;i++){
	 x[i]=i;
    }
a.push(x[1]);
x[1]++;
cout<<a.top()<<endl;
cout<<x[1]<<endl;

    return 0;
} // Compile: g++ -o decimal2binary -Lint-stack decimal2binary.cpp -lintstack




