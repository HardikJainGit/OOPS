#include<bits/stdc++.h>
using namespace std;

void func()
{
    int x = 0;
    static int y = 0;
    cout << x << " " << y << endl;
    x += 1;
    y += 1;
}

class C
{
    public :
    int x;
    
    void incx ()
    {
        x += 1;
    }
};

class Lifetime
{
    public :

    Lifetime()
    {
        cout << "constructor" << endl;
    }
    ~Lifetime()
    {
        cout << "destructor" << endl;
    }
};

class Static
{
    public :
    static int i;
};

int Static::i = 1; // specify for all objects of class Static

int main()
{
    
    // Static variables

    // In function : created and initialised once in lifetime of program
    // In class : created and initialised once, shared by all objects of the class  
    // can not be multiple copies of the same static variables for different objects.
    // Also because of this reason static variables can not be initialized using constructors.  

    func();
    func();
    func(); 

    C ob;
    ob.x = 6;

    ob.incx();

    cout << ob.x << endl;

    // Static objects : Throughout the lifetime of the program

    if(1)
    {
        // Lifetime ob1;
        static Lifetime ob2; // static objects
    }

    Static ob1;
    Static ob2;

    // ob1.i = 1; // error
    // ob2.i = 2;

    cout << ob1.i << " " << " " << ob2.i << endl; 

    cout << "End of program" << endl;

    return 0;
}