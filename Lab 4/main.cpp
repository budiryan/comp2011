#include <iostream>
#include <cmath>
using namespace std;

void convertBinToDec()
{
	cout << "Please input the binary number to be converted into decimal:\n";

	int number;
	cin >> number;
	int dummynumber;
	dummynumber=number;

	int k=0;
	do {
	     ++k;
	     dummynumber /= 10;
	} while (dummynumber);

	int result = 0;

	//TODO: Finish this function...
	for(int j=0;j<k;++j){
		int l=number%10;
		result+=l*(pow(2,j));
		number=number/10;
	}
	cout << "Result=" << result;
}
void countNumberofBits()
{
	int testnumber;
	cout<<"Please input the number to count bits for: ";
	cin>>testnumber;

int k=0;
int result;
result=pow(2,k)-1;
while(result<testnumber){

	k++;
	result=pow(2,k)-1;
}
cout<<"Result = "<<k;
}


void convertDectoBin(){
	int testnumber;
		cout<<"Please input the number to count bits for: ";
		cin>>testnumber;

	int k=0;
	int result;
	result=pow(2,k)-1;
	while(result<testnumber){

		k++;
		result=pow(2,k)-1;
	}

	int result1=0;
	int b=testnumber;
	for(int m=0;m<k;++m){
		int a=b%2;
		b=b/2;
		result1+=a*(pow(10,m));
		}
	cout<<"Result= "<<result1<<endl;
}

//TODO: Add other functions to support the other operations...

int main()
{
	int operationID;

    cout << "Binary/Decimal Conversion\n\n"
    <<  "Choose one of the following:\n\n"
    << "1. Convert a binary number to a decimal number (supports at most 10 binary digits)\n"
    << "2. Count the number of bits needed to represent a non-negative integer in binary format\n"
    << "3. Convert a decimal number to a binary number (supports at most 3 decimal digits)\n"
    << "4. Exit";

    bool done = false;
	while (!done)
	{
		cout<<"\n\nPlease input your choice [1-4]:"<<endl;
		cin >> operationID;
        switch (operationID)
        {
            case 1:
            	convertBinToDec();
            	break;
            case 2:
            	countNumberofBits();
            	break;
            case 3:
            	convertDectoBin();
            	break;
            case 4:
            	done=true;
            	break;


            //TODO: Extend the switch structure to support other operations...

            default:
            	cout << "Invalid input, please try again.\n";
                break;
        }
	}

    cout<< "See you!" << endl;
	return 0;
}



