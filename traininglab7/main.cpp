/*
 * main.cpp
 *
 *  Created on: May 22, 2015
 *      Author: user
 */
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int NAME_SIZE = 100;
struct StudentRecord{
	char name[NAME_SIZE];
	int sid;
	int score;
};

void insert_record(StudentRecord records[], int &records_size, const char name[], int sid, int score);
void update_record(StudentRecord records[], int &records_size, int sid, int score);
void delete_record(StudentRecord records[], int &records_size, int sid);

const int MAX_SIZE = 100;


/*
* you should clear records and add some records here
* you may call function insert_record inside it
*/
void init(StudentRecord records[], int &records_size) {
	records_size = 0;
	insert_record(records, records_size, "Patrick", 1001, 56);
	insert_record(records, records_size, "Doris", 1002, 87);
	insert_record(records, records_size, "Mary", 1003, 79);
	insert_record(records, records_size, "Terry", 1004, 100);
}

/*
* note that we cannot insert students with the same id
* and we cannot exceed the max size limit
*/
void insert_record(StudentRecord records[], int &records_size, const char name[], int sid, int score) {
	for(int i=0;i<records_size;i++){
		if(records[i].sid==sid){
			return;
		}
	}
	strcpy(records[records_size].name,name);
	records[records_size].sid=sid;
	records[records_size].score=score;
	records_size++;
	return;
}


void update_record(StudentRecord records[], int &records_size, int sid, int score) {
	for(int i=0;i<records_size;i++){
		if(records[i].sid==sid){
			records[i].score=score;
			return;
		}
	}
	cout<<"Student ID not found..";
	return;
}

/*
* find the record and delete it
* move the rest of records forward
*/
void delete_record(StudentRecord records[], int &records_size, int sid) {
	//Write your code here.
	if(records[records_size-1].sid==sid){
		records_size--;
		return;
	}
	for(int i=0;i<records_size;i++){
		while(records[i].sid==sid){
			records[i]=records[i+1];
		}
	}
	records_size--;
	return;
}

void find_highest_score(const StudentRecord records[], int records_size) {
	//Write your code here.
	int highestscore=0;
	for(int i = 0;i<records_size;i++){
		if(records[i].score>highestscore){
			highestscore=records[i].score;
		}
	}
	cout<<"The highest score is "<<highestscore<<endl;
}

void find_lowest_score(const StudentRecord records[], int records_size) {
	//Write your code here.
	int lowestscore=100;
	for(int i =0;i<records_size;i++){
		if(records[i].score<lowestscore){
			lowestscore=records[i].score;
		}
	}
	cout<<"The lowest score is "<<lowestscore<<endl;
}

void show_records(const StudentRecord records[], int records_size) {
	for (int i = 0; i<records_size; i++) {
		cout << records[i].name << " " << records[i].sid << " " << records[i].score << endl;
	}
}

void show_mean_sd(const StudentRecord records[], int records_size) {
	//Optional task. Write your code here.

}

int main(){
	StudentRecord records[MAX_SIZE];
	int records_size = 0;
	init(records, records_size);
	int choice;
	while (true) {
		cout << endl;
		cout << "Welcome to the student record system!\n";
		cout << "1. Insert a student record\n";
		cout << "2. Update a student record\n";
		cout << "3. Delete a student record\n";
		cout << "4. Find the highest score\n";
		cout << "5. Find the lowest score\n";
		cout << "6. Show records\n";
		cout << "7. Show mean and SD (optional)\n";
		cout << "8. Exit\n";
		cout << "Please input your choice:" << endl;

		cin >> choice;
		char name[100];
		int sid;
		int score;
		switch (choice) {
		case 1:
			cout << "Please input student name, id, and score:" << endl;
			cin >> name >> sid >> score;
			insert_record(records, records_size, name, sid, score);
			break;
		case 2:
			cout << "Please input student id and update score:" << endl;
			cin >> sid >> score;
			update_record(records, records_size, sid, score);
			break;
		case 3:
			cout << "Please input student id:" << endl;
			cin >> sid;
			delete_record(records, records_size, sid);
			break;
		case 4:
			find_highest_score(records, records_size);
			break;
		case 5:
			find_lowest_score(records, records_size);
			break;
		case 6:
			show_records(records, records_size);
			break;
		case 7:
			show_mean_sd(records, records_size);
			break;
		case 8:
			return 0;
		default:
			cout << "Invalid choice." << endl;
			continue;
		}
	}
}



