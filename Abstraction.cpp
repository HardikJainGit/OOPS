#include<bits/stdc++.h>
using namespace std;

// Hide unnecessary or sensitive things and show only the important parts
// access modifiers is an example

// Abstract classes
// Cannot be instantiated, meant to be inherited

class Shape
{
    virtual void draw() = 0; // pure virtual function -> now Shape automatically is a virtual class
};

class Circle : public Shape
{
    public :
    void draw()
    {
        cout << "Drawing a circle" << endl;
    }
};

int main()
{
    // Shape s; // Object of abstract class is not allowed
    Circle c1;
    c1.draw();

    return 0;
}