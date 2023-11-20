#include <iostream> 

class CA{
public: 
  int a;
  mutable int b;
  int c;
  CA(const int& a0, const int& b0, const int & c0):a(a0),b(b0),c(c0){};
  void weird_print() const;
};

void CA::weird_print()const {
  //a=9; //this won't work
  b=77;
  std::cout<<a<<" "<<b<<" "<<c<<std::endl;
}

int main(){
  CA A(1,2,3);
  A.weird_print();
}
