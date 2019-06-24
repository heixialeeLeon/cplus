#include <iostream>

using namespace std;

class Base {
public:
    Base(){ cout<<"BaseVirtual constructor"<<endl; }
    void func_1() { cout <<"Base func_1"<<endl; }
    virtual void func_2() { cout <<"Base func_1"<<endl; }
};

class Child : public Base
{
public:
    Child():Base() { cout <<"ChildVirtual constructor"<<endl; }
    void func_1() { cout <<"Child func_1"<<endl; }
    virtual void func_2() { cout <<"Child func_1"<<endl; }
};

int main()
{
    Base* ptr_base = static_cast<Base*>(new Child());
    ptr_base->func_1();
    ptr_base->func_2();
}