#include <iostream>

namespace hello_world {
    void print() {
        std::cout << "Hello, World!" << std::endl;
    }
}

int main() {
    hello_world::print(); // Call the print function inside the hello_world namespace
    return 0;
}
