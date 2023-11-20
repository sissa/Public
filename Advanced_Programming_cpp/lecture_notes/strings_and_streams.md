### Strings

you can see the full list of functions, for example, [here](https://cplusplus.com/reference/string/string/)

a working example is in the file `examples/cppstrings.cpp` file

General tips: `std::strings` is a powerful class, avoid old-style C-stings which are just `char` arrays


### Streams


![]("iostream_hierarchy.png")


You can "print to strings" and "read from strings" by using sstream:

```cpp
#include <sstream>
#include <iostream>

int main( int argc, char *argv[] ){
  std::istringstream ss(argv[1]);
  int x{0};
   //let's "read" the arguments passed to the program
  //we try to read a number from the first passed argument
  if (!(ss >> x)) {
    std::cerr << "Invalid number: " << argv[1] << std::endl;
  } else if (!ss.eof()) {
    std::cerr << "There are trailing characters after the number: " << argv[1] << std::endl;
    std::cout<<"number was "<<x<<std::endl;
  }
   
  //now let's write something to a string
   //this is quite useful for file_names creation
   std::ostringstream ss2;
   ss2<<"MEOW"<<x;
   std::string result = ss2.str();
   std::cout<<result<<std::endl;
  return 0;
}


```