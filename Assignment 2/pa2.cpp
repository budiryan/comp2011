/*
 * pa2.cpp
 *
 *  Created on: Apr 2, 2015
 *      Author: user
 */
/*
 * COMP2011 (Spring 2015) Assignment 2: The super zombie outbreak simulator
 *
 * Student name: Budi Ryan
 * Student ID: 20214841
 * Student email: bryanaa@ust.hk
 * Student lab section: LA2
 */
#include <iostream>

using namespace std;

const int NUM_OF_WORLDS = 4;
const int HEIGHT = 10;
const int WIDTH = 10;

//print the world
//do NOT modify it
void printWorld(const char world[][WIDTH])
{
	for(int x=0; x<HEIGHT; x++)
	{
		for(int y=0; y<WIDTH; y++)
		{
			cout << world[x][y] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//spread the zombie virus
//remember x is the vertical coordinate and y is the horizontal coordinate
void spreadZombie(int x, int y, char world[][WIDTH])
{
	//TODO: Finish this function. You must use a recursive approach. No loop of any kind is allowed.
	if((world[x][y]=='W')||(world[x][y]=='O')||(world[x][y]=='S')||(world[x][y]=='X')||(x>9)||(x<0)||(y<0)||(y>9)){
			return;}
	else{
		world[x][y]='Z';

			spreadZombie(x+1,y,world);


			spreadZombie(x,y+1,world);


			spreadZombie(x,y-1,world);
			spreadZombie(x-1,y,world);
	}
	}

//spread the super zombie virus
void spreadSuperZombie(int x, int y, char world[][WIDTH])
{
	//TODO: Finish this function. You must use a recursive approach. No loop of any kind is allowed.
	if((world[x][y]=='W')||(world[x][y]=='O')||(world[x][y]=='S')||(world[x][y]=='X')||(x>9)||(x<0)||(y<0)||(y>9)){
		return;}//base case
		world[x][y]='S';
		spreadSuperZombie(x+1,y,world);
		spreadSuperZombie(x,y+1,world);
		spreadSuperZombie(x,y-1,world);
		spreadSuperZombie(x-1,y,world);
		spreadSuperZombie(x+1,y+1,world);
		spreadSuperZombie(x+1,y-1,world);
		spreadSuperZombie(x-1,y+1,world);
		spreadSuperZombie(x-1,y-1,world);

}

//spread the overpowered zombie virus
void spreadOverpoweredZombie(int x, int y, char world[][WIDTH], int zombiePower)
{
	//TODO: Finish this function. You must use a recursive approach. You may have loops for this one, but you must still use recursion (calling spreadOverpoweredZombie) to spread the virus.
	if((x>9)||(x<0)||(y>9)||(y<0)||(world[x][y]=='W')||world[x][y]=='O'||world[x][y]=='X'){
		return;}//base case
	world[x][y]='O';
	for(int i=1;i<=zombiePower;++i){
	spreadOverpoweredZombie(x+i,y+i,world,zombiePower);
	spreadOverpoweredZombie(x-i,y-i,world,zombiePower);
	spreadOverpoweredZombie(x+i,y-i,world,zombiePower);
	spreadOverpoweredZombie(x-i,y+i,world,zombiePower);
	spreadOverpoweredZombie(x,y+i,world,zombiePower);
	spreadOverpoweredZombie(x,y-i,world,zombiePower);
	spreadOverpoweredZombie(x+i,y,world,zombiePower);
	spreadOverpoweredZombie(x-i,y,world,zombiePower);
	}
}
//spread the bomb
void spreadBomb(int x, int y, char world[][WIDTH], int bombPower)
{
	//TODO: Finish this function. You must use a recursive approach. No loop of any kind is allowed.
	if((bombPower<0)||x>9||x<0||y>9||y<0){
		return;
	}
	world[x][y]='X';
	spreadBomb(x+1,y+1,world,bombPower-1);
	spreadBomb(x-1,y-1,world,bombPower-1);
	spreadBomb(x+1,y-1,world,bombPower-1);
	spreadBomb(x-1,y+1,world,bombPower-1);
	spreadBomb(x,y+1,world,bombPower-1);
	spreadBomb(x,y-1,world,bombPower-1);
	spreadBomb(x+1,y,world,bombPower-1);
	spreadBomb(x-1,y,world,bombPower-1);
}

//main function is the entry point of the program
//do NOT modify the code inside the main function except for the "world" array
int main()
{
	//define the 4 worlds (you may edit the worlds to test your functions)
	char world[NUM_OF_WORLDS][HEIGHT][WIDTH] =
	{
		{
				{'H','H','H','H','H','H','H','H','H','H'},
				{'H','W','W','H','H','H','W','H','H','H'},
				{'H','W','H','W','H','W','H','W','H','H'},
				{'H','W','W','W','H','H','W','H','H','H'},
				{'H','H','H','H','H','W','H','H','H','H'},
				{'H','H','H','H','H','H','H','H','H','H'},
				{'H','H','H','H','H','H','H','H','X','X'},
				{'W','W','W','W','H','H','H','H','X','X'},
				{'W','W','W','W','H','H','X','X','X','X'},
				{'H','H','W','W','H','H','X','X','X','H'}
		},
		{
			{'H','H','H','H','H','H','H','H','H','H'},
			{'H','W','W','W','H','H','H','H','H','H'},
			{'W','H','H','H','H','H','H','H','H','H'},
			{'W','H','H','H','W','H','H','H','H','H'},
			{'W','H','H','H','W','H','H','H','H','H'},
			{'H','W','W','W','H','H','H','H','H','H'},
			{'H','H','H','H','H','H','H','W','W','W'},
			{'H','H','H','H','H','H','H','H','H','W'},
			{'H','H','H','H','H','H','H','W','H','W'},
			{'H','H','H','H','H','H','H','W','W','W'}
		},
		{
			{'H','H','H','H','H','H','H','H','H','H'},
			{'W','W','W','W','W','H','H','H','H','H'},
			{'W','H','H','H','W','H','H','H','H','H'},
			{'W','H','H','H','W','H','H','H','H','H'},
			{'W','H','H','H','W','H','H','H','H','H'},
			{'W','W','W','W','W','H','W','W','W','W'},
			{'H','H','H','H','H','H','W','W','W','W'},
			{'H','H','H','H','H','H','W','W','H','W'},
			{'H','H','H','H','H','H','W','W','H','W'},
			{'H','H','H','H','H','H','W','W','W','W'}
		},
		{
			{'H','H','H','H','H','H','H','H','H','H'},
			{'H','W','W','H','H','H','W','H','H','H'},
			{'H','W','H','W','H','W','H','W','H','H'},
			{'H','W','W','W','H','H','W','H','H','H'},
			{'H','H','H','H','H','W','H','H','H','H'},
			{'H','H','H','H','H','H','H','H','H','H'},
			{'H','H','H','H','H','H','H','H','H','H'},
			{'W','W','W','W','H','H','H','H','H','H'},
			{'W','W','W','W','H','H','H','H','W','W'},
			{'H','H','W','W','H','H','H','H','W','H'}
		}
	};

	//welcome the user
	cout << "Welcome to the Zombie Outbreak Simulator!" << endl <<
			"The world is coming to an end... :(" << endl << endl;

	//print the worlds
	for(int i=0; i<NUM_OF_WORLDS; i++)
	{
		cout << "World " << i << ": " << endl;
		printWorld(world[i]);
	}

	//get the world number
	int worldNumber;
	cout << "Pick a world number. [0-" << (NUM_OF_WORLDS-1) << "]" << endl;
	cin >> worldNumber;

	char continueAnswer;
	do
	{
		//show the world before the outbreak
		cout << endl << "Before the spread:" << endl;
		printWorld(world[worldNumber]);

		//make sure the input is correct (look until isValidInput becomes true)
		bool isValidInput = false;
		int spreadType;
		int x, y;
		while(!isValidInput)
		{
			//choose the spread type and the unfortunate subject
			cout << "Choose the spread type [0:Zombie 1:SuperZombie 2:OverpoweredZombie 3:Bomb]: " << endl;
			cin >> spreadType;
			cout << "Choose the unfortunate subject. Input the x (vertical) and y (horizontal) coordinates:" << endl;
			cin >> x >> y;

			switch(spreadType)
			{
				case 0: //zombies can only infect humans
					if(world[worldNumber][x][y]!='H')
						cout << "Spread cannot start there! Choose again." << endl;
					else
						isValidInput = true;
					break;

				case 1: //superzombies can only infect humans or basic zombies
					if(world[worldNumber][x][y]!='H' && world[worldNumber][x][y]!='Z')
						cout << "Spread cannot start there! Choose again." << endl;
					else
						isValidInput = true;
					break;

				case 2: //overpoweredzombies can only infect humans or basic zombies or superzombies
					if(world[worldNumber][x][y]!='H' && world[worldNumber][x][y]!='Z' && world[worldNumber][x][y]!='S')
						cout << "Spread cannot start there! Choose again." << endl;
					else
						isValidInput = true;
					break;

				case 3: //no restriction for bombs!
					isValidInput = true;
					break;

				default:
					cout << "Wrong spread type! Choose again." << endl;
					break;

			}
		}

		//spread whatever that was chosen!
		switch(spreadType)
		{
			case 0: //zombie
				spreadZombie(x, y, world[worldNumber]);
				break;

			case 1: //superzombie
				spreadSuperZombie(x, y, world[worldNumber]);
				break;

			case 2: //overpoweredzombie
				int zombiePower;
				cout << "Input the zombie power:" << endl;
				cin >> zombiePower;
				spreadOverpoweredZombie(x, y, world[worldNumber], zombiePower);
				break;

			case 3: //bomb
				int bombPower;
				cout << "Input the bomb power:" << endl;
				cin >> bombPower;
				spreadBomb(x, y, world[worldNumber], bombPower);
				break;
		}

		//show the world after the outbreak
		cout << endl << "After the spread:" << endl;
		printWorld(world[worldNumber]);

		cout << "Spread some more stuff? (y/n)" << endl;
		cin >> continueAnswer;
	}
	while(continueAnswer=='y');

	//say goodbye
	cout << endl << "Bye!" << endl;

	//exit the program
	return 0;
}




