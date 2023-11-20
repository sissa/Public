#include <iostream>
template <size_t N>
struct Fibonacci {
    static const size_t value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

// Base cases
template <>
struct Fibonacci<0> {
    static const size_t value = 0;
};

template <>
struct Fibonacci<1> {
    static const size_t value = 1;
};

int main() {
   // const int fib5 = Fibonacci<5>::value;  // 5
    const size_t fib10 = Fibonacci<2500>::value; // 55
   // std::cout << "Fib(5) = " << fib5 << std::endl;
    std::cout << "Fib(2500) = " << fib10 << std::endl;
}

