#ifndef PATIENT_H_
#define PATIENT_H_

const int MAX_NAME_LENGTH = 20;

struct Patient {
	char name[MAX_NAME_LENGTH+1];
	int severity_index;
	Patient* next;
};

Patient* new_patient(const char p_name[MAX_NAME_LENGTH+1], int p_severity_index);

void insert_patient(Patient*& head, Patient* p);

void view_patients(const Patient* const head);

Patient* dispatch_patient(Patient*& head);

void modify_patient_severity_index(Patient*& head, int pos, int severity_index);

void list_patients(const Patient* const head);

void delete_patients(const Patient* const head);


#endif /* PATIENT_H_ */
