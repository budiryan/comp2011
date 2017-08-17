/*
 * student-record.h
 *
 *  Created on: Apr 6, 2015
 *      Author: user
 */

#ifndef STUDENT_RECORD_H_
#define STUDENT_RECORD_H_





#endif /* STUDENT_RECORD_H_ */
/* File: student-record.h */
enum Dept { CSE, ECE, MATH };

struct Date
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

struct Student_Record
{
    char name[32];
    unsigned int id;
    char gender;
    Dept dept;
    Date entry;
};
// Global constants for department names
const char dept_name[ ][30]
  = {"Computer Science", "Electrical Engineering", "Mathematics"};
