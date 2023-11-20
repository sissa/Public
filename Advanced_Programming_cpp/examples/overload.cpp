#include <iostream>

// Function to sum two integers, commented out or it won't compile
/*int sum(int a, int b) {
    std::cout << "Integer version called.\n";
    return a + b;
}
*/
// Function to sum two doubles
double sum(double a, double b) {
    std::cout << "Double version called.\n";
    return a + b;
}

//triple sum
int sum(int a, int b, int c) {
    std::cout << "Triple version called.\n";
    return a + b + c;
}

// Function to sum two integers using lvalue references
int sum(const int &a, const int &b) {
    std::cout << "Lvalue reference version called.\n";
    return a + b;
}

// Function to sum two integers using rvalue references
int sum(int &&a, int &&b) {
    std::cout << "Rvalue reference version called.\n";
    return a + b;
}

int main() {
    int a = 5, b = 3;

    // Call sum with int parameters
    std::cout << "Sum of integers: " << sum(a, b) << "\n\n";

    // Call sum with double parameters
    std::cout << "Sum of doubles: " << sum(2.5, 3.5) << "\n\n";

    // Call sum with lvalue reference parameters
    std::cout << "Sum using lvalue references: " << sum(a, b) << "\n\n";

    // Call sum with rvalue reference parameters
    std::cout << "Sum using rvalue references: " << sum(10, 20) << "\n\n";

   // Call triple sum
    std::cout << "Sum of 3 elements: " << sum(10, 20, 10) << "\n\n";

    return 0;
}

