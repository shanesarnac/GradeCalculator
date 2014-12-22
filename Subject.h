#pragma once

#ifndef SUBJECTS_H
#define SUBJECTS_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include "Category.h"


using namespace std;

class Subject
{
public:
	Subject();
	~Subject();
	void Save_Subject();
	void Load_Subject();
	void set_Class_Name();
	void calcGrade();
	void Determine_Needed_Category_Points();
	void add_Category();
	bool is_Complete();
	bool is_Legal_Percent();

private:
	double GradeCalculation();
	void Load(int first_line);
	vector<int> findAvailable();
	void set_Class_Name(string name);
	void add_Category(string information);

	vector<Category> categories;
	string classname;
	int category_count;	
};
#endif
