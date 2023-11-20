#include <iostream>
#include <chrono>
#include <map>
#include <string>
#include <thread>

class ScopedTimer {
public:
    ScopedTimer(const std::string& name) : name(name), start(std::chrono::steady_clock::now()) {
    }
    
    ~ScopedTimer() {
        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        
        // Update the map with the new duration
        auto it = timeMap.find(name);
        if (it != timeMap.end()) {
            it->second.first += duration;
            it->second.second += 1;
        } else {
            timeMap[name] = {duration, 1};
        }
    }
    
    static void PrintTimes() {
        for (const auto& entry : timeMap) {
            std::cout << "Function " << entry.first << " was called " << entry.second.second
                      << " times and took " << entry.second.first << " microseconds in total.\n";
        }
    }
    
private:
    const std::string name;
    std::chrono::steady_clock::time_point start;
    static std::map<std::string, std::pair<long long, int>> timeMap;
};

std::map<std::string, std::pair<long long, int>> ScopedTimer::timeMap;

int main() {
    {
        ScopedTimer timer("FunctionA");
        // Simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    {
        ScopedTimer timer("FunctionB");
        // Simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
    
    {
        ScopedTimer timer("FunctionA");
        // Simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    
    ScopedTimer::PrintTimes();
    
    return 0;
}

