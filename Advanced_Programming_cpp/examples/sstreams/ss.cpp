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

