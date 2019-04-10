#include <iostream>
#include "common.hpp"
#include "api1.hpp"
#include "api2.hpp"

int main() {
    printf("%s enter\n\n", __func__);
    func_api1(3);
    func_api2(3);
    printf("%s leave\n\n", __func__);
    return 0;
}

