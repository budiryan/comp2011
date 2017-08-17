/*
 * Patient.cpp
 *
 *  Created on: Apr 19, 2015
 *      Author: user
 */


#include <iostream>
#include "Patient.h"
using namespace std;

Patient* new_patient(const char p_name[MAX_NAME_LENGTH+1], int p_severity_index) {
	// TODO1: Create new patient and set his/her name and severity index accordingly, input validation is not needed.
	Patient *newpatient=new Patient;
	strcpy(newpatient->name,p_name);
	newpatient->severity_index=p_severity_index;
	newpatient->next=NULL;
	return newpatient;

}

void insert_patient(Patient*& head, Patient* p) {
	// TODO2: Insert the patient p into the emergency service queue in ascending order of the severity index

	if(head == NULL) { //empty queue
			head = p;
			p->next = NULL;
			return;
		}

		Patient* prev = NULL;
		Patient* current = head;
		while(current != NULL && p->severity_index >= current->severity_index ) {
			prev = current;
			current = current->next;
		}

		if(current==head){
		p->next=head;
		head=p;
		return;
		}
		else if(current==NULL){
			prev->next=p;
			p->next=NULL;
			return;
		}
		else{
			prev->next=p;
			p->next=current;
			return;

		}


}


void view_patients(const Patient* const head) {
	// TODO3: View all patients in the queue, the output format should be:
	// name: name of the patient (tab or spaces) severity index: severity index of the patient
	// Note: display message like "Empty queue" if the queue is empty
	// Please refer to the output example in the lab manual page.
	if(head == NULL) {
		cout << "Current queue is empty." << endl;
		return;
	}

	cout << "Current queue of the emergency service." << endl;
	const Patient* current = head;
	while(current != NULL) {
		cout << "Name: " << current->name << "\tSeverity Index: " << current->severity_index << endl;
		current = current->next;
	}
}
/*
 * void modify_patient_severity_index(Patient*& head, int pos, int severity_index) {
// TODO4: Change the severity index of the patient who is at the (pos)th place in the queue, then re-arrange the patient to a correct position
// Note1: pos starts from 1
// Note2: You don't need to do input validation for pos and severity_index
// Hint: The insert_patient function can be helpful
if (head == NULL) {
return;
}

Patient* prev = NULL;
Patient* current = head;
int i = 1;
while(current != NULL && i != pos){
prev = current;
current = current->next;
i++;
}

if (current == head) {
current->severity_index = severity_index;
if(current->next != NULL && current->severity_index >= current->next->severity_index){
head = head->next;
insert_patient(head, current);
}
return;
} else if (current == NULL){
return;
} else {
current->severity_index = severity_index;
if((current->next != NULL && current->severity_index >= current->next->severity_index) || (prev->severity_index > current->severity_index)){
prev->next = current->next;
insert_patient (head, current);
}
}
return;
}
 *
 */

void modify_patient_severity_index(Patient*& head, int pos, int severity_index) {
	// TODO4: Change the severity index of the patient who is at the (pos)th place in the queue, then re-arrange the patient to a correct position
	// Note1: pos starts from 1
	// Note2: You don't need to do input validation for pos and severity_index
	// Hint: The insert_patient function can be helpful
if(head==NULL){
	return;
}
Patient *previous=NULL;
Patient *current=head;
int i=1;
while(current != NULL && i != pos){
previous = current;
current = current->next;
i++;
}
if(current == head) { // the first one
		current->severity_index = severity_index;
		if(current->next != NULL && current->severity_index >= current->next->severity_index) { // greater than the next one
			head = head->next;
			insert_patient(head, current);
		}
		return;
	}
else if(current == NULL) { // not found
		return;
	}
else { // general case
		current->severity_index = severity_index;
		if( (current->next != NULL && current->severity_index >= current->next->severity_index) || // greater than the next one
				(previous->severity_index > current->severity_index ) ) { // or smaller than the previous one
			previous->next = current->next;
			insert_patient(head, current);
		}
		return;
	}
}

void delete_patients(const Patient* const head) {
	// TODO5: delete (release the dynamic memory for) all the Patient objects in the list


	const Patient* current=head;
	const Patient* temp; //DUMMY POINTER
	cout<<"STARTING DELETING OPERATION"<<endl;
	while(current!=NULL){
		cout<<"DELETING "<<current->name<<endl;
		temp=current;
		current=current->next;
		delete temp;
		temp=NULL;



	}
	if(current==NULL){
		cout<<"COMPLETELY DELETED... CONGRATULATIONS"<<endl;
	}


	return;


}

Patient* dispatch_patient(Patient*& head) {
	if(head == NULL) {
		return NULL;
	}

	Patient* dispatchedPatient = head;
	head = head->next;
	dispatchedPatient->next=NULL;
	return dispatchedPatient; //return the dispatchedPatient to the caller (the main function) as the caller will need it
}

void list_patients(const Patient* const head) {
	const Patient* current = head;
	int i = 1;
	while(current != NULL) {
		cout << i << ": " << current->name << endl;
		current = current->next;
		i++;
	}
}
/*
#include <iostream>
#include "Patient.h"
using namespace std;

Patient* new_patient(const char p_name[MAX_NAME_LENGTH+1], int p_severity_index) {
// TODO1: Create new patient and set his/her name and severity index accordingly, input validation is not needed.
Patient* patient = new Patient;
strcpy(patient->name, p_name);
patient->severity_index = p_severity_index;
patient->next = NULL;

return patient;
}

void insert_patient(Patient*& head, Patient* p) {
// TODO2: Insert the patient p into the emergency service queue in ascending order of the severity index
if(head ==NULL){
head = p;
p->next = NULL;
return;
}

Patient* prev = NULL;
Patient* current = head;
while (current != NULL && p->severity_index >= current->severity_index){
prev = current;
current = current->next;
}

if (current == head) {
p->next = head;
head = p;
return;
} else if (current == NULL) {
prev->next = p;
p->next = NULL;
return;
} else {
prev->next = p;
p->next = current;
return;
}
}

void view_patients(const Patient* const head) {
// TODO3: View all patients in the queue, the output format should be:
// name: name of the patient (tab or spaces) severity index: severity index of the patient
// Note: display message like "Empty queue" if the queue is empty
// Please refer to the output example in the lab manual page.
if (head == NULL){
cout << "Current queue is empty." << endl;
return;
}

cout << "Current queue of the emergency service." << endl;
const Patient* current = head;
while (current != NULL) {
cout << "Name: " << current->name << "\tSeverity Index: " << current->severity_index << endl;
current = current->next;
}
}

void modify_patient_severity_index(Patient*& head, int pos, int severity_index) {
// TODO4: Change the severity index of the patient who is at the (pos)th place in the queue, then re-arrange the patient to a correct position
// Note1: pos starts from 1
// Note2: You don't need to do input validation for pos and severity_index
// Hint: The insert_patient function can be helpful
if (head == NULL) {
return;
}

Patient* prev = NULL;
Patient* current = head;
int i = 1;
while(current != NULL && i != pos){
prev = current;
current = current->next;
i++;
}

if (current == head) {
current->severity_index = severity_index;
if(current->next != NULL && current->severity_index >= current->next->severity_index){
head = head->next;
insert_patient(head, current);
}
return;
} else if (current == NULL){
return;
} else {
current->severity_index = severity_index;
if((current->next != NULL && current->severity_index >= current->next->severity_index) || (prev->severity_index > current->severity_index)){
prev->next = current->next;
insert_patient (head, current);
}
}
return;
}

void delete_patients(const Patient* const head) {
// TODO5: delete (release the dynamic memory for) all the Patient objects in the list
if (head == NULL){
cout << "Empty list" << endl;
return;
}

delete_patients(head->next);
cout << "deleting " << head->name << endl;
delete head;

}

Patient* dispatch_patient(Patient*& head) {
if(head == NULL) {
return NULL;
}

Patient* dispatchedPatient = head;
head = head->next;
return dispatchedPatient; //return the dispatchedPatient to the caller (the main function) as the caller will need it
}

void list_patients(const Patient* const head) {
const Patient* current = head;
int i = 1;
while(current != NULL) {
cout << i << ": " << current->name << endl;
current = current->next;
i++;
}
}
*/


