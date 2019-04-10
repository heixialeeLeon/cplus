#include <iostream>

class Base
{
public:
    void foo(){ std::cout<<"Base foo"<<std::endl; }
    virtual void fun(){ std::cout<<"Base fun"<<std::endl;}
};

class Derived : public Base
{
    void foo(){ std::cout<<"Derived foo"<<std::endl; }
    virtual void fun(){ std::cout<<"Derived fun"<<std::endl;}
};

int main()
{
    Base base;
    Derived derived;
    Base *p = &base;
    std::cout<<"point to Father"<<std::endl;
    p->foo();
    p->fun();
    std::cout<<"point to Children"<<std::endl;
    p = &derived;
    p->foo();
    p->fun();
    std::cout<<"point to Children with dynmatic_cast"<<std::endl;
    Base* pbase = dynamic_cast<Base*>(p);
    pbase->foo();
    pbase->fun();
}