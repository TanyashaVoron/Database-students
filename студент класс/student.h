#pragma once

#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class Student
{
private:
	bool CheckID();

public:
	int id;
	string name;
	int group;
	string specialty;

	Student() {
		name = "";
		group = 0;
		specialty = "";
	}

	void GeneratorID();
	//string NameBook();
	string ToString();

	void add_str();
	void delete_str();
};