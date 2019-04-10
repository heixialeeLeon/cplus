#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Base{
public:
    Base() { cout << "Base Constructor" << endl; }
    Base(const Base& base) { cout<< "Base Copy Constructor" << endl;}
    ~Base() { cout << "Base Destructor" << endl; }
};

class Complex {
public:
    Complex() { cout << "Complex Constructor" << endl; }
    Complex(const Complex& other) { cout<< "Complex Copy Constructor" << endl; m_base = other.m_base; }
    ~Complex() { cout << "Complex Destructor" << endl; }
    void Func() { cout<<"Complex Func called"<<endl; }
private:
    Base m_base;
};

void passByValue(Complex com) { com.Func(); }
void passByReference(Complex& com) { com.Func(); }

int main()
{
    Complex com;
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
    passByValue(com);
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
    passByReference(com);
    do
    {
        cout << '\n' << "Press a key to continue...";
    } while (cin.get() != '\n');

}