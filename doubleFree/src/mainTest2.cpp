#include <iostream>
#include "test.hpp"

int main() {
    printf("%s enter\n\n", __func__);
    Test t;
    t.process(2);
    printf("%s leave\n\n", __func__);
    return 0;
}


