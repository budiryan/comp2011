/*
 * main.cpp
 *
 *  Created on: May 23, 2015
 *      Author: user
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "dict.h"
using namespace std;

void guessWord(Dict *dic) {
    //hint: you may use srand, rand, and time functions to generate random numbers
    //e.g.
    //srand(time(NULL));
    //int randomNumberBetweenZeroAndN = rand() % (n+1);
	srand(time(NULL));
	int randomnumber=rand()%(dic->size);
	char choosenword[100];
	strcpy(choosenword,dic->wordArray[randomnumber]->word);
	int randomletter=rand()%(strlen(choosenword));
	int chances=3;
	cout<<"Guess this word..:";
	for(int i=0;i<strlen(choosenword);i++){
		if (i==randomletter){
			cout<<"*";
		}
		else cout<<choosenword[i];
	}
	cout<<" type: ";
	switch(dic->wordArray[randomnumber]->type){
	case 1:
		cout<<" Animal";break;k
	case 2:
		cout<<" Fruit";break;
	case 3:
		cout<<" Name";break;
	}
	char guessedword[100];
while(chances>0){
	cin.getline(guessedword,100);
	if(strcmp(guessedword,dic->wordArray[randomnumber]->word)==0){
		cout<<"You won the game";
		break;
	}
	else chances--;cout<<"Try again! you have "<<chances<<" left"<<endl;
	}
if(chances==0){
	cout<<"GAMEOVER! BITCH!";
}

}

int main() {

    cout << "======= Word guessing game =======" << endl << endl;

    Dict *dic = createDictionary(100);
    addWord(dic, "apple", Fruit);
    addWord(dic, "banana", Fruit);
    addWord(dic, "kiwi", Fruit);
    addWord(dic, "blackberry", Fruit);
    addWord(dic, "strawberry", Fruit);
    addWord(dic, "lemon", Fruit);
    addWord(dic, "orange", Fruit);
    addWord(dic, "cherry", Fruit);

    addWord(dic, "pig", Animal);
    addWord(dic, "dog", Animal);
    addWord(dic, "cat", Animal);
    addWord(dic, "ant", Animal);
    addWord(dic, "bat", Animal);
    addWord(dic, "ape", Animal);
    addWord(dic, "bear", Animal);
    addWord(dic, "alligator", Animal);
    addWord(dic, "crocodile", Animal);
    addWord(dic, "lobster", Animal);
    addWord(dic, "octopus", Animal);
    addWord(dic, "sheep", Animal);
    addWord(dic, "whale", Animal);
    addWord(dic, "shrimp", Animal);
    addWord(dic, "goldfish", Animal);

    addWord(dic, "john", Name);
    addWord(dic, "candy", Name);
    addWord(dic, "luke", Name);
    addWord(dic, "anna", Name);
    addWord(dic, "taylor", Name);

    cout << "All words:\n";
    printDictionary(dic);
    cout << "Animals only:\n";
    printDictionary(dic, Animal);
    cout << "Fruits only:\n";
    printDictionary(dic, Fruit);
    cout << "Names only:\n";
    printDictionary(dic, Name);

    guessWord(dic);

    //delete the dictionary and release all the memory that was dynamically allocated
    deleteDictionary(dic);

    return 0;
}



