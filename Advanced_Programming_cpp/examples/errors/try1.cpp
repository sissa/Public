#include <iostream>
#include <cmath>
#include <memory>
#include <string>
//your exception class should inherit from std::exception
//and override the function "what"
class CMyException: public std::exception{
  const char* what() const noexcept override{
    return "My exception happened";
  }
};

int main(){
// throw 999; //if you don't catch it'll call std::terminate   

//just doing a "fake exception" to see the try-catch block
  try{
    throw std::string("try to throw string");
  }
  catch (std::string excep){
    std::cout << "Caught Exception  " << excep << '\n';
  }
 
//now showing the use of our class
//this is more general as we "catch" std::exception
  try{
    throw CMyException();    
        
   }catch (std::exception& e){
    std::cout << e.what() << std::endl;
  }

//and this is to show an actual fail
  try
  {
    double* myarray= new double[10000000000000000];
  }
  catch (std::exception& e)
  {
    std::cout << "Standard exception: " << e.what() << std::endl;
  }
  return 0;
 
}
