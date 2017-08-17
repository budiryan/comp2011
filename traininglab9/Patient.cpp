/*
 * Patient.cpp
 *
 *  Created on: May 23, 2015
 *      Author: user
 */
#include <iostream>
#include "Patient.h"
using namespace std;

Patient* new_patient(const char p_name[MAX_NAME_LENGTH+1], int p_severity_index) {
	// TODO1: Create new patient and set his/her name and severity index accordingly, input validation is not needed.
	Patient* newpatient= new Patient;
	strcpy(newpatient->name,p_name);
	newpatient->severity_index=p_severity_index;
	newpatient->next=NULL;
	return newpatient;
}

void insert_patient(Patient*& head, Patient* p) {
	// TODO2: Insert the patient p into the emergency service queue in ascending order of the severity index
	//Case 1: List kosong
	if(head==NULL){
		head=p;
		p->next=NULL;
		return;
	}
	//Case 2: Di tengah2
	Patient *prev=NULL;
	Patient *current=head;
	while(current!=NULL && p->severity_index>=current->severity_index){
		prev=current;
		current=current->next;
	}
	if(current==head){
		p->next=head;
		head=p;
		return;
	}

	//case 3: kalo di akhir2
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
	//case 1: kalo di awal2

}

void view_patients(const Patient* const head) {
	// TODO3: View all patients in the queue, the output format should be:
	// name: name of the patient (tab or spaces) severity index: severity index of the patient
	// Note: display message like "Empty queue" if the queue is empty
	// Please refer to the output example in the lab manual page.
	//If the queue is empty:
	cout<<"Current queue of the emergency service: "<<endl;
	if(head==NULL){
		cout<<"Nothing to display"<<endl;
		return;
	}
	const Patient* current=head;
	while(current!=NULL){
		cout<<"Name: "<<current->name<<"\tSeverity Index: "<<current->severity_index<<endl;
		current=current->next;
	}
return;
}

void modify_patient_severity_index(Patient*& head, int pos, int severity_index) {
	// TODO4: Change the severity index of the patient who is at the (pos)th place in the queue, then re-arrange the patient to a correct position
	// Note1: pos starts from 1
	// Note2: You don't need to do input validation for pos and severity_index
	// Hint: The insert_patient function can be helpful
if(head==NULL)return;
Patient* current=head;
Patient* prev=NULL;
int i=1;
while(current!=NULL && i!=pos){
	prev=current;
	current=current->next;
	i++;
}
//1st case: head=current
if(head==current){
	current->severity_index=severity_index;
	if(current->severity_index>=current->next->severity_index&&current->next!=NULL){
		head=head->next;
		insert_patient(head,current);
	return;}
	}
//2nd case: not found
else if(current==NULL){
	cout<<"Pos is invalid!"<<endl;
	return;
}
//3rd case: current is in the end
//General case:
else {
	current->severity_index=severity_index;
	if(current->severity_index>=current->next->severity_index||current->next!=NULL){
	prev->next=current->next;
	insert_patient(head,current);}
}
}

void delete_patients(const Patient* const head) {
	// TODO5: delete (release the dynamic memory for) all the Patient objects in the list
const Patient* current=head;
while(current!=NULL){
	cout<<"Deleting "<<current->name<<endl;
	delete current;
	current=current->next;


	}
cout<<"DELETING DONE YEAH"<<endl;

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



