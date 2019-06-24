#include <iostream>

using namespace std;

class BaseVirtual {
public:
    BaseVirtual(){ cout<<"BaseVirtual constructor"<<endl; }
    virtual ~BaseVirtual() { cout<<"BaseVirtual destructor"<<endl; }
};

class ChildVirtual : public BaseVirtual
{
public:
    ChildVirtual():BaseVirtual() { cout <<"ChildVirtual constructor"<<endl; }
    ~ChildVirtual() { cout<<"ChildVirtual destructor"<<endl; }
};

class Base {
public:
    Base(){ cout<<"Base constructor"<<endl; }
    ~Base() { cout<<"Base destructor"<<endl; }
};

class Child : public Base
{
public:
    Child():Base() { cout <<"Child constructor"<<endl; }
    ~Child() { cout<<"Child destructor"<<endl; }
};

int main()
{
    cout<<"sizeof Base is " << sizeof(Base)<<endl;
    cout<<"sizeof BaseVirtual is " << sizeof(BaseVirtual)<<endl;
    Base* ptr_base = static_cast<Base*>(new Child());
    BaseVirtual* ptr_base_virtual = static_cast<BaseVirtual*>(new ChildVirtual());
    Child* ptr_child = new Child();

    cout<<"*********************************************************"<<endl;
    cout <<"The Destructor for the class without Virtual destructor: " <<endl;
    delete ptr_base;
    cout <<"The Destructor for the class with Virtual destructor: " <<endl;
    delete ptr_base_virtual;
    cout<<"The Destructor for the child class without Virtual destructor:"<<endl;
    delete ptr_child;
}