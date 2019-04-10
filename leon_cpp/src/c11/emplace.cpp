#include <iostream>
#include <vector>

using namespace std;
class TestClass
{
public:
    TestClass(int va, int vb):a(va),b(vb) { cout<<"construct"<<endl;}
    TestClass(const TestClass& rhs): a(rhs.a),b(rhs.b) { cout<<"copy construct"<<endl; }
    TestClass(TestClass&& rhs) { cout<<"move construct"<<endl; }
    int a;
    int b;
};

int main()
{
    vector<TestClass> TestList;
    TestList.reserve(2);
    cout<<"push back ops >>>>>>>>>>>>>>>>>"<<endl;
    TestList.push_back(TestClass(1,0));
    cout<<"emplace back ops >>>>>>>>>>>>>>>>>>"<<endl;
    TestList.emplace_back(1,0);

    cout<<"without the reserve"<<endl;
    vector<TestClass> TestList2;
    cout<<"push back ops >>>>>>>>>>>>>>>>>"<<endl;
    TestList2.push_back(TestClass(1,0));
    cout<<"emplace back ops >>>>>>>>>>>>>>>>>>"<<endl;
    TestList2.emplace_back(1,0);
}

