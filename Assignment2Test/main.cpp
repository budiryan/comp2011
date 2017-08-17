/*
 * main.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: user
 */
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
	world[x][y]='Z';
		if(world[x+1][y]=='H'){
			spreadZombie(x+1,y,world);
		}
		if(world[x][y+1]=='H'){
			spreadZombie(x,y+1,world);
		}
		if(world[x][y-1]=='H'){
			spreadZombie(x,y-1,world);
		}
		if(world[x-1][y]=='H'){
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
	char world[HEIGHT][WIDTH] =
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
	};

	char answer[HEIGHT][WIDTH] =
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
		{'H','H','W','W','H','H','X','X','X','Z'}
	};

	spreadZombie(9, 9, world);

	bool isCorrectAnswer = true;
	for(int x=0; x<HEIGHT; x++)
	{
		for(int y=0; y<WIDTH; y++)
		{
			if(world[x][y] != answer[x][y])
			{
				isCorrectAnswer = false;
			}
		}
	}

	cout << endl << endl << "Model answer:" << endl;
	printWorld(answer);
	cout << endl << endl << "Your answer" << endl;
	printWorld(world);
	cout << endl << endl;
	cout << (isCorrectAnswer?"Correct":"Incorrect") << endl;

	return 0;
}










