/*
 * main.cpp
 *
 *  Created on: Feb 12, 2015
 *      Author: user
 */
/*
 * main.cpp
 *
 *  Created on: Feb 12, 2015
 *      Author: user
 */
#include <iostream>
using namespace std;
int main(){
	int option, width, height,lengthOfTheFirstSide,lengthOfTheSecondSide,lengthOfTheThirdSide,radius;

	while (true){
		cout<< "Thanks for using the Awesome Calculator"<<endl;
		cout<<"1. Calculate a rectangle perimeter"<<endl;
		cout<<"2. Calculate a triangle perimeter"<<endl;
		cout<<"3. Calculate a circle perimeter"<<endl;
		cout<<"4. Quit"<<endl;

		cout<<"Please enter your choice[1-4]: ";
		cin>>option;
		while(option>4||option<1){
			cout<<"INVALID, Please try again: ";
			cin>>option;
			cout<<endl;
		}

		if(option==1){
			cout<<"Please input the width of the rectangle: ";
			cin>>width;
			cout<<endl;
			cout<<"Please input the height of the rectangle: ";
			cin>>height;
			cout<<endl;
			cout<<"The perimeter of the rectangle is "<<(width + height) * 2<<endl;
		}
		if(option==2){
			cout<<"Please input the length of the first side of the triangle: ";
			cin>>lengthOfTheFirstSide;
			cout<<endl;
			cout<<"Please input the length of the second side of the triangle: ";
			cin>>lengthOfTheSecondSide;
			cout<<endl;
			cout<<"Please input the length of the second side of the triangle: ";
			cin>>lengthOfTheThirdSide;
			cout<<endl;
			cout<<"The perimeter of the triangle is "<<lengthOfTheFirstSide+lengthOfTheSecondSide+lengthOfTheThirdSide<<endl;

		}
		if(option==3){
			cout<<"Please input the radius of the circle: ";
			cin>>radius;
			cout<<endl;
			cout<<"The perimeter of the circle is "<<2 * 3.1416 * radius<<endl;
		}
		if(option==4){
			cout<<"BYE BYE BYE BYE BYE!"<<endl;
			break;
		}

	}




	return 0;
}







