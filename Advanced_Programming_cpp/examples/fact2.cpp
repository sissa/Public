#include <iostream>

template <size_t N>
constexpr size_t factorial() {
    if constexpr (N == 0) {
        return 1;
    } else {
        return N * factorial<N - 1>();
    }
}

int main() {
    std::cout << "Factorial of 5: " << factorial<5>() << std::endl;
    std::cout << "Factorial of 10: " << factorial<10>() << std::endl;
}

