#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct studentInFo
{
	vector <string> studentName;
	vector <int> grades;
	map<string, vector<int> > studentData;
	int numStudentPass = 0;
	int numStudentFail = 0;
	int studentCount = 0;
	int gradeCount = 0;

};

void addStudent(studentInFo &student)
{
	cout << "----------------------------------------------------------------------------";
	cout << "\n\t\t\t ** Add Student **";
	string name;
	int grade;
	cout << "\n Entre your name: ";
	cin >> name;
	student.studentName.push_back(name);
	cout << "\n Entre the Number of grads:  ";
	cin >> student.gradeCount;
	cout << "\n Enter your grades(1-100): \n";
	for (int i = 1; i <= student.gradeCount; i++)
	{
		cout << "\tGrade " << i << " : ";
		cin >> grade;
		student.grades.push_back(grade);
	}
	cout << "\n----------------------------------------------------------------------------\n";
}

void SearchStudent(studentInFo &student) {
	cout << "\n----------------------------------------------------------------------------";
	cout << "\n\t\t\t ** Search Student ** ";
	cout << "\n Enter the name of the student you want to search for :  ";
	string name;
	cin >> name;
	auto it = find(student.studentName.begin(), student.studentName.end(), name);
	if (it != student.studentName.end()) {
		cout << "Student Found.";
		//cout << " هنظهر الدتا بتاع الطالب ";
	}
	else
		cout << "\n No student named \" " << name << " \' was found ";
	cout << "\n----------------------------------------------------------------------------\n";

}
void ShowAllStudents(studentInFo &student) {
	cout << "\n----------------------------------------------------------------------------";
	cout << "\n\t\t\t ** Show All Student **";
	cout << "\t Name : " << endl;
	cout << "\t Grades : " << endl;
	cout << "\t Average : " << endl;
	cout << "\t Statues : " << endl;
	cout << "\n----------------------------------------------------------------------------\n";
}
void ClassStatistics(studentInFo &student) {
	cout << "\n----------------------------------------------------------------------------";
	cout << "\n\t\t\t**Class Statistics **\n";
	cout << "\t Total Student :" << endl;
	cout << "\t Passing :" << endl;
	cout << "\t Failing :" << endl;
	cout << "\t Highest Average :" << endl;
	cout << "\t Lowest Average :" << endl;
	cout << "\t Class Average :" << endl;
	cout << "\n----------------------------------------------------------------------------\n";
}

void chooseOperation(int& n, studentInFo &student)
{
	if (n == 1)
		addStudent(student);
	else if (n == 2)
		ShowAllStudents(student);
	else if (n == 3)
		SearchStudent(student);
	else if (n == 4)
		ClassStatistics(student);

}

void showScreen()
{
	cout << "\n \t\t\t ** STUDENT GRADE MANAGEMENT SYSTEM ** " << endl << endl;
		cout << " \n \tChoose the Operation:" << endl
			<< " \t\t1.   Add student : " << endl
			<< " \t\t2.  Show All Students : " << endl
			<< " \t\t3.  Search Student :" << endl
			<< " \t\t4.  Class Statistics :" << endl
			<< " \t\t5.  Exit : " << endl;
}

void startProject()
{
	studentInFo student;
	int oprNum;
	do {
		showScreen();
		cout << " Enter yours choice (1-5): "; 
		cin >> oprNum;
		chooseOperation(oprNum,student);
	} while (oprNum !=5);
	cout << " GoodBy! See you next time.\n";
}

int main()
{
	startProject();
	return 0;
}