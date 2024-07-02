#include<bits/stdc++.h>
using namespace std;

class Person
{
    public : 

    string name;
    int age;
        
    Person(string name, int age) 
    {
        this -> name = name;
        this -> age = age;
    }
};

class Student : public Person 
{
    // first constructor of base class is called then of the derived class
    // opposite for destructor

    public :
    // name age roll no
    int rollno;

    // Constructor needed if base class has parameterized constructor :

    Student(string name, int age, int rollno) : Person(name, age)
    {
        this->rollno = rollno;
    }

    void getInfo()
    {
        cout << name << " " << age << " " << rollno << " " << endl;
    }
};

class Student_demo_multiple_inheritance
{
    // Student     Person
    //         Clg

    public :

    int rollno;

    Student_demo_multiple_inheritance(int rollno)
    {
        this -> rollno = rollno;
    }
};

class Clg_student : public Person, public Student_demo_multiple_inheritance
{
    public :
    string clg;

    Clg_student(string clg, int age, string name, int rollno) : Person(name, age), Student_demo_multiple_inheritance(rollno)
    {
        this->clg = clg;
    }
    void getInfo()
    {
        cout << name << " " << age << " " << rollno << " " << clg << endl;
    }
};

int main()
{
    Person t1("Yo", 20); 
    Student s("Yo", 20, 120);

    s.getInfo();

    // Protected used for inheritance to child class

    //                                      Derived
    // Base           Private               Protected               Public
    // Private        Not inherited         Not inherited           Not inherited
    // Protected      Private               Protected               Protected
    // Public         Private               Protected               Public

    // Types :
    // Single : One base to one child
    // Multi-level : Parent -> Child -> Child of child
    // Multiple : More than one parent of one child class
    // Hierarchial : Parent -> Child 1 ; Parent -> Child 2
    // Hybrid : Mix of everything

    Clg_student cs("IITG", 20, "Yo", 123);
    cs.getInfo();

    return 0;
}