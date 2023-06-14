#include <iostream> 
#include <fstream> 
#include <string>

using namespace std;

struct student {
	string name, surname, facNum;
	double avgGrade = 0.0;
};

int counter = 1;
student stu;
ifstream inf("students.txt", ios::in);
ofstream outf("students.txt", ios::out);

void getInfo() {
	char exit = ' ';

	do {
		cout << "Input data about a student" << endl;

		do {
			cout << "Name: ";
			cin >> stu.name;
		} while (stu.name.length() < 3 || stu.name.length() > 25);

		do {
			cout << "Surname: ";
			cin >> stu.surname;
		} while (stu.surname.length() < 3 || stu.surname.length() > 25);

		do {
			cout << "Faculty Number: ";
			cin >> stu.facNum;
		} while (stu.facNum.length() != 10);

		do {
			cout << "Avgerage Grade: ";
			cin >> stu.avgGrade;
		} while (stu.avgGrade < 3.00 || stu.avgGrade > 6.00);

		cout << "Press N to stop or Y to continue: ";
		cin >> exit;

		outf.seekp(counter * sizeof(student));
		outf.write((char*)&stu, sizeof(student));
		counter = counter + 5;

		cout << endl;
	} while (exit != 'n' && exit != 'N');
}

void printInfo() {
	int exit = counter;
	counter = 1;

	do {
		inf.seekg(counter * sizeof(student));
		inf.read((char*)&stu, sizeof(student));

		cout << endl << endl;

		cout << "Data about students" << endl;
		cout << stu.name << " " << stu.surname << endl << stu.facNum << endl << stu.avgGrade << endl << endl;

		counter = counter + 5;
	} while (exit != counter);
}

int main() {
	getInfo();
	outf.close();

	printInfo();
	inf.close();

	return 0;
}