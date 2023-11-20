#include <cmath>
#include <iostream>

int main() {
  double d = std::sqrt(4);
  std::cout <<"root of 4: "<< d << " " <<"error code: "<<  errno << std::endl;

  d = std::sqrt(-4);
  std::cout <<"root of -4: "<< d << " " <<"eroor code: "<< errno << std::endl;

  d = 0;

  errno = 0;

  d=pow(22,123456);
   
  std::cout<<"now error code is non zero again : "<<errno<<std::endl;
    
  return 0;
}
 
