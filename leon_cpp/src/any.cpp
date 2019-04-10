#include <iostream>
#include <boost/any.hpp>
#include <memory>

class DataType
{
public:
    int xvalue = 100;
    int yvalue = 10;
};

class CallBack
{
public:
    virtual void CallBack_Process(boost::any& data) =0;
};

class Base
{
public:
    virtual void process() = 0;
    void registerCallback(std::shared_ptr<CallBack> ptr) { m_callback = ptr; };
protected:
    std::shared_ptr<CallBack> m_callback;
};

class CallBackImplInt : public CallBack
{
    void CallBack_Process(boost::any& data)
    {
        int* dataPtr = boost::any_cast<int>(&data);
        std::cout<<"CallBackImplInt: "<< *dataPtr<<std::endl;
    }
};

class CallBackImplFloat : public CallBack
{
    void CallBack_Process(boost::any& data)
    {
        float* dataPtr = boost::any_cast<float>(&data);
        std::cout<<"CallBackImplFloat: "<< *dataPtr<<std::endl;
    }
};

class CallBackImplDataType : public CallBack
{
    void CallBack_Process(boost::any& data)
    {
        DataType* dataPtr = boost::any_cast<DataType>(&data);
        std::cout<<"CallBackImplDataType: x "<< dataPtr->xvalue<<" y: "<<dataPtr->yvalue<<std::endl;
        DataType dataReference = boost::any_cast<DataType>(data);
        std::cout<<"CallBackImplDataType: x "<< dataReference.xvalue<<" y: "<<dataReference.yvalue<<std::endl;
    }
};

class Derived1 : public Base
{
public:
    void process() {
        int a =10;
        boost::any data = a;
        if(m_callback)
            m_callback->CallBack_Process(data);
    }
};

class Derived2 : public Base
{
public:
    void process() {
        float a =10.99;
        boost::any data = a;
        if(m_callback)
            m_callback->CallBack_Process(data);
    }
};

class Derived3 : public Base
{
public:
    void process() {
        DataType a;
        boost::any data = a;
        if(m_callback)
            m_callback->CallBack_Process(data);
    }
};

int main()
{
    std::cout<<"start"<<std::endl;
    Derived1 d1;
    Derived2 d2;
    Derived3 d3;
    std::shared_ptr<CallBack> ptrfunc1;
    ptrfunc1.reset(new CallBackImplInt());
    std::shared_ptr<CallBack> ptrfunc2;
    ptrfunc2.reset(new CallBackImplFloat());
    std::shared_ptr<CallBack> ptrfunc3;
    ptrfunc3.reset(new CallBackImplDataType());
    d1.registerCallback(ptrfunc1);
    d1.process();
    d2.registerCallback(ptrfunc2);
    d2.process();
    d3.registerCallback(ptrfunc3);
    d3.process();
}

