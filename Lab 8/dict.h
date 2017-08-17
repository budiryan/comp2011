/*
 * dict.h
 *
 *  Created on: Apr 11, 2015
 *      Author: user
 */

#ifndef DICT_H_
#define DICT_H_





#endif /* DICT_H_ */
enum WordType{All, Animal, Fruit, Name};

struct Word{
    WordType type;
    char word[20];
};

struct Dict{
    int size;
    int capacity;
    Word** wordArray;// a POINTER to a POINTER that points to a WORD
};

Dict *createDictionary(int capacity);
bool addWord(Dict *dic, const char *word, WordType type);
void deleteDictionary(Dict *dic);
void printDictionary(Dict *dic, WordType type=All);
