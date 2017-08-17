/*
 * main.cpp
 *
 *  Created on: May 22, 2015
 *      Author: user
 */
#include <iostream>

using namespace std;

const int NUM_OF_WORLDS = 4;
const int HEIGHT = 10;
const int WIDTH = 10;


//print the world
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

//isWorldEnd returns true if there is no human left, or returns false otherwise
bool isWorldEnded(const char world[][WIDTH])
{
	//TODO: finish this function.
	//base case
	int row,col;
	for(int row=0;row<10;++row){
		for(int col=0;col<10;++col){
			if(world[row][col]=='H'){
				return false;
			}
		}
	}
	return true;
}

//spread the zombie virus
//remember x is the vertical coordinate and y is the horizontal coordinate
void spreadZombie(int x, int y, char world[][WIDTH])
{
	//TODO: finish this function. You must use a recursive approach.
	//base case
	if(world[x][y]!='H'||x>9||x<0||y<0||y>9){
		return;
	}
	world[x][y]='Z';
	spreadZombie(x+1,y,world);
	spreadZombie(x,y+1,world);
	spreadZombie(x-1,y,world);
	spreadZombie(x,y-1,world);
}

//main function is the entry point of the program
int main()
{
	//define the 4 worlds
	char world[NUM_OF_WORLDS][HEIGHT][WIDTH] =
	{
		{
			{'H','H','H','H','H','H','H','H','H','H'},
			{'H','W','W','W','H','H','H','H','H','H'},
			{'W','H','H','H','W','H','H','H','H','H'},
			{'W','H','H','H','W','H','H','H','H','H'},
			{'W','H','H','H','W','H','H','H','H','H'},
			{'H','W','W','W','H','H','H','H','H','H'},
			{'H','H','H','H','H','H','H','W','W','W'},
			{'H','H','H','H','H','H','H','W','H','W'},
			{'H','H','H','H','H','H','H','W','H','W'},
			{'H','H','H','H','H','H','H','W','W','W'}
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
			{'H','H','H','H','H','H','H','H','H','H'},
			{'H','H','H','H','H','H','H','H','H','H'},
			{'H','H','H','H','H','H','H','H','H','H'},
			{'H','H','H','H','H','H','H','H','H','H'},
			{'H','H','H','H','H','H','H','H','H','H'},
			{'H','H','H','H','H','H','H','H','H','H'},
			{'H','H','H','H','H','H','H','H','H','H'},
			{'H','H','H','H','H','H','H','H','H','H'},
			{'H','H','H','H','H','H','H','H','H','H'}
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

	//show the world before the outbreak
	cout << endl << "Before the Zombie Outbreak:" << endl;
	printWorld(world[worldNumber]);

	//choose the unfortunate human
	int x, y;
	cout << "Choose the unfortunate human. Input the x (vertical) and y (horizontal) coordinates:" << endl;
	cin >> x >> y;
	while(world[worldNumber][x][y]!='H') //make sure that is really a human so that the infection can begin
	{
		cout << "Only humans can be infected! Choose again." << endl;
		cin >> x >> y;
	}

	//spread the virus!
	spreadZombie(x, y, world[worldNumber]);

	//show the world after the outbreak
	cout << endl << "After the Zombie Outbreak:" << endl;
	printWorld(world[worldNumber]);

	//world ended?
	if(isWorldEnded(world[worldNumber]))
	{
		cout << "OMG! WORLD ENDED!" << endl;
	}
	else
	{
		cout << "Humans survived... for now!" << endl;
	}

	//exit the program
	return 0;
}



