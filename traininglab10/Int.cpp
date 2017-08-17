#include <iostream>
#include "Int.h"
using namespace std;

// TODO #1: Implement constructor1
// If the input is unsigned, it is a positive number
// Assumption: input string s is always a valid char representation of an integer
Int::Int(const char* s)
{
   cout << "Call constructor with string input: " << s << endl;

   // ADD YOUR CODE HERE
   if(s[0]=='-'){
	   sign=negative;
   }
   else sign=positive;
   if(s[0]=='+'||s[0]=='-'){
	   s++;
   }
   num_digits=strlen(s);
   digit=new char[strlen(s)+1];
   strcpy(digit,s);
}


// TODO #2: Implement constructor2
Int::Int(long x)
{
   cout << "Call constructor with long input: " << x << endl;

   // ADD YOUR CODE HERE
   if(x<0){
	   sign=negative;
	   x=-x;
   }
   else sign=positive;
   num_digits=1;

for(long j=x;j/=10;num_digits++)cout<<num_digits;
cout<<num_digits;
digit=new char[num_digits];
for(int i=num_digits-1;i>=0;i--){
	   digit[i]='/0'+(x%10);
	   x/=10;
   }

}


// TODO #3: Implement the destructor
Int::~Int()
{
   cout << "Call destructor: " << ((sign == positive) ? '+' : '-') << digit << endl;

   // ADD YOUR CODE HERE
   delete [] digit;
}


// TODO #4: Implement this function
// If positive, return true, otherwise false
bool Int::is_positive() const
{
   // ADD YOUR CODE HERE
if(sign==positive)return true;
else return false;
}

// TODO #5: Implement this function
// Reverse the number, e.g., 1234 becomes 4321
// Do not change the sign
void Int::reverse()
{
   // ADD YOUR CODE HERE
	int i=0;
	int j=(num_digits-1);
	while(i<j){
		char temp;
		temp=digit[i];
		digit[i]=digit[j];
		digit[j]=temp;
		i++;
		j--;

	}
}

/******************** This Is An Optional but Challenging Task ************/
// TODO #6: Implement the add function
// Return the sum as a new Int
Int* Int::add(const Int& x) const
{
	  return NULL;
   // ADD YOUR CODE HERE
}



// Print with a comma for every 3 digits counting from the right
// Always print out the sign
void Int::print() const
{
   // Always print out the sign
   cout << ((sign == positive) ? '+' : '-');

   for (const char *p = digit,  *last_digit_ptr = digit + num_digits - 1;
        p <= last_digit_ptr; ++p)
   {
       cout << *p;

       if (p != last_digit_ptr  &&  (last_digit_ptr - p)%3 == 0)
           cout << ',';
   }

   cout << endl;
}
