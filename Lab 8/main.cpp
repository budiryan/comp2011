/*
 * main.cpp
 *
 *  Created on: Apr 11, 2015
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
	cout<<"Guess this word: "<<endl;
	srand(time(NULL));
	int randomword=rand()%(dic->size);

	switch(dic->wordArray[randomword]->type){

	case All:{
		cout<<" Type: All"<<endl;
	break;}
	case Animal:{
		cout<<" Type: Animal"<<endl;
	break;}
	case Fruit:{
		cout<<" Type: Fruit"<<endl;
	break;}
	case Name:{
		cout<<" Type: Name"<<endl;
	break;}
	}

	char *word = dic->wordArray[randomword]->word;
	int randomchar=rand()%(strlen(word));
	char letter=word[randomchar];

	for(int l=0;l<strlen(word);++l){
		if (word[l]==letter)cout<<"*";
		else cout<<word[l];
	}
	char userinput[100];

	int chance=3;
	while(true){
		cin>>userinput;
		if(strcmp(userinput,word)==0){
			cout<<"YOU WON THE GAME!!!"<<endl;
			break; }
		else{
			chance--;
			cout<<"WRONG! YOU HAVE "<<chance<<" CHANCE(S) LEFT!!!"<<endl;;
		}
		if(chance==0){
			cout<<"GAMEOVER, YOU LOST THE GAME, THE ANSWER IS ";
			for(int m=0;m<strlen(word);++m){
				cout<<word[m];
			}
			break;
		}
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



