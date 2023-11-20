#include <iostream>
#include <string>

int main () {

   std::string str1 = "Hello";
   std::string str2 = "World";
   std::string str3;
   int  len ;

   // copy str1 into str3
   str3 = str1;
   std::cout << "str3 : " << str3 << std::endl;

   // concatenates str1 and str2
   str3 = str1 + str2;
   std::cout << "str1 + str2 : " << str3 << std::endl;

   // total length of str3 after concatenation
   len = str3.size();
   std::cout << "str3.size() :  " << len << std::endl;

//more ways to construct   
    std::string str33(10, 'a');                // Initialize with character repeated n times
    std::string str4(str2);                  // Copy constructor
    std::string str5(str3.begin()+2, str3.end()-4); // Range constructor
    std::string str8 = {'H', 'e', 'l', 'l', 'o'}; // Initializer list constructor

    std::cout<<"str3 is "<<str33<<std::endl;
    std::cout<<"str5 is "<<str5<<std::endl;
//testing different functions:
    std::cout<< "str4 size is " <<str4.size()<<std::endl;
    std::cout<<"can also use length for this "<<str4.length()<<std::endl;
    if (!str4.empty()){
      str4.resize(20);
    }
    std::cout<<"str4 now is "<<str4<<std::endl;
    std::cout<<"str4's capacity is "<<str4.capacity()<<std::endl;
   
   return 0;
} 
