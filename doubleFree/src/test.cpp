#include "test.hpp"
#include <stdio.h>

static void __attribute__((constructor)) leonTest_init() {
    printf("%s, leonTest.so loading ...\n", __func__);
}

static void __attribute__((destructor)) leonTest_fini() {
    printf("%s, leonTest.so unloading ...\n", __func__);
}

void TraceClass::push_back(int value) { printf("TraceClass push_back\n");}

void Test::process(int value)
{
//    abc.push_back(value);
    trace.push_back(value);
}

