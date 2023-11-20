#include <iostream>
#include <fstream>

int main() {
    std::ofstream outFile("example.bin", std::ios::binary);
    
    int data{42};
    outFile.write(reinterpret_cast<char*>(&data), sizeof(data));
    
    outFile.close();
    
    std::cout << "Binary file written successfully!" << std::endl;
   
  
    std::ifstream inFile("example.bin", std::ios::binary);
    
    if (!inFile) {
        std::cerr << "Could not open the file!" << std::endl;
        exit(1);
    }
    
    int data_from_file{0};
    inFile.read(reinterpret_cast<char*>(&data_from_file), sizeof(data_from_file));
    
    inFile.close();
    
    std::cout << "Read from binary file: " << data_from_file << std::endl;
    return 0;
}
 
