#include "stack.h"
#include "find.h"
#include "student.h"

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

Stack* NewStack(int& i) {
    Stack* StackOutput = Create_Stack();
    ifstream f("Students.txt");

    if (f.is_open())
    {
        string str;
        while (!f.eof())
        {
            str = "";
            getline(f, str);

            Data a;
            a.kom = str;
            Push(StackOutput, a);
            i++;
        }
        f.close();
    }
    else cout << "File not found" << endl;
    return StackOutput;
}

Stack* firndStack(int& i_output, int& i_input,Stack* StackInput,string name,string group,string specialty) {
   /* string name = Student->name;
    string group = to_string(Student->group);
    string specialty = Student->specialty;*/
    
    Stack* StackOutput = Create_Stack();
    i_output = 1;
    //Node* last = StackInput->top;
    //Node* second = nullptr;
    while (i_input>0) {
        string str = Top(StackInput).kom;
        //cout <<endl<< str;
        Pop(StackInput);
        i_input--;
        //second = last;
        //last = last->next;
       // string str = second->str.kom;
       // delete second;

        int k = 0;
        int konst = 0;
        while (str[k] != ' ') {
            k++;
            konst++;
        }
        //cout <<endl<< "*" << str << endl;
        bool flag = 0;
        int i = 0; //бежим по строке, прочитанной из файла
        int j = 0; //бежим поочереди по всем введенным данным
        //cout << i << endl;
        k = konst + 1;
        int Size = -1;
        //cout << str[i] << "***" << endl;
        while (str[k] != '0' && str[k] != '1' && str[k] != '2' && str[k] != '3' && str[k] != '4' && str[k] != '5' && str[k] != '6' && str[k] != '7' && str[k] != '8' && str[k] != '9') {
            Size++;
            k++;
        }
        //cout << Size << endl;

        if (name[0] == '-') i += Size + 1; //проверка на совпадение имени, если оно указано при поиске
        else {
            while (flag == 0 && i < Size)
            {                                 // cout << flag << " i=" << i << " " <<"size(name)="<< size(name) << endl;
           // cout << str[i + konst + 1] << " " << name[i] << endl;
                if (str[i + konst + 1] != name[i])

                    flag = 1;
                i++;
            }
            i++;
        }
        i += konst + 1;
        //cout << "name: " << flag << " i=" << i << " j=" << j << endl;
        k = i;
        Size = 0;
        while (str[k] != ' ')
        {
            Size++;
            k++;
        }//cout << Size << endl;

        if (group[0] == '-') i += Size + 1; //проверка на совпадение группы, если оно указано при поиске
        else {
            while (flag == 0 && j < Size)
            {                             // cout << "group: " << flag << " j=" << j << " size(group)=" << Size << endl;
                if (str[i] != group[j])
                    flag = 1;
                i++;
                j++;
            }
            i++;
            j = 0;
        }//cout << "group: " << flag << " i=" << i << " j=" << j << endl;

        //cout << flag << endl;
        if (specialty[0] != '-')//проверка на совпадение специальности, если оно указано при поиске
        {
            while (flag == 0 && i < size(str))
            {                                   //cout << "sep: " << flag << " j=" << j << " size(sep)=" << Size<<" i="<<i << " size(str)=" << size(str) << endl;
            //cout << str[i] << specialty[j] << endl;
                if (str[i] != specialty[j])
                    flag = 1;
                i++;
                j++;
            }

            if (i != size(str)) flag = 1;
        }//cout << "sep: " << flag << " i=" << i << " j=" << j << endl;
        //cout << endl;
        if (flag == 0) {
            cout << i_output << " " << str << endl;
            i_output++;
            Data a;
            a.kom = str;
            Push(StackOutput, a);
        }
    }
    i_output--;
    return StackOutput;
}


Stack* NewStackBook(int& i, string namefile) {
    Stack* StackOutput = Create_Stack();
    ifstream f(namefile);

    if (f.is_open())
    {
        string str;
        while (!f.eof())
        {
            str = "";
            getline(f, str);

            Data a;
            a.kom = str;
            Push(StackOutput, a);
            i++;
        }
        f.close();
    }
    else cout << "File not found" << endl;
    return StackOutput;
}
