#include <iostream>
#include "common.hpp"
#include "api1.hpp"
#include "api2.hpp"

int main() {
    printf("%s enter\n\n", __func__);
    func_api1(3);
    func_api2(3);
    printf("%s leave\n\n", __func__);
    //quick_exit(0);  // this will not call the destructor and avoid double free
    return 0;
}

