#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

struct studentInFo
{
	map< string, vector<int> > studentGrades;
	map< string, double > studentAverage;
	vector<double> average;
	int numStudentPass = 0;
	int numStudentFail = 0;
	double highestAvrge = 0;
	double lowestAvrge = 0;
	double classAvrge = 0;
};

void addStudent(studentInFo& student)
{
	cout << "----------------------------------------------------------------------------";
	cout << "\n\t\t\t ** Add Student **";

	string name;
	cout << "\n Entre your name: ";
	cin >> name;

	vector <int> grades;
	cout << "\n Enter 5 grades(1-100): \n";
	for (int i = 1; i <= 5; i++)
	{
		int grade;
		do {
			cout << "\tGrade " << i << " : ";
			cin >> grade;
			grades.push_back(grade);
		} while (grade < 0 || grade > 100);
	}

	student.studentGrades[name] = grades;
	cout << "\n----------------------------------------------------------------------------\n";
}

void calcAverage(studentInFo& student)
{
	student.average.clear();
	student.studentAverage.clear();
	for (auto& stud : student.studentGrades)
	{
		double sum = 0;
		for (int grade : stud.second)
		{
			sum += grade;
		}
		double avg = sum / stud.second.size();
		student.studentAverage[stud.first] = avg;
		student.average.push_back(avg);
	}
}

void minMaxAverage(studentInFo& student)
{
	student.highestAvrge = *max_element(student.average.begin(), student.average.end());
	student.lowestAvrge = *min_element(student.average.begin(), student.average.end());
	auto it = student.average.begin();
	double sum = 0;
	for (auto grade : student.average) {
		sum += grade;
	}
	student.classAvrge = sum / student.average.size();
}

void calcStatues(studentInFo& student)
{
	student.numStudentPass = 0;
	student.numStudentFail = 0;
	auto it = student.studentAverage.begin();
	for (;it != student.studentAverage.end();it++)
	{
		if (student.studentAverage[it->first] < 50)
			student.numStudentFail++;
		else
			student.numStudentPass++;
	}
}

void printData(studentInFo& student, map<string, vector<int>>::iterator it)
{
	cout << endl << " Name : " << it->first << endl;
	cout << " Grades : ";
	for (auto grade : it->second)
	{
		cout << grade << " ";
	}
	cout << endl;

	cout << " Average : " << student.studentAverage[it->first] << endl;

	if (student.studentAverage[it->first] >= 50)
		cout << " Status : Pass ";
	else
		cout << " Status : Fail ";
}

void SearchStudent(studentInFo& student)
{
	cout << "\n----------------------------------------------------------------------------";
	cout << "\n\t\t\t ** Search Student ** ";
	cout << "\n Enter the name of the student you want to search for :  ";

	string name;
	cin >> name;

	auto it = student.studentGrades.find(name);
	if (it != student.studentGrades.end())
	{
		cout << endl << "Student Found." << endl;
		printData(student, it);
	}
	else
		cout << "\n No student named \" " << name << " \' was found ";
	cout << "\n----------------------------------------------------------------------------\n";

}

void ShowAllStudents(studentInFo& student)
{
	auto it = student.studentGrades.begin();
	cout << "\n----------------------------------------------------------------------------";
	cout << "\n\t\t\t ** Show All Student **" << endl;
	for (int i = 1; i <= student.studentGrades.size(); i++)
	{
		
		cout << "\n\n+----------------------------------------------+\n";
		cout << "\t\tStudent [ " << i << " ] " << endl;
		cout << "\t Name : " << it->first << endl;

		cout << "\t Grades : ";
		for (auto grade : it->second)
		{
			cout << grade << " ";
		}
		cout << endl;
		cout << "\t Average : " << student.studentAverage[it->first] << endl;

		if (student.studentAverage[it->first] >= 50)
			cout << "\t Status : Pass ";
		else
			cout << "\t Status : Fail ";
		cout << "\n+----------------------------------------------+\n\n";
		it++;
	}
	cout << "\n----------------------------------------------------------------------------\n";
}

void ClassStatistics(studentInFo& student)
{
	cout << "\n----------------------------------------------------------------------------";
	cout << "\n\t\t\t**Class Statistics **\n";
	cout << "\t Total Student : " << student.studentGrades.size() << endl;
	cout << "\t Passing : " << student.numStudentPass << endl;
	cout << "\t Failing : " << student.numStudentFail << endl;
	cout << "\t Highest Average : " << student.highestAvrge << endl;
	cout << "\t Lowest Average : " << student.lowestAvrge << endl;
	cout << "\t Class Average : " << student.classAvrge << endl;
	cout << "\n----------------------------------------------------------------------------\n";
}

void Exit()
{
	cout << " GoodBy! See you next time.\n";
}

void chooseOperation(int& n, studentInFo& student)
{
	if (n == 1)
		addStudent(student);
	else if (n == 2) {
		calcAverage(student);
		ShowAllStudents(student);
	}
	else if (n == 3) {
		calcAverage(student);
		SearchStudent(student);
	}
	else if (n == 4) {
		calcAverage(student);
		minMaxAverage(student);
		calcStatues(student);
		ClassStatistics(student);
	}
	else if (n == 5)
		Exit();
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
		chooseOperation(oprNum, student);
	} while (oprNum != 5);

}

int main()
{
	startProject();
	return 0;
}
