#include <iostream>
#include <memory>

int main() {
    // Using a lambda expression for a custom deleter
    auto deleter = [](int* p) {
        std::cout << "Destructor called\n";
        delete p;
    };

    // Creating a unique_ptr with a custom deleter
    std::unique_ptr<int, decltype(deleter)> p(new int, deleter);

    return 0;
} 
