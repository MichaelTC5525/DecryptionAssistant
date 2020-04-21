#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Is this thing working?" << std::endl;

    int d = 78;
    int * asd = &d;
    std::cout << "The number is: " << *asd << std::endl;
    return 0;
}
