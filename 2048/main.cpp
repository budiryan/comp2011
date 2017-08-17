#include <iostream>
using namespace std;
const int MAX_NAME_LEN=32;
class student_record{
private:
	char name[MAX_NAME_LEN];
	unsigned int id;
public:
	student_record(char* nameee,int ID){
		cout<<"im testing the constructor"<<endl;
		strcpy(name,nameee);
		id=ID;

	}
	const char* get_name(void);
	unsigned int get_id(void){
		return id;
	}
	void print(void)const{
		cout<<"Name:\t"<<name<<"\nID:\t"<<id<<endl;}


void set(const char* my_name, unsigned int my_id){
	strcpy(name,my_name);
	id=my_id;
}
void copy(const student_record& sr){
	set(sr.name,sr.id);
}




};
const char* student_record::get_name(void){
	return name;
}
int main(){
student_record adam("asshole",1),brian("haha",4),budi("fuck you",5);

cout<<adam.get_name()<<endl;
cout<<budi.get_id()<<endl;
cout<<budi.get_name()<<endl;
char haha[]="aksdfljaskfl";
char *hehe=haha;
cout<<hehe<<endl;



}


