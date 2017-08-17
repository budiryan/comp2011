/*
 * book.cpp
 *
 *  Created on: May 22, 2015
 *      Author: user
 */
#include "book.h" /* File: book.cpp; an app written by an application programmer */
void make_books(void)
{
    Book y("Love", "HKUST", 88);
    Book* p = new Book [3];
    p[0].set("book1", "author1", 1);
    p[1].set("book2", "author2", 2);
    p[2].set("book3", "author3", 3);

    delete [ ] p; cout << endl;
    return;
}

int main(void)
{
    Book x("War", "Hitler", 1000);
    Book* z = new Book("Outliers", "Gladwell", 300);

    make_books( ); cout << endl;
    delete z; cout << endl;
    z = NULL;
    return 0;
}






