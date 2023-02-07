#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "book.h"
#include "Student.h"
#include "stack.h"
#include "find.h"

void Book::Create(Student& student){
    //string content = to_string(student.id) + '\t' + student.name + '\n';
    string filename = "D:\\рабочий стол\\ЯТП\\2 семестр\\студент класс\\студент класс\\books\\";
    filename += to_string(student.id);

        string name = "";
        int j = 0;
        while (j<size(student.name)) {
           if(student.name[j]!=' ')
               filename += student.name[j];
            j++;
        }
        filename += ".txt";
    
    //cout << filename << endl;
    ofstream file;
    file.open(filename);
   // file << content;
    file.close();
}

bool Comparison_ID_Book(string ID, string str)//сравнение ID
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

bool Book::CheckID()
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
            int ID = 0;
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

void Book::GeneratorID() {
    do {
        id = rand();
        // cout << id<<endl;
    } while (id < 1000 || id>9999 || CheckID() == 1);
    cout << id;
}

string Book::ToString() {
    return to_string(id) + ' ' + subject + ' ' + to_string(grade) + ' ' + date;
}


void Book::add_str(string filename) //добавление студента в конец общей базы
{
    string str = to_string(id) + ' ' + subject + ' ' + to_string(grade) + ' ' + date;
    //cout << str <<endl;
    ofstream F(filename, ios::app);

    if (F.is_open())
    {
        if (size(str) > 1)
            F << endl << str;
    }
    F.close();
    //Student::print_All();
}

void Book::delete_str(string filename) //удаление строки по айдишнику
{
    int flag = 0;
    ifstream input(filename);

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

                if (Comparison_ID_Book(to_string(id), str) != 0 && size(str) > 1)
                {
                    out << str << endl;
                    flag++;
                }
            }
        }
        out.close();
        input.close();

        input.open("output.txt");
        out.open(filename);
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