#include "student.h"

#include <iostream>
#include <string>
using namespace std;

bool Comparison_ID(string ID, string str)//сравнение ID
{
    int i_ID = 0;
    int i_str = 0;
    bool flag = 0;

    while (flag == 0 && i_ID < size(ID))
    {
        if (str[i_str] != ID[i_ID])
            flag = 1;

        i_str++;
        i_ID++;
    }
    return flag;
}

bool Student::CheckID()
{
    ifstream f("Students.txt");
    if (f.is_open())
    {
        string str;
        while (!f.eof())
        {
            str = "";
            getline(f, str);
            int i = 0;
            int ID=0;
            while (str[i] != ' ') {
                ID = ID * 10 + int(str[i]) - 48;
                i++;
            }
            if (id == ID) return 1;
        }
        f.close();
    }
    else cout << "File not found" << endl;
    return 0;
}

void Student::GeneratorID() {
    do {
        id = rand();
       // cout << id<<endl;
    } while (id < 1000 || id>9999 || CheckID() == 1);
    //cout << id;
}


string Student::ToString() {
    return to_string(id) + ' ' + name + ' ' + to_string(group) + ' ' + specialty;
}


void Student::add_str() //добавление студента в конец общей базы
{
    string str = to_string(id) + ' ' + name + ' ' + to_string(group) + ' ' + specialty;
    //cout << str <<endl;
    ofstream F("Students.txt", ios::app);

    if (F.is_open())
    {
        if (size(str) > 1)
            F << endl << str;
    }
    F.close();
    //Student::print_All();
}

void Student::delete_str() //удаление строки по айдишнику
{
    int flag = 0;
    ifstream input("Students.txt");

    if (input.is_open())
    {
        ofstream out;          // поток для записи
        out.open("output.txt");

        if (out.is_open())
        {
            string str;
            while (!input.eof())
            {
                str = "";
                getline(input, str);

                if (Comparison_ID(to_string(id), str) != 0 && size(str) > 1)
                {
                    out << str << endl;
                    flag++;
                }
            }
        }
        out.close();
        input.close();

        input.open("output.txt");
        out.open("Students.txt");
        if (out.is_open())
        {
            string str;
            while (!input.eof())
            {
                str = "";
                getline(input, str);
                if (size(str) > 1)
                {
                    if (flag == 1) out << str;
                    else
                        out << str << endl;
                    flag--;
                }
            }
        }
        out.close();
        input.close();
        remove("output.txt");
    }
    else cout << "File not found" << endl;
}
