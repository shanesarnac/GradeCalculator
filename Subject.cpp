#ifndef SUBJECT_CPP
#define SUBJECT_CPP


#include "Subject.h"


using namespace std;

Subject::Subject()
{
	category_count = 0;
}

Subject::~Subject()
{
}

void Subject::Save_Subject()
{
	fstream file;
	file.open("Subjects.txt", fstream:: out |fstream:: app);
	file << classname << "\n";
	for (int i = 0; i < category_count; i++)
	{
		file << categories[i].get_Category_Type() << ":" << categories[i].get_Category_Percentage() << ",";
		file << categories[i].get_Category_Points_Earned() << "," << categories[i].get_Category_Total_Points() << "\n";
	}
	file << "---\n";
	file.close();
}

void Subject::Load_Subject()
{
	fstream file;
	string information;
	string choice;
	int counter = 0;
	file.open("Subjects.txt", fstream::in);
	vector<int> lines = findAvailable();
	cout << "Which subject would you like to load?\n";
	for (unsigned int i = 0; i < lines.size(); i++)
	{
		while (lines[i] != counter)
		{
			getline(file, information);
			counter++;
		}
		cout << i << ". " << information << endl;
	}
	cin >> choice;
	Load(lines[atoi(choice.c_str())]);
	file.close();
}

void Subject::Load(int first_line)
{
	fstream file;
	string information;
	int counter = 0;
	file.open("Subjects.txt", fstream::in);
	while (counter != first_line)
	{
		getline(file, information);
		counter++;
	}
	set_Class_Name(information);
	while (information != "---")
	{
		getline(file, information);
		if (information != "---")
			add_Category(information);
	}
	file.close();
}

vector<int> Subject::findAvailable()
{
	fstream file;
	string information;
	int counter = 0;
	vector<int> lines;
	file.open("Subjects.txt", fstream::in);
	while (getline(file, information))
	{
		size_t found = information.find(',');
		counter++;
		if (found == string::npos && information != "---")
		{
			lines.push_back(counter);
		}
	}
	file.close();
	return lines;
}

void Subject::set_Class_Name()
{
	string choice;
	while (choice != "q")
	{
		cout << "Enter the name of the class: ";
		cin >> classname;
		cout << "The name you entered is " << classname << ". Is that correct? (y/n) ";
		cin >> choice; cout << "\n";
		if (choice == "y")
		{
			choice = "q";
		}
	}
}

void Subject::set_Class_Name(string name)
{
	classname = name;
}

void Subject::add_Category()
{
	Category c;
	c.set_Category_Type();

	categories.push_back(c);
	category_count++;
	
	categories[category_count - 1].set_Category_Percentage();
	while (is_Legal_Percent() == false)
	{
		cout << "You did not enter a legal category percentage. The total for all categories must be 100.\n";
		categories[category_count-1].set_Category_Percentage();
	}
	categories[category_count-1].set_Category_Points();
}

void Subject::add_Category(string information)
{
	Category c;
	string name;
	string percent;
	string earned;
	string total;
	unsigned int i = 0;
	while (information[i] != ':')
	{
		name = name + information[i];
		i++;
	}
	i++;
	c.set_Category_Type(name);
	while (information[i] != ',')
	{
		percent = percent + information[i];
		i++;
	}
	i++;
	c.set_Category_Percentage(atof(percent.c_str()));
	while (information[i] != ',')
	{
		earned = earned + information[i];
		i++;
	}
	i++;
	while ( i < information.length())
	{
		total = total + information[i];
		i++;
	}
	c.set_Category_Points(atof(earned.c_str()), atof(total.c_str()));
	categories.push_back(c);
	category_count++;
}

bool Subject::is_Complete()
{
	double percent = 0;
	for (int i = 0; i < category_count; i++)
	{
		percent += categories[i].get_Category_Percentage();
	}
	return (percent == 100.0);
}

bool Subject::is_Legal_Percent()
{
	double percent = 0;
	for (int i = 0; i < category_count; i++)
	{
		percent += categories[i].get_Category_Percentage();
	}
	return percent < 100.0 || is_Complete();
}

double Subject::GradeCalculation()
{
	double grade = 0.0;
	for (int i = 0; i < category_count; i++)
	{
		grade += ((double)categories[i].get_Category_Points_Earned() / (double)categories[i].get_Category_Total_Points())*(double)categories[i].get_Category_Percentage();
	}
	return grade;
}

void Subject::calcGrade()
{
	cout << "Your Current grade in " << classname << " is " << GradeCalculation() << ".\n \n";
}

void Subject::Determine_Needed_Category_Points()
{
	string choice;
	double wantedgrade;
	double tempholder;
	double counter = 0.0;
	int decision;
	while (choice != "q")
	{
		cout << "What grade would you like to get in the class overall (i.e. 90 or 75) ";
		cin >> wantedgrade; cout << "\n";
		cout << "You entered " << wantedgrade << ". Is that correct? (y/n) ";
		cin >> choice; cout << "\n";
		if (choice == "y")
		{
			while (choice != "e")
			{
				cout << "The categories you entered for " << classname << " are:\n";
				for (int i = 0; i < category_count; i++)
				{
					cout << i << ". " << categories[i].get_Category_Type() << endl;
				}
				cout << "Select which category you would like to know what point totals you need to get a " << wantedgrade;
				cout << " in " << classname << " ";
				cin >> decision; cout << "\n";
				cout << "You entered " << categories[decision].get_Category_Type() << ". Is that correct? (y/n) ";
				cin >> choice; cout << "\n";
				if (choice == "y")
				{
					tempholder = categories[decision].get_Category_Points_Earned();
					while (GradeCalculation() < wantedgrade)
					{
						categories[decision].set_Category_Points(counter++, categories[decision].get_Category_Total_Points());
					}
					if (counter - 1 > categories[decision].get_Category_Total_Points())
					{
						cout << "You cannot recieve your wanted grade from improvements to " << categories[decision].get_Category_Type() << "\n";
					}
					else
					{
						cout << "To get a " << wantedgrade << " in " << classname << ", you need to get " << counter - 1;
						cout << " points out of " << categories[decision].get_Category_Total_Points() << " points. \n";
					}
					cout << "Would you like to exit back to the previous menu? (y,n) ";
					cin >> choice;
					cout << "\n";
					if (choice == "y")
						choice = "e";
					counter = 0.0;
					categories[decision].set_Category_Points(tempholder, categories[decision].get_Category_Total_Points());
				}
			}
			cout << "Would you like to exit to the Calculations menu? (y/n) ";
			cin >> choice;
			if (choice == "y")
			{
				cout << "Are you sure? (y/n) ";
				cin >> choice;
				if (choice == "y")
				{
					choice = "q";
				}
			}
		}
	}
}
#endif

