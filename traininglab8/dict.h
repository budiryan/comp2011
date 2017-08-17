/*
 * dict.h
 *
 *  Created on: May 23, 2015
 *      Author: user
 */

#ifndef DICT_H_
#define DICT_H_
enum WordType{All, Animal, Fruit, Name};

struct Word{
    WordType type;
    char word[20];
};

struct Dict{
    int size;
    int capacity;
    Word **wordArray;
};

Dict *createDictionary(int capacity);
bool addWord(Dict *dic, const char *word, WordType type);
void deleteDictionary(Dict *dic);
void printDictionary(Dict *dic, WordType type=All);





#endif /* DICT_H_ */
