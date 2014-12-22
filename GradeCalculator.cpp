#include <iostream>
//#include <ofstream> //Class to write on files
//#include <ifstream> //Stream class to read from files
#include <fstream> //Stream class to read and write from files
#include "Subject.h"
#include <string>
#include <cstring>


using namespace std;

void Calculations(Subject p)
{
	string choice;
	while (choice != "e")
	{
		cout << "What would you like to calculate about your class? \n";
		cout << " 1. Your overall grade\n 2. Points need in a category to get a specific grade\n 3. Exit to previous menu.\n";
		cout << "Enter you choice: ";
		cin >> choice; cout << "\n";
		if (choice == "1")
		{
			p.calcGrade();
		}
		if (choice == "2")
		{
			p.Determine_Needed_Category_Points();
		}
		if (choice == "3")
		{
			cout << "Are you sure? (y/n) ";
			cin >> choice; cout << "\n";
			if (choice == "y")
			{
				choice = "e";
			}
		}
	}
}

void Create_New_Subject()
{
	Subject p;
	p.set_Class_Name();
	while (p.is_Complete() == false)
	{
		p.add_Category();
	}
	p.Save_Subject();
	Calculations(p);
}

void Load_Subject()
{
	Subject p;
	p.Load_Subject();
	Calculations(p);
}

int main()
{
	string choice;
	Subject classes[5];
	while (choice != "q")
	{
		cout << "Welcome to the GradeCalculator 2000! \n What would you like to do? \n";
		cout << " 1. Create a new subject\n 2. Load an old subject\n 3. Exit\n Enter you choice: ";
		cin >> choice; cout << "\n";
		if (choice == "1")
		{
			Create_New_Subject();
		}
		if (choice == "2")
		{
			Load_Subject();
		}
		if (choice == "3")
		{
			cout << "Are you sure? (y/n) ";
			cin >> choice; cout << "\n";
			if (choice == "y")
				choice = "q";
		}
	}
	return 0;
}