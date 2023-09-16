#include "back.h"
#include <iostream>

int main() {

    std::initializer_list <int> file = {1,2,3,4,5};

    for (auto num : file)
        std::cout << num << " ";

    return 0;
}
