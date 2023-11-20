#include <iostream>
template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static const int value = 1;
};

int main() {
    const int fact5 = Factorial<5>::value;  // 120
    std::cout << fact5 << std::endl;
}

