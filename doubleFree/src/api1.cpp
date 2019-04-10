#include "api1.hpp"
#include <stdio.h>

static void __attribute__((constructor)) lib1_init() {
    printf("%s, lib1.so loading ...\n", __func__);
}

static void __attribute__((destructor)) lib1_fini() {
    printf("%s, lib1.so unloading ...\n", __func__);
}

void func_api1(int i) {
    printf("%s: %s\n", __FILE__, __func__);
    A::set(i);
    A::print();
}


