#include <iostream>

using namespace std;

void PrintT(int& t){  cout<<"left value" <<endl; }

void PrintT(int&& t) { cout<<"right value"<<endl;}

template<typename T>
void TestFoward(T&& v){
    PrintT(v);
    PrintT(std::forward<T>(v));
    PrintT(std::move(v));
}

int main()
{
    cout<<"input rvalue: >>>>>>>>>>>>>>>>>>>>>"<<endl;
    TestFoward(1);
    int x = 1;
    cout<<"input lvalue: >>>>>>>>>>>>>>>>>>>>>"<<endl;
    TestFoward(x);
    cout<<"input forward value: >>>>>>>>>>>>>>>>>>>>>"<<endl;
    TestFoward(std::forward<int>(x));
}
