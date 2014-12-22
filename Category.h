#ifndef CATEGORY_H
#define CATEGORY_H

#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

class Category
{
public:
	Category();
	~Category();
	void set_Category_Type();
	void set_Category_Type(string type);
	void set_Category_Percentage();
	void set_Category_Percentage(double percentage);
	void set_Category_Points();
	void set_Category_Points(double points_earned, double total_points);
	double get_Category_Percentage();
	double get_Category_Points_Earned();
	double get_Category_Total_Points();
	string get_Category_Type();
	
private:
	double class_percentage;
	double total_available_points;
	double points_earned;
	string category_type;	
};

#endif