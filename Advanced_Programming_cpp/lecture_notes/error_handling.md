### Error handling

Let's look at how errors are handled in C:

```C
int main() {
  double d = std::sqrt(4);
  std::cout <<"root of 4: "<< d << " " <<"error code: "<<  errno << std::endl;
  d = std::sqrt(-4);
  std::cout <<"root of -4: "<< d << " " <<"eroor code: "<< errno << std::endl;

  errno = 0;

  d=pow(22,123456);
   
  std::cout<<"now error code is non zero again : "<<errno<<std::endl;
    
  return 0;
}

```

You can check if that varibale `errno` is not zero and act accordingly.



In C++, we have *exceptions*.

Let's learn on examples:

```cpp
#include <iostream>
#include <cmath>
#include <memory>

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
    throw 777;
  }
  catch (int excep){
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
```

The other example files are in `example/errors` folder.

They are better to just be read there than copied here.

#### Exercise0:

Play around with the `try-catch` from the examples and witht the provided macro.


#### Exercise1:
Write a program that tries to resize a vector to a huge size, catches the exception from std::vector and then resizes it to a default number (let's say 10) while also informing the user about that.


#### Exercise2:
Make your "bisection" exercise accept the "range" parameters and throw an exception if the function have the same sign on the borders.











