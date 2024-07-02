#include<bits/stdc++.h>
using namespace std;

// Ability of objects to take different forms depending on context

// Compile time polymorphism ( static ) :

// Constructor overloading ( Having more than 1 constructor ) 
// Function loading -> 2 functions with same parameters
// Operator overloading 

// Run time polymorphism (Dynamic) :

// Function overriding -> Parent and child both have same function, parent is overridden
// Virtual Functions -> member functions expected to be redefined in derived classes

class C
{
    public : 

    // complex nos a + bj

    int x;
    int y;

    C(int x, int y)
    {
        this -> x = x;
        this -> y = y;
    }

    C()
    {

    }
        
    void show (int x)
    {
        cout << x << endl;
    }

    void show (char c)
    {
        cout << c << endl;
    }

    // overloading the + operator

    C  operator+ (const C& other) 
    {
        C result;
        result.x = this->x + other.x;
        result.y = this->y + other.y;
        return result;
    }

    C print()
    {
        cout << x << " " << y << endl;
    }

};

class Parent
{
    public :
    void getInfo()
    {
        cout << "parent" << endl;
    }

    virtual void hello()
    {
        cout << "Hello from base" << endl; // expected that the child class will re implement
    }
};

class Child : public Parent
{
    public :
    void getInfo()
    {
        cout << "child" << endl;
    }

    void hello()
    {
        cout << "Hello from child" << endl;
    }
};

int main()
{
    C p;
    p.show(1);
    p.show('c');

    C c1(1,2);
    C c2(2,3);

    C c3 = c1 + c2;

    // c1 invokes the + operation it is this
    // c2 is passed as a parameter so it is other

    c3.print();

    Child ch1;
    Parent p1;
    p1.getInfo();

    // Virtual functions
    // dynamic in nature (runtime polymorphism declared in base, overriden in child)

    ch1.getInfo(); // Child has overriden the base class' function
    ch1.hello();

    return 0;
}