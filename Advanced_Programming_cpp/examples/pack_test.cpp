#include <iostream>

double sum(size_t count, ...) {
    va_list args;
    va_start(args, count);
    double result = 0.0;

    result = (... + va_arg(args, double)); // fold expression

    va_end(args);
    return result;
}

int main() {
    std::cout << sum(3, 1.0, 2.0, 3.0) << std::endl; // Outputs 6.0
}

