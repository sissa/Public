#include <iostream>
#include <fstream>
#include <vector>

int main() {
    // Step 1: Create a vector of integers
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Step 2: Open a binary file for writing
    std::ofstream outFile("vector.bin", std::ios::binary | std::ios::out);
    
    // Step 3: Check if the file is open
    if (!outFile) {
        std::cerr << "Could not open the file for writing!" << std::endl;
        return 1;
    }
    
    // Step 4: Write the size of the vector to the file
    size_t size = numbers.size();
    outFile.write(reinterpret_cast<char*>(&size), sizeof(size));
    
    // Step 5: Write the vector data to the file
    outFile.write(reinterpret_cast<char*>(numbers.data()), sizeof(int) * size);
    
    // Step 6: Close the file
    outFile.close();
    
    std::cout << "Vector written to binary file successfully!" << std::endl;
    return 0;
}

