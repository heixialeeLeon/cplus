#include "common.hpp"
#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> A::vec_int = std::vector<int>();

void A::set(int num) {
    vec_int.clear();
    for (int i = 0; i < num; i++) {
        vec_int.push_back(i);
    }
}

void A::print() {
    for (int i = 0; i < vec_int.size(); i++) {
        printf("vec_int[%d] = %d, addr: %p.\n", i, vec_int[i], &vec_int[i]);
    }
    printf("vec_int addr: %p, size:%u, capacity:%u\n\n", &vec_int, vec_int.size(), vec_int.capacity());
}

void test(int value)
{
    if(aa.find(value) != std::end(aa)){
        printf("find\n");
    }else{
        printf("not find \n");
    }
}