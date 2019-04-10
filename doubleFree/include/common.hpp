#pragma once

#include <set>
#include <vector>

static std::set<int> aa {1,2,3};
//std::set<int> bb {1,2,3};

class A {
public:
    static void set(int i);
    static void print();
private:
    static std::vector<int> vec_int;
};

void test(int value);