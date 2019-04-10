#include <iostream>
#include <functional>

//template<typename Function, typename ParamType, typename ReturnType>
//ReturnType Process(Function func, ParamType& param)
//{
//    return func(param);
//};

template<typename paramType, typename outType>
struct Process
{
    typedef void (*process) (const paramType&, outType&);
};

template<typename Functor, typename paramType, typename outType>
void TProcess(Functor process, paramType& param, outType& outParam)
{
    process(param, outParam);
};

void processInt(int& value, int& out) {
    std::cout<<"processInt: "<<value<<std::endl;
    out = ++value;
}

void processFloat(float& value, float& out){
    std::cout<<"processInt: "<<value<<std::endl;
    out = value+2.0;
}

class Base{
    virtual void process() = 0;
};

class Derived1 : public Base {
public:
    void process(){
        int a=10;
        int b;
        TProcess(Derived1::processInt,a,b);
        std::cout<<"b is: "<<b<<std::endl;
    }
private:
    static void processInt(int& value, int& out) {
        std::cout<<"Derived1 processInt: "<<value<<std::endl;
        out = ++value;
    }
};

class Derived2 : public Base {
public:
    void process(){
        float a=100;
        float b;
        TProcess(Derived2::processFloat,a,b);
        std::cout<<"b is: "<<b<<std::endl;
    }
private:
    static void processFloat(float& value, float& out) {
        std::cout<<"Derived1 processFloat: "<<value<<std::endl;
        out = ++value;
    }
};

int main()
{
    std::cout<<"start test now"<<std::endl;
    int a,b;
    a=0;
    TProcess(processInt,a,b);
    std::cout<<"result out is: "<<b<<std::endl;
    std::cout<<"***************************************"<<std::endl;
    Derived1 d1;
    d1.process();
    Derived2 d2;
    d2.process();
}


//template<class ParamType>
//struct IsGood {
//    typedef bool (*Check)(const ParamType&);
//};
//
//template<typename Functor, typename ParamType>
//void DoSmth(Functor isGood, ParamType& param) {
//    if (isGood(param)){
//        std::cout<<"isGood pass" <<std::endl;
//    }else{
//        std::cout<<"isGood not pass "<<std::endl;
//    }
//}
//
//bool checkEqualInt(int& i){
//    std::cout<<"checkEqualInt: " << i <<std::endl;
//    return i==0;
//}
//bool checkEqualFloat(float& i){
//    std::cout<<"checkEqualFloat: " << i <<std::endl;
//    return i==0.0;
//}
//
//int main()
//{
//    std::cout <<"start"<<std::endl;
//    int a=0;
//    DoSmth(checkEqualInt,a);
//    a++;
//    DoSmth(checkEqualInt,a);
//}