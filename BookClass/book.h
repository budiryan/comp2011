/*
 * book.h
 *
 *  Created on: May 22, 2015
 *      Author: user
 */

#ifndef BOOK_H_
#define BOOK_H_
#include <iostream> /* File: book.h */
using namespace std;
class Book // Class definition written by class developer
{
  private:
    char* title;
    char* author;
    int num_pages;

  public:
    Book(int n = 100) { title = author = NULL; num_pages = n; }
    Book(const char* t, const char* a, int n = 5) { set(t, a, n); }
    ~Book(void)
    {
        cout << "Delete the book titled \"" << title << "\"" << endl;
        delete [ ] title; delete [ ] author;
    }

    void set(const char* t, const char* a, int n)
    {
        title = new char [strlen(t)+1]; strcpy(title, t);
        author = new char [strlen(a)+1]; strcpy(author, a);
        num_pages = n;
    }
};





#endif /* BOOK_H_ */
