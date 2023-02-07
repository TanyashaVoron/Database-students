#include "stack.h"
#include "find.h"
#include "student.h"
#include "book.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

bool proverka_grup(string g) {
    bool flag = 0;
    if (size(g) != 8) flag = 1;
    for( int i = 0; i < size(g); i++) {
        if(char(g[i])<48 || char(g[i]>58))
            flag=1;
    }
    if (flag == 1) return 0;
    else return 1;
}

string konvertSinFilename(string s) {
    string filename= "D:\\рабочий стол\\ЯТП\\2 семестр\\студент класс\\студент класс\\books\\";
    int i = 0;
    int j = 0;
    while (i < 3) {
        if (s[j] != ' ')
            filename += s[j];

        else i++;
        j++;
        //cout << filename << endl;
    }
    filename += ".txt";
    return filename;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    //find
    Stack* Stack1 = Create_Stack();
    Stack* Stack2 = Create_Stack();
    int i_stack1 = 0;
    int i_stack2 = 0;

    Stack* Stack1b = Create_Stack();
    Stack* Stack2b = Create_Stack();
    int i_stack1b = 0;
    int i_stack2b = 0;

    //add
    Stack* Stack3 = Create_Stack();
    Stack* Stack4 = Create_Stack();
    int i_stack3 = 0;
    int i_stack4 = 0;

    Stack* Stack3b = Create_Stack();
    Stack* Stack4b = Create_Stack();
    int i_stack3b = 0;
    int i_stack4b = 0;

    //del
    Stack* Stack5 = Create_Stack();
    Stack* Stack6 = Create_Stack();
    int i_stack5 = 0;
    int i_stack6 = 0;

    Stack* Stack5b = Create_Stack();
    Stack* Stack6b = Create_Stack();
    int i_stack5b = 0;
    int i_stack6b = 0;

    //upd
    Stack* Stack7 = Create_Stack();
    Stack* Stack8 = Create_Stack();
    int i_stack7 = 0;
    int i_stack8 = 0;

    Stack* Stack7b = Create_Stack();
    Stack* Stack8b = Create_Stack();
    int i_stack7b = 0;
    int i_stack8b = 0;

    int f_find = 0;
    int b_find = 0;

    string kom;
    string filename="";

    do {
        cout << endl << "Введите команду: " << endl <<
            " find-поиск" << endl <<
            " add-добавление данных" << endl <<
            " upd-изменение данных" << endl <<
            " del-удaление данных" << endl <<
            " end-завершение программы" << endl;

        if (f_find != 0)
            cout << " clean-очистить список" << endl << endl;
        
       if(f_find!=0 || filename!="")
           cout<<
           "с зачетной книжкой: " << endl<<
            " Bfind-поиск" << endl <<
            " Badd-добавление" << endl<<
            " Bupd-изменение данных" << endl <<
                " Bdel-удaление данных" << endl;

        cin >> kom;

        if (kom == "clean") {
            Clean_Stack(Stack1);
            Clean_Stack(Stack2);
            i_stack1 = 0;
            i_stack2 = 0;
            f_find = 0;

            Clean_Stack(Stack1b);
            Clean_Stack(Stack2b);
            i_stack1b = 0;
            i_stack2b = 0;
            b_find = 0;

            filename = "";
        }

        if (kom == "find" && f_find != 0) { //стек  Ne пустой. поиск по уже существующему стеку
            Student Student1;

            cout << "для дальнейшей работы необходимо найти студента(ов)" << endl << "Поиск: ";
            string a, b;
            cout << "введите условия для поиск (если данное поле необходимо пропустить, введите '-')" << endl <<
                "ФИО (вместо пробела поставьте '_' : ";
            cin >> b;

            for (int i = 0; i < size(b); i++)
            {
                if (b[i] != '_') a += b[i];
                else a += ' ';
            }
            Student1.name = a;
            b = "";
            do {
                cout << "группа: ";
                cin >> b;
            } while (proverka_grup(b) != 0 && b != "-");
            if (b == "-") Student1.group = 0;
            else Student1.group = stoi(b);
            cout << "специальность: ";
            cin >> Student1.specialty;
            
            if (f_find % 2 == 1) {
                //cout << i_stack1 << " " << i_stack2 << endl;
                Stack1 = firndStack(i_stack1, i_stack2, Stack2, Student1.name, b, Student1.specialty);
                //cout << i_stack1 << " " << i_stack2 << endl;
                //cout << i_stack2 << endl;
                //while (i_stack2 > 0) {
                //    //cout << Top(Stack2).kom << endl;
                //    Pop(Stack2);
                //    i_stack2--;
                //}
                //Clean_Stack(Stack2);
               
            }
            else if(f_find%2==0) {
                //i_stack1 = 0;
               // cout << i_stack2<< i_stack1 << endl;
                Stack2 = firndStack(i_stack2, i_stack1, Stack1, Student1.name, b, Student1.specialty);
                // cout << i_stack1 << endl;
                 //while (i_stack1 > 0) {
                 //    //cout << Top(Stack1).kom << endl;
                 //    Pop(Stack1);
                 //    i_stack1--;
                 //}
                 //Clean_Stack(Stack1);
                 
            }
            f_find++;
        }

        if (kom == "find" && f_find == 0) { //стек пустой. поиск с файла
            Stack1 = NewStack(i_stack1);
            //cout << i_stack1;
            Student Student1;

            cout << "для дальнейшей работы необходимо найти студента(ов)" << endl << "Поиск: ";
            string a, b;
            cout << "введите условия для поиск (если данное поле необходимо пропустить, введите '-')" << endl <<
                "ФИО (вместо пробела поставьте '_' : ";
            cin >> b;

            for (int i = 0; i < size(b); i++)
            {
                if (b[i] != '_') a += b[i];
                else a += ' ';
            }
            Student1.name = a;
            b = "";
            do {
                cout << "группа: ";
                cin >> b;
            } while (proverka_grup(b) != 0 && b != "-");
            if (b == "-") Student1.group = 0;
            else Student1.group = stoi(b);
            cout << "специальность: ";
            cin >> Student1.specialty;

            Stack2 = firndStack(i_stack2, i_stack1, Stack1, Student1.name, b, Student1.specialty);
            //cout << i_stack2 << endl;
            //cout << i_stack1 << endl;

            //Clean_Stack(Stack1);
            //Top(Stack1);
            f_find++;

        }

        if (kom == "add") {
            Stack3 = NewStack(i_stack3);
            Student Student1;

            string a, b;
            cout << "введите данные: " << endl <<
                "ФИО (вместо пробела поставьте '_' : ";
            cin >> b;

            for (int i = 0; i < size(b); i++)
            {
                if (b[i] != '_') a += b[i];
                else a += ' ';
            }
            Student1.name = a;
            b = "";
            do {
                cout << "группа: ";
                cin >> b;
            } while (proverka_grup(b) != 0 && b != "-");
            if (b == "-") Student1.group = 0;
            else Student1.group = stoi(b);
            cout << "специальность: ";
            cin >> Student1.specialty;

            cout << "Поиск на совпадение: " << endl;
            Stack4 = firndStack(i_stack4, i_stack3, Stack3, Student1.name, b, Student1.specialty);
            //cout << i_stack1 << endl;
            if (i_stack4 == 0) cout << "Совпадений не найдено" << endl;

            /*while (i_stack3 > 0) {
                cout << Top(Stack1).kom << endl;
                Pop(Stack3);
                i_stack3--;
            }*/

            cout << "Добавить нового студента? " << endl;
            string ans;
            do {
                cout << "введите Yes | No " << endl;
                cin >> ans;
            } while (ans != "Yes" && ans != "No");

            if (ans == "Yes") {
                Student1.GeneratorID();
                Student1.add_str();
                Book book;
                book.Create(Student1);
            }

            Clean_Stack(Stack4);
            //Top(Stack1);
            //f_find++;
        }

        if (kom == "del" && f_find == 0) {
            Stack5 = NewStack(i_stack5);
            Student Student1;

            string a, b;
            cout << "введите данные: " << endl <<
                "ФИО (вместо пробела поставьте '_' : ";
            cin >> b;

            for (int i = 0; i < size(b); i++)
            {
                if (b[i] != '_') a += b[i];
                else a += ' ';
            }
            Student1.name = a;
            b = "";
            do {
                cout << "группа: ";
                cin >> b;
            } while (proverka_grup(b) != 0 && b != "-");
            if (b == "-") Student1.group = 0;
            else Student1.group = stoi(b);
            cout << "специальность: ";
            cin >> Student1.specialty;

            cout << "Поиск на совпадение: " << endl;
            Stack6 = firndStack(i_stack6, i_stack5, Stack5, Student1.name, b, Student1.specialty);
            //cout << i_stack1 << endl;
            if (i_stack6 == 0) cout << "Совпадений не найдено" << endl;

            /*while (i_stack3 > 0) {
                cout << Top(Stack1).kom << endl;
                Pop(Stack3);
                i_stack3--;
            }*/
            else {
                cout << "Вы хотите удалить всех? " << endl;
                string ans;
                do {
                    cout << "введите Yes | No " << endl;
                    cin >> ans;
                } while (ans != "Yes" && ans != "No");

                if (ans == "Yes") {
                    while (i_stack6 > 0) {
                        string str = Top(Stack6).kom;
                        string id = "";
                        int i = 0;
                        while (str[i] != ' ') {
                            id += str[i];
                            i++;
                        }
                        Student a;
                        a.id = stoi(id);
                        a.delete_str();
                        Pop(Stack6);
                        i_stack6--;
                    }
                }
                else {
                    int N;
                    cout << "Введите номер студента для удаления: " << endl;
                    cin >> N;
                    for (int i = 0; i < i_stack6 - N; i++)
                        Pop(Stack6);

                    Node* last = Stack6->top;
                    Stack6->top = last->next;
                    Data ret = last->str;
                    string s = ret.kom;
                    int i = 0;
                    string s1 = "";
                    while (s[i] != ' ') {
                        s1 += s[i];
                        i++;
                    }
                    Student a;
                    a.id = stoi(s1);
                    cout << a.id << endl;
                    a.delete_str();

                }
            }


        }

        else if (kom == "del" && f_find != 0) {
            cout << "Вы хотите удалить всех? " << endl;
            string ans;
            do {
                cout << "введите Yes | No " << endl;
                cin >> ans;
            } while (ans != "Yes" && ans != "No");

            if (ans == "Yes") {
                if (f_find % 2 == 0) {
                    while (i_stack1 > 0) {
                        string str = Top(Stack1).kom;
                        string id = "";
                        int i = 0;
                        while (str[i] != ' ') {
                            id += str[i];
                            i++;
                        }
                        Student a;
                        a.id = stoi(id);
                        a.delete_str();
                        Pop(Stack1);
                        i_stack1--;
                    }
                }
                else {
                    while (i_stack2 > 0) {
                        string str = Top(Stack2).kom;
                        string id = "";
                        int i = 0;
                        while (str[i] != ' ') {
                            id += str[i];
                            i++;
                        }
                        Student a;
                        a.id = stoi(id);
                        a.delete_str();
                        Pop(Stack2);
                        i_stack2--;
                    }
                }
                f_find = 0;
            }
            else {
                int N;
                cout << "Введите номер студента для удаления: " << endl;
                cin >> N;
                if (f_find % 2 == 0) {

                    for (int i = 0; i < i_stack1 - N; i++)
                        Pop(Stack1);

                    Node* last = Stack1->top;
                    Stack1->top = last->next;
                    Data ret = last->str;
                    string s = ret.kom;
                    int i = 0;
                    string s1 = "";
                    while (s[i] != ' ') {
                        s1 += s[i];
                        i++;
                    }
                    Student a;
                    a.id = stoi(s1);
                    cout << a.id << endl;
                    a.delete_str();
                }
                else {
                    for (int i = 0; i < i_stack2 - N; i++)
                        Pop(Stack2);

                    Node* last = Stack2->top;
                    Stack2->top = last->next;
                    Data ret = last->str;
                    string s = ret.kom;
                    int i = 0;
                    string s1 = "";
                    while (s[i] != ' ') {
                        s1 += s[i];
                        i++;
                    }
                    Student a;
                    a.id = stoi(s1);
                    cout << a.id << endl;
                    a.delete_str();
                }
                f_find = 0;
            }

        }

        if (kom == "upd" && f_find == 0) {
            Stack7 = NewStack(i_stack7);
            Student Student1;

            string a, b;
            cout << "введите данные: " << endl <<
                "ФИО (вместо пробела поставьте '_' : ";
            cin >> b;

            for (int i = 0; i < size(b); i++)
            {
                if (b[i] != '_') a += b[i];
                else a += ' ';
            }
            Student1.name = a;
            b = "";
            do {
                cout << "группа: ";
                cin >> b;
            } while (proverka_grup(b) != 0 && b != "-");
            if (b == "-") Student1.group = 0;
            else Student1.group = stoi(b);
            cout << "специальность: ";
            cin >> Student1.specialty;

            cout << "Поиск на совпадение: " << endl;
            Stack8 = firndStack(i_stack8, i_stack7, Stack7, Student1.name, b, Student1.specialty);
            //cout << i_stack1 << endl;
            if (i_stack8 == 0) cout << "Совпадений не найдено" << endl;


            else {
                cout << "Вы хотите изменить всех? " << endl;
                string ans;
                do {
                    cout << "введите Yes | No " << endl;
                    cin >> ans;
                } while (ans != "Yes" && ans != "No");


                string c;
                cout << "введите новые данные: " << endl <<
                    "ФИО (вместо пробела поставьте '_' : ";
                cin >> b;

                for (int i = 0; i < size(b); i++)
                {
                    if (b[i] != '_') a += b[i];
                    else a += ' ';
                }
                if (a[0] != '-') Student1.name = a;
                b = "";
                do {
                    cout << "группа: ";
                    cin >> b;
                } while (proverka_grup(b) != 0 && b != "-");
                if (b[0] != '-') {
                    Student1.group = stoi(b);
                }
                cout << "специальность: ";
                cin >> c;
                if (c[0] != '-') Student1.specialty = c;


                if (ans == "Yes") {
                    while (i_stack8 > 0) {
                        string str = Top(Stack8).kom;

                        string id = "";
                        int i = 0;
                        while (str[i] != ' ') {
                            id += str[i];
                            i++;
                        }
                        i++;

                        string s = "";
                        while (str[i] != ' ') {
                            s += str[i];
                            i++;
                        }
                        i++;
                        s += ' ';
                        while (str[i] != ' ') {
                            s += str[i];
                            i++;
                        }

                        if (a[0] == '-') Student1.name = s;
                        i++;
                        s = "";
                        while (str[i] != ' ') {
                            s += str[i];
                            i++;
                        }
                        if (b[0] == '-') Student1.group = stoi(s);
                        s = "";
                        i++;
                        while (i < size(str)) {
                            s += str[i];
                            i++;
                        }
                        if (c[0] == '-') Student1.specialty = s;

                        Student1.id = stoi(id);
                        Student1.delete_str();
                        Student1.add_str();
                        Pop(Stack8);
                        i_stack8--;
                    }
                }
                else {
                    int N;
                    cout << "Введите номер студента для изменения данных: " << endl;
                    cin >> N;
                    for (int i = 0; i < i_stack8 - N; i++)
                        Pop(Stack8);

                    Node* last = Stack8->top;
                    Stack8->top = last->next;
                    Data ret = last->str;
                    string str = ret.kom;
                    int i = 0;
                    string s1 = "";
                    while (str[i] != ' ') {
                        s1 += str[i];
                        i++;
                    }
                    i++;
                    string s = "";
                    while (str[i] != ' ') {
                        s += str[i];
                        i++;
                    }
                    i++;
                    s += ' ';
                    while (str[i] != ' ') {
                        s += str[i];
                        i++;
                    }

                    if (a[0] == '-') Student1.name = s;
                    i++;
                    s = "";
                    while (str[i] != ' ') {
                        s += str[i];
                        i++;
                    }
                    if (b[0] == '-') Student1.group = stoi(s);
                    s = "";
                    i++;
                    while (i < size(str)) {
                        s += str[i];
                        i++;
                    }
                    if (c[0] == '-') Student1.specialty = s;
                    Student1.id = stoi(s1);
                    Student1.delete_str();
                    Student1.add_str();

                }
            }
            Clean_Stack(Stack8);
        }

        else if (kom == "upd" && f_find != 0) {
            cout << "Вы хотите изменить всех? " << endl;
            string ans;
            do {
                cout << "введите Yes | No " << endl;
                cin >> ans;
            } while (ans != "Yes" && ans != "No");

            Student Student1;
            string c, a, b;
            cout << "введите новые данные: " << endl <<
                "ФИО (вместо пробела поставьте '_' : ";
            cin >> b;

            for (int i = 0; i < size(b); i++)
            {
                if (b[i] != '_') a += b[i];
                else a += ' ';
            }
            Student1.name = a;
            b = "";
            do {
                cout << "группа: ";
                cin >> b;
            } while (proverka_grup(b) != 0 && b != "-");
            if (b[0] != '-')
                Student1.group = stoi(b);

            cout << "специальность: ";
            cin >> c;
            Student1.specialty = c;

            if (ans == "Yes") {
                if (f_find % 2 == 0) {
                    while (i_stack1 > 0) {
                        string str = Top(Stack1).kom;

                        string id = "";
                        int i = 0;
                        while (str[i] != ' ') {
                            id += str[i];
                            i++;
                        }
                        i++;

                        string s = "";
                        while (str[i] != ' ') {
                            s += str[i];
                            i++;
                        }
                        i++;
                        s += ' ';
                        while (str[i] != ' ') {
                            s += str[i];
                            i++;
                        }

                        if (a[0] == '-') Student1.name = s;
                        i++;
                        s = "";
                        while (str[i] != ' ') {
                            s += str[i];
                            i++;
                        }
                        if (b[0] == '-') Student1.group = stoi(s);
                        s = "";
                        i++;
                        while (i < size(str)) {
                            s += str[i];
                            i++;
                        }
                        if (c[0] == '-') Student1.specialty = s;

                        Student1.id = stoi(id);
                        Student1.delete_str();
                        Student1.add_str();
                        Pop(Stack1);
                        i_stack1--;

                    }
                }
                else {
                    while (i_stack2 > 0) {

                        string str = Top(Stack2).kom;

                        string id = "";
                        int i = 0;
                        while (str[i] != ' ') {
                            id += str[i];
                            i++;
                        }
                        i++;

                        string s = "";
                        while (str[i] != ' ') {
                            s += str[i];
                            i++;
                        }
                        i++;
                        s += ' ';
                        while (str[i] != ' ') {
                            s += str[i];
                            i++;
                        }

                        if (a[0] == '-') Student1.name = s;
                        i++;
                        s = "";
                        while (str[i] != ' ') {
                            s += str[i];
                            i++;
                        }
                        if (b[0] == '-') Student1.group = stoi(s);
                        s = "";
                        i++;
                        while (i < size(str)) {
                            s += str[i];
                            i++;
                        }
                        if (c[0] == '-') Student1.specialty = s;

                        Student1.id = stoi(id);
                        Student1.delete_str();
                        Student1.add_str();
                        Pop(Stack2);
                        i_stack2--;

                    }
                }

            }
            else {
                int N;
                cout << "Введите номер студента для изменения данных: " << endl;
                cin >> N;
                if (f_find % 2 == 0) {

                    for (int i = 0; i < i_stack1 - N; i++)
                        Pop(Stack1);

                    Node* last = Stack1->top;
                    Stack1->top = last->next;
                    Data ret = last->str;
                    string str = ret.kom;
                    int i = 0;
                    string s1 = "";
                    while (str[i] != ' ') {
                        s1 += str[i];
                        i++;
                    }
                    i++;
                    string s = "";
                    while (str[i] != ' ') {
                        s += str[i];
                        i++;
                    }
                    i++;
                    s += ' ';
                    while (str[i] != ' ') {
                        s += str[i];
                        i++;
                    }

                    if (a[0] == '-') Student1.name = s;
                    i++;
                    s = "";
                    while (str[i] != ' ') {
                        s += str[i];
                        i++;
                    }
                    if (b[0] == '-') Student1.group = stoi(s);
                    s = "";
                    i++;
                    while (i < size(str)) {
                        s += str[i];
                        i++;
                    }
                    if (c[0] == '-') Student1.specialty = s;
                    Student1.id = stoi(s1);
                    Student1.delete_str();
                    Student1.add_str();
                }
                else {
                    for (int i = 0; i < i_stack2 - N; i++)
                        Pop(Stack2);

                    Node* last = Stack2->top;
                    Stack2->top = last->next;
                    Data ret = last->str;
                    string str = ret.kom;
                    int i = 0;
                    string s1 = "";
                    while (str[i] != ' ') {
                        s1 += str[i];
                        i++;
                    }
                    i++;
                    string s = "";
                    while (str[i] != ' ') {
                        s += str[i];
                        i++;
                    }
                    i++;
                    s += ' ';
                    while (str[i] != ' ') {
                        s += str[i];
                        i++;
                    }

                    if (a[0] == '-') Student1.name = s;
                    i++;
                    s = "";
                    while (str[i] != ' ') {
                        s += str[i];
                        i++;
                    }
                    if (b[0] == '-') Student1.group = stoi(s);
                    s = "";
                    i++;
                    while (i < size(str)) {
                        s += str[i];
                        i++;
                    }
                    if (c[0] == '-') Student1.specialty = s;
                    Student1.id = stoi(s1);
                    Student1.delete_str();
                    Student1.add_str();
                }

            }

            f_find = 0;
        }


        if (kom[0] != 'B') filename = "";

        if (kom[0] == 'B' && filename=="") {
            int N;
            cout << "Введите номер студента для работы с его зачетной книжкой: " << endl;
            cin >> N;
            //cout << f_find << endl;
            if (f_find % 2 == 0) {

                for (int i = 0; i < i_stack1 - N; i++)
                    Pop(Stack1);

                Node* last = Stack1->top;
                Stack1->top = last->next;
                Data ret = last->str;
                string s = ret.kom;
                filename = konvertSinFilename(s);
                //cout << filename;

            }
            else {
                for (int i = 0; i < i_stack2 - N; i++)
                    Pop(Stack2);

                Node* last = Stack2->top;
                Stack2->top = last->next;
                Data ret = last->str;
                string s = ret.kom;
               // cout << s << endl;
                filename = konvertSinFilename(s);
                cout << filename;
            }
            f_find = 0;
        }

        if (kom == "Bfind" && b_find != 0) {
            //стек  Ne пустой. поиск по уже существующему стеку
            Book Book1;

            cout << "для дальнейшей работы необходимо найти строку в зачетке" << endl << "Поиск: ";
            string a, b;
            cout << "введите условия для поиск (если данное поле необходимо пропустить, введите '-')" << endl <<
                "предмет : ";

            cin >> Book1.subject;
            b = "";
            do {
                cout << "оценка от 1 до 5: ";
                cin >> b;
            } while (b != "1" && b != "2" && b != "3" && b != "4" && b != "5" && b != "-");
            if (b == "-") Book1.grade = 0;
            else Book1.grade = stoi(b);

            do {
                cout << "дата сдачи (например 21.01.21): ";
                cin >> a;
            } while ((size(a) != 8 || a[2] != '.' || a[5] != '.') && a != "-");
            Book1.date = a;

            if (b_find % 2 == 1) {
                Stack1b = firndStack(i_stack1b, i_stack2b, Stack2b, Book1.subject, b, Book1.date);
                //cout << i_stack2 << endl;
                //while (i_stack2 > 0) {
                //    //cout << Top(Stack2).kom << endl;
                //    Pop(Stack2);
                //    i_stack2--;
                //}
                //Clean_Stack(Stack2);
            }
            else {
                i_stack1b = 0;
                Stack2b = firndStack(i_stack2b, i_stack1b, Stack1b, Book1.subject, b, Book1.date);
                // cout << i_stack1 << endl;
                 //while (i_stack1 > 0) {
                 //    //cout << Top(Stack1).kom << endl;
                 //    Pop(Stack1);
                 //    i_stack1--;
                 //}
                 //Clean_Stack(Stack1);
            }
            b_find++;
        }

        if (kom == "Bfind" && b_find == 0) {
            //стек пустой. поиск с файла
            Stack1b = NewStackBook(i_stack1b, filename);
            //cout << i_stack1;
            Book Book1;

            cout << "для дальнейшей работы необходимо найти строку в зачетке" << endl << "Поиск: ";
            string a, b;
            cout << "введите условия для поиск (если данное поле необходимо пропустить, введите '-')" << endl <<
                "предмет : ";

            cin >> Book1.subject;
            b = "";
            do {
                cout << "оценка от 1 до 5: ";
                cin >> b;
            } while (b != "1" && b != "2" && b != "3" && b != "4" && b != "5" && b != "-");
            if (b == "-") Book1.grade = 0;
            else Book1.grade = stoi(b);

            do {
                cout << "дата сдачи (например 21.01.21): ";
                cin >> a;
            } while ((size(a) != 8 || a[2] != '.' || a[5] != '.') && a != "-");
            Book1.date = a;

            Stack2b = firndStack(i_stack2b, i_stack1b, Stack1b, Book1.subject, b, Book1.date);
        }

        if (kom == "Badd") {
            Stack3b = NewStackBook(i_stack3b, filename);
            Book Book1;

            string a, b;
            cout << "Введите данные:" << endl << "предмет:" << endl;
            cin >> Book1.subject;
            b = "";
            do {
                cout << "оценка от 1 до 5: ";
                cin >> b;
            } while (b != "1" && b != "2" && b != "3" && b != "4" && b != "5" && b != "-");
            if (b == "-") Book1.grade = 0;
            else Book1.grade = stoi(b);

            do {
                cout << "дата сдачи (например 21.01.21): ";
                cin >> a;
            } while ((size(a) != 8 || a[2] != '.' || a[5] != '.') && a != "-");
            Book1.date = a;

            cout << "Поиск на совпадение: " << endl;
            Stack4b = firndStack(i_stack4b, i_stack3b, Stack3b, Book1.subject, b, Book1.date);
            //cout << i_stack1 << endl;
            if (i_stack4b == 0) cout << "Совпадений не найдено" << endl;

            /*while (i_stack3 > 0) {
                cout << Top(Stack1).kom << endl;
                Pop(Stack3);
                i_stack3--;
            }*/

            cout << "Добавить данные? " << endl;
            string ans;
            do {
                cout << "введите Yes | No " << endl;
                cin >> ans;
            } while (ans != "Yes" && ans != "No");

            if (ans == "Yes") {
                Book1.GeneratorID();
                Book1.add_str(filename);

            }

            //Clean_Stack(Stack1);
            //Top(Stack1);
            //f_find++;
        }

        if (kom == "Bdel" && b_find == 0) {
            Stack5b = NewStackBook(i_stack5b, filename);
            Book Book1;

            string a, b;
            cout << "введите условия для поиск (если данное поле необходимо пропустить, введите '-')" << endl <<
                "предмет : ";
            cin >> Book1.subject;
            b = "";
            do {
                cout << "оценка от 1 до 5: ";
                cin >> b;
            } while (b != "1" && b != "2" && b != "3" && b != "4" && b != "5" && b != "-");
            if (b == "-") Book1.grade = 0;
            else Book1.grade = stoi(b);

            do {
                cout << "дата сдачи (например 21.01.21): ";
                cin >> a;
            } while ((size(a) != 8 || a[2] != '.' || a[5] != '.') && a != "-");
            Book1.date = a;

            cout << "Поиск на совпадение: " << endl;
            Stack6b = firndStack(i_stack6b, i_stack5b, Stack5b, Book1.subject, b, Book1.date);
            //cout << i_stack1 << endl;
            if (i_stack6b == 0) cout << "Совпадений не найдено" << endl;

            /*while (i_stack3 > 0) {
                cout << Top(Stack1).kom << endl;
                Pop(Stack3);
                i_stack3--;
            }*/
            else {
                cout << "Вы хотите удалить всех? " << endl;
                string ans;
                do {
                    cout << "введите Yes | No " << endl;
                    cin >> ans;
                } while (ans != "Yes" && ans != "No");

                if (ans == "Yes") {
                    while (i_stack6b > 0) {
                        string str = Top(Stack6b).kom;
                        string id = "";
                        int i = 0;
                        while (str[i] != ' ') {
                            id += str[i];
                            i++;
                        }
                        Book A;
                        A.id = stoi(id);
                        A.delete_str(filename);
                        Pop(Stack6b);
                        i_stack6b--;
                    }
                }
                else {
                    int N;
                    cout << "Введите номер студента для удаления: " << endl;
                    cin >> N;
                    for (int i = 0; i < i_stack6b - N; i++)
                        Pop(Stack6b);

                    Node* last = Stack6b->top;
                    Stack6b->top = last->next;
                    Data ret = last->str;
                    string s = ret.kom;
                    int i = 0;
                    string s1 = "";
                    while (s[i] != ' ') {
                        s1 += s[i];
                        i++;
                    }
                    Book A;
                    A.id = stoi(s1);
                    cout << A.id << endl;
                    A.delete_str(filename);

                }
            }


        }

        else if (kom == "Bdel" && b_find != 0) {
            cout << "Вы хотите удалить всех? " << endl;
            string ans;
            do {
                cout << "введите Yes | No " << endl;
                cin >> ans;
            } while (ans != "Yes" && ans != "No");

            if (ans == "Yes") {
                if (b_find % 2 == 0) {
                    while (i_stack1b > 0) {
                        string str = Top(Stack1b).kom;
                        string id = "";
                        int i = 0;
                        while (str[i] != ' ') {
                            id += str[i];
                            i++;
                        }
                        Book a;
                        a.id = stoi(id);
                        a.delete_str(filename);
                        Pop(Stack1b);
                        i_stack1b--;
                    }
                }
                else {
                    while (i_stack2b > 0) {
                        string str = Top(Stack2b).kom;
                        string id = "";
                        int i = 0;
                        while (str[i] != ' ') {
                            id += str[i];
                            i++;
                        }
                        Book a;
                        a.id = stoi(id);
                        a.delete_str(filename);
                        Pop(Stack2b);
                        i_stack2b--;
                    }
                }
                b_find = 0;
            }
            else {
                int N;
                cout << "Введите номер строки для удаления: " << endl;
                cin >> N;
                if (b_find % 2 == 0) {

                    for (int i = 0; i < i_stack1b - N; i++)
                        Pop(Stack1b);

                    Node* last = Stack1b->top;
                    Stack1b->top = last->next;
                    Data ret = last->str;
                    string s = ret.kom;
                    int i = 0;
                    string s1 = "";
                    while (s[i] != ' ') {
                        s1 += s[i];
                        i++;
                    }
                    Book a;
                    a.id = stoi(s1);
                    cout << a.id << endl;
                    a.delete_str(filename);
                }
                else {
                    for (int i = 0; i < i_stack2b - N; i++)
                        Pop(Stack2b);

                    Node* last = Stack2b->top;
                    Stack2b->top = last->next;
                    Data ret = last->str;
                    string s = ret.kom;
                    int i = 0;
                    string s1 = "";
                    while (s[i] != ' ') {
                        s1 += s[i];
                        i++;
                    }
                    Book a;
                    a.id = stoi(s1);
                    cout << a.id << endl;
                    a.delete_str(filename);
                }
                b_find = 0;
            }

        }

        if (kom == "Bupd" && b_find == 0) {
            Stack7b = NewStackBook(i_stack7b, filename);
            Book Book1;

            string a, b;
            cout << "введите условия для поиск (если данное поле необходимо пропустить, введите '-')" << endl <<
                "предмет : ";
            cin >> Book1.subject;
            b = "";
            do {
                cout << "оценка от 1 до 5: ";
                cin >> b;
            } while (b != "1" && b != "2" && b != "3" && b != "4" && b != "5" && b != "-");
            if (b == "-") Book1.grade = 0;
            else Book1.grade = stoi(b);

            do {
                cout << "дата сдачи (например 21.01.21): ";
                cin >> a;
            } while ((size(a) != 8 || a[2] != '.' || a[5] != '.') && a != "-");
            Book1.date = a;

            cout << "Поиск на совпадение: " << endl;
            Stack8b = firndStack(i_stack8b, i_stack7b, Stack7b, Book1.subject, b, Book1.date);
            //cout << i_stack1 << endl;
            if (i_stack8b == 0) cout << "Совпадений не найдено" << endl;


            else {
                cout << "Вы хотите изменить всех? " << endl;
                string ans;
                do {
                    cout << "введите Yes | No " << endl;
                    cin >> ans;
                } while (ans != "Yes" && ans != "No");

                string c;
                cout << "введите новые данные: " << endl <<
                    "предмет : ";
                cin >> a;
                if (a[0] != '-') Book1.subject = a;
                b = "";
                do {
                    cout << "оценка от 1 до 5: ";
                    cin >> b;
                } while (b != "1" && b != "2" && b != "3" && b != "4" && b != "5" && b != "-");

                if (b[0] != '-') {
                    Book1.grade = stoi(b);
                }
                do {
                    cout << "дата сдачи (например 21.01.21): ";
                    cin >> a;
                } while ((size(a) != 8 || a[2] != '.' || a[5] != '.') && a != "-");

                if (c[0] != '-') Book1.date = a;


                if (ans == "Yes") {
                    while (i_stack8b > 0) {
                        string str = Top(Stack8b).kom;

                        string id = "";
                        int i = 0;
                        while (str[i] != ' ') {
                            id += str[i];
                            i++;
                        }
                        i++;

                        string s = "";
                        while (str[i] != ' ') {
                            s += str[i];
                            i++;
                        }

                        if (a[0] == '-') Book1.subject = s;
                        i++;
                        s = "";
                        while (str[i] != ' ') {
                            s += str[i];
                            i++;
                        }
                        if (b[0] == '-') Book1.grade = stoi(s);
                        s = "";
                        i++;
                        while (i < size(str)) {
                            s += str[i];
                            i++;
                        }
                        if (c[0] == '-') Book1.date = s;

                        Book1.id = stoi(id);
                        Book1.delete_str(filename);
                        Book1.add_str(filename);
                        Pop(Stack8b);
                        i_stack8b--;
                    }
                }
                else {
                    int N;
                    cout << "Введите номер строки для изменения данных: " << endl;
                    cin >> N;
                    for (int i = 0; i < i_stack8b - N; i++)
                        Pop(Stack8b);

                    Node* last = Stack8->top;
                    Stack8->top = last->next;
                    Data ret = last->str;
                    string str = ret.kom;
                    int i = 0;
                    string s1 = "";
                    while (str[i] != ' ') {
                        s1 += str[i];
                        i++;
                    }
                    i++;
                    string s = "";
                    while (str[i] != ' ') {
                        s += str[i];
                        i++;
                    }

                    if (a[0] == '-') Book1.subject = s;
                    i++;
                    s = "";
                    while (str[i] != ' ') {
                        s += str[i];
                        i++;
                    }
                    if (b[0] == '-') Book1.grade = stoi(s);
                    s = "";
                    i++;
                    while (i < size(str)) {
                        s += str[i];
                        i++;
                    }
                    if (c[0] == '-') Book1.date = s;
                    Book1.id = stoi(s1);
                    Book1.delete_str(filename);
                    Book1.add_str(filename);

                }
            }
            Clean_Stack(Stack8b);
        }

        else if (kom == "Bupd" && b_find != 0) {
            cout << "Вы хотите изменить всех? " << endl;
            string ans;
            do {
                cout << "введите Yes | No " << endl;
                cin >> ans;
            } while (ans != "Yes" && ans != "No");

            Book Book1;
            string c, a, b;
            cout << "введите новые данные: " << endl <<
                "предмет : ";
            cin >> a;
            if (a[0] != '-') Book1.subject = a;
            b = "";
            do {
                cout << "оценка от 1 до 5: ";
                cin >> b;
            } while (b != "1" && b != "2" && b != "3" && b != "4" && b != "5" && b != "-");

            if (b[0] != '-') {
                Book1.grade = stoi(b);
            }
            do {
                cout << "дата сдачи (например 21.01.21): ";
                cin >> a;
            } while ((size(a) != 8 || a[2] != '.' || a[5] != '.') && a != "-");

            if (c[0] != '-') Book1.date = a;

            if (ans == "Yes") {
                if (b_find % 2 == 0) {
                    while (i_stack1b > 0) {
                        string str = Top(Stack1b).kom;

                        string id = "";
                        int i = 0;
                        while (str[i] != ' ') {
                            id += str[i];
                            i++;
                        }
                        i++;

                        string s = "";
                        while (str[i] != ' ') {
                            s += str[i];
                            i++;
                        }

                        if (a[0] == '-') Book1.subject = s;
                        i++;
                        s = "";
                        while (str[i] != ' ') {
                            s += str[i];
                            i++;
                        }
                        if (b[0] == '-') Book1.grade = stoi(s);
                        s = "";
                        i++;
                        while (i < size(str)) {
                            s += str[i];
                            i++;
                        }
                        if (c[0] == '-') Book1.date = s;

                        Book1.id = stoi(id);
                        Book1.delete_str(filename);
                        Book1.add_str(filename);
                        Pop(Stack1b);
                        i_stack1b--;

                    }
                }
                else {
                    while (i_stack2b > 0) {

                        string str = Top(Stack2b).kom;

                        string id = "";
                        int i = 0;
                        while (str[i] != ' ') {
                            id += str[i];
                            i++;
                        }
                        i++;

                        string s = "";
                        while (str[i] != ' ') {
                            s += str[i];
                            i++;
                        }

                        if (a[0] == '-') Book1.subject = s;
                        i++;
                        s = "";
                        while (str[i] != ' ') {
                            s += str[i];
                            i++;
                        }
                        if (b[0] == '-') Book1.grade = stoi(s);
                        s = "";
                        i++;
                        while (i < size(str)) {
                            s += str[i];
                            i++;
                        }
                        if (c[0] == '-') Book1.date = s;

                        Book1.id = stoi(id);
                        Book1.delete_str(filename);
                        Book1.add_str(filename);
                        Pop(Stack2b);
                        i_stack2b--;

                    }
                }

            }
            else {
                int N;
                cout << "Введите номер студента для изменения данных: " << endl;
                cin >> N;
                if (b_find % 2 == 0) {

                    for (int i = 0; i < i_stack1b - N; i++)
                        Pop(Stack1b);

                    Node* last = Stack1b->top;
                    Stack1b->top = last->next;
                    Data ret = last->str;
                    string str = ret.kom;
                    int i = 0;
                    string s1 = "";
                    while (str[i] != ' ') {
                        s1 += str[i];
                        i++;
                    }
                    i++;
                    string s = "";
                    while (str[i] != ' ') {
                        s += str[i];
                        i++;
                    }

                    if (a[0] == '-') Book1.subject = s;
                    i++;
                    s = "";
                    while (str[i] != ' ') {
                        s += str[i];
                        i++;
                    }
                    if (b[0] == '-') Book1.grade = stoi(s);
                    s = "";
                    i++;
                    while (i < size(str)) {
                        s += str[i];
                        i++;
                    }
                    if (c[0] == '-') Book1.date = s;
                    Book1.id = stoi(s1);
                    Book1.delete_str(filename);
                    Book1.add_str(filename);
                }
                else {
                    for (int i = 0; i < i_stack2b - N; i++)
                        Pop(Stack2b);

                    Node* last = Stack2b->top;
                    Stack2b->top = last->next;
                    Data ret = last->str;
                    string str = ret.kom;
                    int i = 0;
                    string s1 = "";
                    while (str[i] != ' ') {
                        s1 += str[i];
                        i++;
                    }
                    i++;
                    string s = "";
                    while (str[i] != ' ') {
                        s += str[i];
                        i++;
                    }

                    if (a[0] == '-') Book1.subject = s;
                    i++;
                    s = "";
                    while (str[i] != ' ') {
                        s += str[i];
                        i++;
                    }
                    if (b[0] == '-') Book1.grade = stoi(s);
                    s = "";
                    i++;
                    while (i < size(str)) {
                        s += str[i];
                        i++;
                    }
                    if (c[0] == '-') Book1.date = s;
                    Book1.id = stoi(s1);
                    Book1.delete_str(filename);
                    Book1.add_str(filename);
                }

            }

            b_find = 0;
        }


    } while (kom != "end");
}