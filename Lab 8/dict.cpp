/*
 * main.cpp
 *
 *  Created on: Apr 11, 2015
 *      Author: user
 */
#include "dict.h"
#include <cstring>
#include <iostream>
using namespace std;

Dict *createDictionary(int capacity){
    //TODO: initialize a dictionary with the specified capacity
	Dict *newdict= new Dict;
	newdict->capacity=capacity;
	newdict->size=0;
	newdict->wordArray=new Word*[capacity];//Creates an array of objects
	for(int i=0;i<capacity;++i){
		newdict->wordArray[i]=NULL;
	}
	return newdict;

}

bool addWord(Dict *dic, const char *word, WordType type){
    //TODO: add a Word to the dictionary. If the dictionary is already full (can’t add addtional words), return false. Otherwise, add the word to the dictionary, increase dictionary size by 1, and return true.
	if(dic->size==dic->capacity){cout<<"The dictionary is already full!"<<endl;
	return false;}
	Word *a=new Word; //Pointer that points to a new word
	a->type=type;
	strcpy(a->word,word);
	dic->wordArray[dic->size] = a;
	++dic->size;
	return true;


}

void deleteDictionary(Dict *dic){
    //TODO: release all the dynamically-allocated memory for the dictionary
	for(int j=0;j<(dic->size);++j){
		delete []dic->wordArray[j];
	}

	delete dic;
}

void printDictionary(Dict *dic, WordType type){
    //TODO: for default type all (specified in the header file), print words of all types. Otherwise print words of the specified type
	switch(type){
	case 0:{
		for(int k=0;k<(dic->size);++k){
			cout<<dic->wordArray[k]->word<<" ";
		}cout<<endl<<endl;
		break;}
	case 1:{
		for(int k=0;k<(dic->size);++k){
			if(dic->wordArray[k]->type==Animal)
					cout<<dic->wordArray[k]->word<<" ";
				}cout<<endl<<endl;
  break;}
	case 2:{
		for(int k=0;k<(dic->size);++k){
					if(dic->wordArray[k]->type==Fruit)
							cout<<dic->wordArray[k]->word<<" ";
						}cout<<endl<<endl;
	break;}
	case 3:{
		for(int k=0;k<(dic->size);++k){
					if(dic->wordArray[k]->type==Name)
							cout<<dic->wordArray[k]->word<<" ";
						}
		cout<<endl<<endl;
break;	}
	}
}
void printcategory(WordType Type){
	char WordTypeD[][20]={"All","Animal","Fruit","Name"};
	cout<<" Type: "<<WordTypeD[Type];
}


