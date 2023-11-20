#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7};
    
    //Open a binary file for writing
    std::ofstream outFile("vector.bin", std::ios::binary);
    
    // Write the size of the vector to the file
    size_t size = numbers.size();
    outFile.write(reinterpret_cast<char*>(&size), sizeof(size));
    
    // Write the vector data to the file
    outFile.write(reinterpret_cast<char*>(numbers.data()), sizeof(int) * size);
    
    // Close the file
    outFile.close();
  
    // Open a binary file for reading
    std::ifstream inFile("vector.bin", std::ios::binary);
    
    // Check if the file is open
    if (!inFile) {
        std::cerr << "Could not open the file for reading!" << std::endl;
        exit(1);
    }
    
    // Read the size of the vector from the file
    size_t size;
    inFile.read(reinterpret_cast<char*>(&size), sizeof(size));
    
    // Resize the vector to the read size and read the vector data from the file
    std::vector<int> numbers(size);
    inFile.read(reinterpret_cast<char*>(numbers.data()), sizeof(int) * size);
    
    // Close the file
    inFile.close();
    
    // Print the read vector to the console
    std::cout << "Vector read from binary file: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
 
