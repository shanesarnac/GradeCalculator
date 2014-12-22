#ifndef CATEGORY_CPP
#define CATEGORY_CPP

#include "Category.h"

Category::Category()
{
	class_percentage = 0.0;
	total_available_points = 0.0;
	points_earned = 0.0;
	category_type;
}

Category::~Category()
{
}

void Category::set_Category_Type()
{
	string choice;
	while (choice != "q")
	{
		cout << "Enter the name of a class category (i.e. Homework or Midterm): ";
		cin >> category_type; cout << "\n";
		cout << "You entered " << category_type << ". Is that correct? (y/n) ";
		cin >> choice; cout << "\n";
		if (choice == "y")
			choice = "q";
	}
}

void Category::set_Category_Type(string type)
{
	category_type = type;
}

void Category::set_Category_Percentage()
{
	string choice;
	while (choice != "q")
	{
		cout << "The current percentage of " << category_type << " is " << class_percentage << ".\n";
		cout << "What percent of the grade is " << category_type << " worth (out of 100)? ";
		cin >> class_percentage; cout << "\n";
		cout << "You entered " << class_percentage << ". Is that correct? (y/n) ";
		cin >> choice; cout << "\n";
		if (choice == "y")
		{
			choice = "q";
		}
	}
}

void Category::set_Category_Percentage(double percentage)
{
	class_percentage = percentage;
}

void Category::set_Category_Points()
{
	string choice;
	while (choice != "q")
	{
		cout << "The total points available in " << category_type << " is currently " << total_available_points << ".\n";
		cout << "The total points earned in " << category_type << " is currently " << points_earned << ".\n";
		cout << "How many total points are available in " << category_type << "? ";
		cin >> total_available_points; cout << "\n";
		cout << "Enter the number of points earned so far (if zero enter 0): ";
		cin >> points_earned; cout << "\n";
		if (points_earned > total_available_points)
		{
			cout << "That is not a valid input. The total points earned cannot be larger than the total points available.\n";
		}
		else
		{
			cout << "You entered:\n     Total points available: " << total_available_points << "\n     Total points earned: " << points_earned << "\n";
			cout << "Is that correct? (y/n) ";
			cin >> choice; cout << "\n";
			if (choice == "y")
				choice = "q";
		}
	}
}

void Category::set_Category_Points(double earned_points, double total_points)
{
	points_earned = earned_points;
	total_available_points = total_points;
}

double Category::get_Category_Percentage()
{
	return class_percentage;
}


double Category::get_Category_Points_Earned()
{
	return points_earned;
}


double Category::get_Category_Total_Points()
{
	return total_available_points;
}

string Category::get_Category_Type()
{
	return category_type;
}

#endif

