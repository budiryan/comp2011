/*
 * dict.cpp
 *
 *  Created on: May 23, 2015
 *      Author: user
 */
#include "dict.h"
#include <cstring>
#include <iostream>
using namespace std;

Dict *createDictionary(int capacity){
    //TODO: initialize a dictionary with the specified capacity
	Dict *dic=new Dict;
	dic->capacity=capacity;
	dic->size=0;
	dic->wordArray=new Word*[capacity];
	for(int i=0;i<capacity;i++){
		dic->wordArray[i]=NULL;
	}
	return dic;


}

bool addWord(Dict *dic, const char *word, WordType type){
    //TODO: add a Word to the dictionary. If the dictionary is already full (can’t add addtional words), return false. Otherwise, add the word to the dictionary, increase dictionary size by 1, and return true.
	if(dic->size==dic->capacity){
		cout<<"dictionary is already full"<<endl;
		return false;
	}
Word* a=new Word;
strcpy(a->word,word);
a->type=type;
dic->wordArray[dic->size]=a;
dic->size++;
return true;
}

void deleteDictionary(Dict *dic){
    //TODO: release all the dynamically-allocated memory for the dictionary
	for(int i=0;i<(dic->size);i++){
		delete [] dic->wordArray[i];
	}
}

void printDictionary(Dict *dic, WordType type){
    //TODO: for default type all (specified in the header file), print words of all types. Otherwise print words of the specified type
	switch(type){
	case 0:
		for(int i=0;i<dic->size;i++){
			cout<<dic->wordArray[i]->word<<" ";
		}cout<<endl;break;
	case 1:
		for(int i=0;i<dic->size;i++){
			if(dic->wordArray[i]->type==Animal){
				cout<<dic->wordArray[i]->word<<" ";
			}
		}cout<<endl;break;
	case 2:
		for(int i=0;i<dic->size;i++){
			if(dic->wordArray[i]->type==Fruit){
				cout<<dic->wordArray[i]->word<<" ";
			}
		}cout<<endl;break;
	case 3:
		for(int i=0;i<dic->size;i++){
			if(dic->wordArray[i]->type==Name){
				cout<<dic->wordArray[i]->word<<" ";
			}
		}cout<<endl;break;
	}
}



