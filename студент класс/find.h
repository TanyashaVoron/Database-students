#pragma once
#include "stack.h"
#include "find.h"
#include "student.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

Stack* NewStack(int& i_output);
Stack* firndStack(int& i_output, int& i_input,Stack* StackInput, string name, string group, string specialty);


Stack* NewStackBook(int& i_output, string namefile);
