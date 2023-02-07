#pragma once
#include "stack.h"
#include "find.h"
#include "student.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Book {
public:
	int id;
	string subject;
	int grade;
	string date;

	Book() {
		subject = "";
		grade = 0;
		date = "";
	}
	bool CheckID();
	void Create(Student& student);
	void GeneratorID();
	
	string ToString();

	void add_str(string filename);
	void delete_str(string filename);
};
