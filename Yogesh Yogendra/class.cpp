
#include<bits/stdc++.h>
using namespace std;

class Student
{
private:
    /* data */
public:
    string name;
    int rollno,age;
    void setter(string ,int ,int);
    // {
    //     name = _name;
    //     age = _age;
    //     rollno = _roll;
    // }
    void getter()
    {
        cout<<"Name--> " <<name<<"\n";
        cout<<"Age--> " <<age<<"\n";
        cout<<"Roll Number--> " <<rollno<<"\n";
    }
    // Student(/* args */);
    // ~Student();
};

void Student :: setter(string _name,int _age,int _roll)
{
    name = _name;
    age = _age;
    rollno = _roll;
}

int main()
{
    Student ele;//created in stack
    
    ele.setter("Arkashish",20,189);
    ele.getter();


    // Student *st = new Student();//created in heap
    // st->getter("Naman",20,30);
}