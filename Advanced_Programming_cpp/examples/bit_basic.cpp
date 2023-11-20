#include <iostream>

int main(){
  int a = 5;  // 0101 in binary
  int b = 3;  // 0011 in binary
  // AND
  int c = a & b;  // 0001 = 1 in decimal
  std::cout<<c<<std::endl;
    
  //OR
  c = a | b;  // 0111 = 7 in decimal
  std::cout<<c<<std::endl;
  
  //XOR
  c = a ^ b;  // 0110 = 6 in decimal
  std::cout<<c<<std::endl;
  
  //NOT
  c = ~a;  // 1010 = -6 in decimal (two’s complement)
  std::cout<<c<<std::endl;
 
  //left shift
  c = a << 1;  // 1010 = 10 in decimal 
  std::cout<<c<<std::endl;
  
  //right shift
  c = a >> 1;  // 0010 = 2 in decimal
  std::cout<<c<<std::endl;
}
