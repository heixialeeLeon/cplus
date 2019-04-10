#pragma once
#include <vector>
#include <iostream>

//std::vector<int> abc = {1,2,3};

class TraceClass
{
public:
    TraceClass(){ std::cout<<"TraceClass cons" <<std::endl; }
    ~TraceClass(){ std::cout<<"TraceClass dest" <<std::endl;}
    void push_back(int value);
};

TraceClass trace;

class Test
{
public:
    Test(){}
    virtual ~Test() {}
    void process(int value);
};
