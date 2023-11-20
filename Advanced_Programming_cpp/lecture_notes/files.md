### Introduction to working with files:

First, you need to include the header `<fstream>`

Then, you need to define variables use for accessing the files:
`std::ofstream` for output and `std::ifstream` for input.

```cpp
//this will overwrite the file if it exists or create if it doesn't
std::ofstream filevar("test.txt");
//this will look for "test.txt" and fail if it doesn't exist
//but it won't crash, so better to check manually
std::ifstream filevar2("test.txt");
  if(filevar2){
    ...
  }  
```
You should already be familiar with `std::cout` and `std::cin`. Writing to files is very similar to printing on screen, just use the "file variable" instead of `std::cout`/`cin`.

After using the file, don't forget to `close()` it!


```cpp
    filevar << "1 2 3"<<std::endl;
    filevar.close();
    int a{0},b{0},c{0};
    filevar2 >> a >>b >>c;
    std::cout<<a<< " " <<b <<" "<< c<<std::endl;
    filevar2.close();
    //this will append instead of overwriting
    filevar.open("test.txt", std::ios_base::app);
    filevar << "1 2 3"<<std::endl;
    filevar.close();
```

### Binary files

Text files take too much space and lose precision, they are only used for small calculations and exercises. real world uses binary files to store data. There are various formats that you might even see later in some courses, but let's try the basic, "raw" one.

Let's look and discuss the simple writing of one element:

```cpp
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
 

```

 `reinterpret_cast<char*>` is "casting" the pointer to `data_from_file` to a pointer to char. reinterpret_cast is used for type casting that converts one pointer type to another. Since `inFile.read()` expects the first parameter to be a pointer to char (representing the location where the read bytes will be stored), we need to perform this cast.


And now a vector:

```cpp

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
 

```

### Problems with this:

*These files are not guaranteered to be portable between different systems.*

One of the main reasons for this is the potential for differences in endianness between different systems (while you can expect that 32- and 64- bits systems are different, people forget that this is another problem).

Endianness refers to the order in which the bytes of a multi-byte data type (like an int, float, etc.) are stored in memory. There are two types of endianness:

  - Big-Endian: The most significant byte is stored first (at the lowest address).
  - Little-Endian: The least significant byte is stored first.

In addition to endianness, different systems might have different sizes and representations for fundamental data types (like int, double, etc.), different padding, and alignment requirements, which could also affect the portability of binary files.

There are libraries that solve the issue by introducing some standard binary formats, but it's not our topic.


#### Exercise1:

 - Add "print_to_file" function to your matrix class (the vector version of it).
 - Add "read_from_file" function to it (the file should have dimentions on the first line to avoid a somewhat unreliable function to seek the end of file, but feel free to explore possibilities).

#### Exercise2:

 - Add "print_to_file_binary" function to your matrix class (the vector version of it).
 - Add "read_from_file_binary" function to it. Compare the sizes of the file for `.txt` and `.bin`.

