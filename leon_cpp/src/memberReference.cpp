#include <iostream>

using namespace std;
class Base
{
public:
    static Base& ins() { static thread_local Base obj; return obj; }
    void Func() { cout<<"Base Func called"<<endl; }
};

class Child
{
public:
    Child():m_base(Base::ins()) {}
    virtual ~Child() {}
    void Func() { m_base.Func(); }
private:
    Base& m_base;
};

int main()
{
    Child child;
    child.Func();
}

