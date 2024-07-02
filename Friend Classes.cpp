#include<bits/stdc++.h>
using namespace std;

class Complex
{
    private : int a,b; 
    friend class Calculator;

    public :

    Complex()
    {

    }

    Complex(int x, int y)
    {
        a = x;
        b = y;
    }

    void Print()
    {
        cout << a << " + " << b << "i" << endl;
    }
};


class Calculator
{
public:
    int sumRealComplex(Complex o1, Complex o2)
    {
        return (o1.a + o2.a);
    }
    int sumImgComplex(Complex o1, Complex o2)
    {
        return (o1.b + o2.b);
    }
};

int main()
{
    Complex c1(1,2);
    Complex c2(2,3);
    Complex c3;

    Calculator calc;

    int res = calc.sumRealComplex(c1,c2);
    int res_i = calc.sumImgComplex(c1,c2);

    cout << res << endl;
    cout << res_i << endl;
    return 0;
}