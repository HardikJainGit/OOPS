#include<bits/stdc++.h>
using namespace std;

class Teacher
{
    // wrapping up of data and member functions in a single unit class : Encapsulation
    // thus helping in data handling by use of private 

    // 3 types of access modifiers : private public protected
    private :
    double salary;
    public : 
        
    Teacher()  // non parameterized
    // Constructor always public
    // same name as class, no return type, only called automatically once on obj creation
    // memory allocation is done when it is called
    {
        cout << "Constructor" << endl;
        clg = "IITG";
    }

    Teacher(string name, string dept, string clg) // Parameterized Constructor
    {
        // this is used to avoid confusion

        this -> name = name;
        this -> dept = dept;
        this -> clg = clg;
    }

    // copy constructor (optional)
    // shallow copy (copies members)
    // issue arises with dynamic memory allocation
    Teacher(Teacher & obj) // by reference
    {
        this -> name = obj.name;
        dept = obj.dept;
        clg = obj.clg;
        cout << "Copy constructor called" << endl;
    }

    Teacher(string n)
    {
        // Here no this keyword needed
        // this -> name = n; // optional
        name = n;
    }

    // for these properties / methods to be accessible to outside the class
    // by default things are private 

    // protected for it to be accessible inside our class and its derived classes

    // properties / attributes
    string name;
    string dept;
    string clg;

    // methods / member functions

    void changeDept(string newDept)
    {
        dept = newDept;
    }

    // setter
    void setSalary(double s)
    {
        salary = s;
    }
    
    // getter
    double getSalary()
    {
        return salary;
    }

    void getInfo()
    {
        cout << name << " " << dept << " " << clg << '\n';
    }
};

class Student
{
    public :
    string name;
    double* cg_ptr;
    double* cg_ptr_deep;

    Student(string n, double cg, double cg_deep)
    {
        name = n;
        cg_ptr = new double(cg); // dynamic memory allocation
        cg_ptr_deep = new double (cg_deep);
    }
    
    Student(Student &obj) // by reference
    {
        this -> name = obj.name;
        cg_ptr = obj.cg_ptr; // shallow
        cg_ptr_deep = new double (*obj.cg_ptr_deep); // deep
        cout << "Copy constructor called" << endl;
    }

    // the default copy constructor creates shallow copy
};

class Staff
{
    public :
    string dept;
    double* salary;

    // Constructor mandatorily needed for dynamic things

    Staff()
    {
        salary = new double();
    }

    // Destructor
    ~Staff()
    {
        cout << "Destructor called" << endl;
        // dynamic memory is not by default freed 
        delete salary;
    }
};

int main()
{
    Teacher t1; // Constructor called
    t1.name = "Yo";
    t1.dept = "Phy";
    t1.changeDept("ECE");
    cout << t1.dept << '\n';
    cout << t1.clg << '\n';

    t1.setSalary(20000);
    int t1_salary = t1.getSalary();
    cout << t1_salary << '\n';

    // Using >1 constructors is constructor overloading (Polymorphism example)

    Teacher t("Yo_");
    cout << t.name << '\n';

    Teacher t2("Yo", "ECE", "IITG");
    t2.getInfo();

    // Copy Constructor

    Teacher t_copy(t2);
    t_copy.getInfo();

    // Issue with shallow copy

    Student s1("yo", 9.02, 8.00);
    cout << *s1.cg_ptr << endl;

    Student s2(s1);
    cout << *s2.cg_ptr << endl;

    // All fine but now edit content
    *s2.cg_ptr = 9.00;
    *s2.cg_ptr_deep = 8.50;

    cout << *s1.cg_ptr << " " << *s2.cg_ptr << endl; // obv s1 is also updated
    cout << *s1.cg_ptr_deep << " " << *s2.cg_ptr_deep << endl; // s1 not updated

    Staff st1;
    *st1.salary = 20000;

    return 0;
}