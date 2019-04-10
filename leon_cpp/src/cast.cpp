#include <iostream>
#include <iosfwd>
using namespace std;

class Base{
public:
    int m;
};

class Derived : public Base {
public:
    int n;
};

int main()
{
    Derived d;
    Base* ptr_base = &d;
    Derived* ptr_derived = &d;
    cout<<"ptr_base: "<<ptr_base<<endl;
    cout<<"ptr_derived: "<<ptr_derived<<endl;
}