#include <iostream>
#include <algorithm>
#include <ctime>
#include "EngramCandy.h"

int main() {
    srand(time(nullptr));
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Is this thing working?" << std::endl;

    int d = 78;
    int * asd = &d;
    std::cout << "The number is: " << *asd << std::endl;

    for (int i = 0; i < 10; i++) {
        EngramCandy * engramCandy = new EngramCandy();
        std::cout << engramCandy->getRarity() << std::endl;
    }
    //Some startup procedures, initialize GUI (for much later)
    return 0;
}
