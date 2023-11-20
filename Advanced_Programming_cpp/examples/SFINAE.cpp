#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
class CMyClass {
    T a;
public:
    // For non-specialized types
    template <typename U = T, 
              typename std::enable_if<!std::is_same<U, int>::value && 
                                      !std::is_same<U, double>::value, int>::type = 0>
    void do_something() {
        std::cout << "I'm a function that does something for whatever type" << std::endl;
    }
    
    // Specialized for int
    template <typename U = T, typename std::enable_if<std::is_same<U, int>::value, int>::type = 0>
    void do_something() {
        std::cout << "I'm a function that does something for INT" << std::endl;
    }
    
    // Specialized for double
    template <typename U = T, typename std::enable_if<std::is_same<U, double>::value, int>::type = 0>
    void do_something() {
        std::cout << "I'm a function that does something for DOUBLE" << std::endl;
    }
};

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
