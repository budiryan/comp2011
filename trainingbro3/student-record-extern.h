/*
 * student-record-extern.h
 *
 *  Created on: Apr 6, 2015
 *      Author: user
 */

#ifndef STUDENT_RECORD_EXTERN_H_
#define STUDENT_RECORD_EXTERN_H_





#endif /* STUDENT_RECORD_EXTERN_H_ */
/* File: student-record-extern.h */

void print_date(const Date&);
void print_student_record(const Student_Record&);
void init_date(Date& x, unsigned int, unsigned int, unsigned int);
void init_student_record(Student_Record&, const char[ ], unsigned int, char, Dept, const Date&);
void swap_SR(Student_Record&, Student_Record&);
void sort_3SR_by_id(Student_Record sr[ ]);

