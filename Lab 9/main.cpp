#include <iostream>
#include "Patient.h"
using namespace std;

int main() {
	Patient* head = NULL;
	Patient* p1 = new_patient("Adam", 1);
	Patient* p2 = new_patient("Betty", 2);
	Patient* p3 = new_patient("Chris", 3);
	Patient* p4 = new_patient("Doris", 4);
	Patient* p5 = new_patient("Eric", 5);
	insert_patient(head, p1);
	insert_patient(head, p2);
	insert_patient(head, p3);
	insert_patient(head, p4);
	insert_patient(head, p5);

	int reply, patient_choice, severity_index;
	char patient_name[MAX_NAME_LENGTH+1];
	Patient* p;

	do {
		view_patients(head);
		cout << endl << "Choose an operation:" << endl;
		cout << "1: Insert a new patient to the queue." << endl;
		cout << "2: Dispatch a patient to the emergency room." << endl;
		cout << "3: Change the severity index of a patient." << endl;
		cout << "4: Quit" << endl;
		cin >> reply;

		switch(reply) {
		case 1:
			cout << "Please enter the name of the patient:" ;
			cin >> patient_name;
			cout << "Please enter the severity index of the patient:";
			cin >> severity_index;
			p = new_patient(patient_name, severity_index);
			insert_patient(head, p);
			break;
		case 2:
			p = dispatch_patient(head);
			if (p != NULL)
			{
				cout << p->name << " is dispatched to the emergency room." << endl;
				delete p;
			}
			else
				cout << "No patients to dispatch!" << endl;
			break;
		case 3:
			if(head != NULL) {
				cout << "Please choose a patient:" << endl;
				list_patients(head);
				cin >> patient_choice;
				cout << "Change his/her severity index to:" ;
				cin >> severity_index;
				modify_patient_severity_index(head, patient_choice, severity_index);
			} else {
				cout << "No patients available!" << endl;
			}
			break;
		case 4:
			delete_patients(head);
			break;
		default:
			break;
		}

	} while (reply != 4);


	return 0;
}
