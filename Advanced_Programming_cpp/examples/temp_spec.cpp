#include <iostream>
#include <string>

template <typename T>
class CMyClass {
    T a;
public:
    void do_something() {
        std::cout << "I'm a function that does something for whatever type" << std::endl;
    }
};

template <>
void CMyClass<int>::do_something(){
     std::cout << "I'm a function that does something for INT" << std::endl;
}

template <>
void CMyClass<double>::do_something(){
     std::cout << "I'm a function that does something for DOUBLE" << std::endl;
}


int main(){
    
    CMyClass<double> A;
    CMyClass<int> B;
    CMyClass<float> C;
    CMyClass<std::string> D;
    
    A.do_something();
    B.do_something();
    C.do_something();
    D.do_something();
    
    
}
