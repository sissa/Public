#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>

int main() {
    std::mt19937 engine(std::random_device{}()); // seeded Mersenne Twister engine
    std::uniform_int_distribution<int> dist(1, 100); // distribution in the range [1, 100]
    
    const size_t array_size = 10;
    int array[array_size];

    auto generate_random_number = [&]() { return dist(engine); };
    std::generate(std::begin(array), std::end(array), generate_random_number);
    
    std::cout << "Random Numbers Array: ";
    std::copy(std::begin(array), std::end(array), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    return 0;
}

