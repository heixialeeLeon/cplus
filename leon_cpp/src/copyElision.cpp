#include <iostream>

using namespace std;

class Base{
public:
    Base() { cout << "Base Constructor" << endl; }
    Base(const Base& base) { cout<< "Base Copy Constructor" << endl; }
    //Base(const Base& base) = delete;
    Base(const Base&& base) { cout<< "Base Rvalue Constructor" << endl; }
    Base& operator=(const Base& base) { cout<< "assign operator" << endl; }
    //Base operator=(const Base& base) = delete;
    Base& operator=(const Base&& base) { cout<< "assign Rvalue operator" << endl;}
    //Base operator=(const Base&& base) = delete;
    ~Base() { cout << "Base Destructor" << endl; }
};

Base func()
{
    Base base;
    return base;
}

void base_test()
{
    Base ret;
    ret = func();
}

void base_copy_elision_test()
{
    Base ret = func();
}

void base_copy_elision_reference(Base& base_r)
{
    base_r = func();
}

int main()
{
    base_test();
    cout<<"copy elison >>>>>>>>>>>>"<<endl;
    base_copy_elision_test();
    cout<<"copy elison reference>>>>>>>>>>>>"<<endl;
    Base ret;
    base_copy_elision_reference(ret);
}

