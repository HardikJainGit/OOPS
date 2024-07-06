#include<bits/stdc++.h>
using namespace std;

class Complex
{
    private : int a,b; 

    public :

    Complex()
    {

    }

    Complex(int x, int y)
    {
        a = x;
        b = y;
    }

    friend Complex sumComplex(Complex o1, Complex o2); // needed if a and b are private otherwise no
    // can be written in public or private

    void Print()
    {
        cout << a << " + " << b << "i" << endl;
    }
};

Complex sumComplex(Complex o1, Complex o2)
{
    Complex o3;
    o3.a = o1.a + o2.a;
    o3.b = o1.b+o2.b;
    return o3;
}

class Y; // Forward declaration, assurance to class X assuring that class Y exists afterwards

class X
{
    int data;
    public:
        void setValue(int value)
        {
            data = value;
        }
    friend void add(X, Y);    
};

class Y
{
    int num;
    public:
        void setValue(int value)
        {
            num = value;
        }
    friend void add(X, Y);    

};

void add(X o1, Y o2)
{
    cout << o1.data + o2.num << endl;
}

int main()
{
    Complex c1(1,2);
    Complex c2(2,3);
    
    c1.Print();
    c2.Print();

    Complex c3;
    c3 = sumComplex(c1,c2);
    c3.Print();

    // all this works if a and b are public but if they are private, we need friend functions

    X a1;
    a1.setValue(3);

    Y b1;
    b1.setValue(15);

    add(a1, b1);

    return 0;
}