#include <iostream>
#include <vector>
#include <chrono>

constexpr size_t LARGE_SIZE = 10000000;  // 10 million

struct PointWithConstexpr {
    int x, y;
    constexpr PointWithConstexpr(int x, int y) : x(x), y(y) {}
};

struct PointWithoutConstexpr {
    int x, y;
    PointWithoutConstexpr(int x, int y) : x(x), y(y) {}
};

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();
    std::vector<PointWithConstexpr> vectorWithConstexpr;
        vectorWithConstexpr.resize(LARGE_SIZE,{1,2});
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration_with_constexpr = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Time taken with constexpr: " << duration_with_constexpr << "ms" << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    std::vector<PointWithoutConstexpr> vectorWithoutConstexpr;
    vectorWithoutConstexpr.resize(LARGE_SIZE,{1,2});
    end_time = std::chrono::high_resolution_clock::now();
    auto duration_without_constexpr = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Time taken without constexpr: " << duration_without_constexpr << "ms" << std::endl;

    return 0;
}

