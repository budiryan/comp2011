/*
 * student-record-array.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: user
 */
#include <iostream> /* File: student-record-array.cpp */
using namespace std;
#include "student-record.h"
#include "student-record-extern.h"

int main(void)
{
    Student_Record sr[ ] = {
        { "Adam", 12000, 'M', CSE, { 2006 , 1 , 10 } },
        { "Bob", 11000, 'M', MATH, { 2005 , 9 , 1 } },
        { "Cathy", 10000, 'F', ECE, { 2006 , 8 , 20 } } };

    for (int j = 0; j < sizeof(sr)/sizeof(Student_Record); ++j)
        print_student_record(sr[j]);
    cout<<sizeof(sr)<<"   "<<sizeof(Student_Record)<<endl;
    cout<<sr[0].name<<sr[1].name<<sr[2].name<<endl;


    return 0;
}

/* g++ student-record-array.cpp student-record-functions.cpp */




