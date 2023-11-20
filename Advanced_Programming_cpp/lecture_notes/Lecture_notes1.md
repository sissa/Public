### Some history

 - C++ was first developed by **Bjarne Stroustrup at** Bell Labs, starting in 1979, with the aim of adding object-oriented features to C.
 - the language was first called "C with Classes". It offered basic object oriented features like classes and basic inheritance.
C++:
 - the language C++ appeared in 1983. The "++" symbolizes the increment operator in C, indicating that C++ is an improved or incremented version of C. 
 - C++ Standards:
     - ISO/IEC 14882:1998: The first standardized version was released in 1998 by the International Organization for Standardization (ISO), known as C++98.
     - C++03: was kidn of a bug fix release to C++98, didn't change much.
     - C++11: this was major update with many new features, enhancements, and fixes. It introduced auto keyword, nullptr, smart pointers, lambda expressions, rvalue references and range-based for loops. This was almost a new language. Since then the "standard committee" decided to meet every 3 years. *The problem is that C++03 is still being taught as "C++" at many places.*
     - C++14: feature improvements and bug fixes over C++11, function return type deduction, binary literals,  generic lambda expressions, and etc.
     - C++17: parallel algorithms, std::optional, std::variant, and std::filesystem for file system operations, among other features.
     - C++20: concepts, ranges, calendar and timezone library, coroutines. These are major changes, it would take time before they make their way to scientific programming...


### Hello World!

```C++
#include <iostream>
int main(){
    //printing on screen
    std::cout<<"Hello World!"<<std::endl;
    return 0;
}

```

There are 4 topics which are different from C:

- libraries/header files
- strings
- namespaces
- streams

Compile with:

```
g++ -o hello.x hello_world.cpp
```

If your code contains something from at least c++ 14 standard, it's better to pass it to the compiler as `--std=c++14`, for example.



### Recap on variables (same as C)

One can say that "variables" are containers for storing some data values or "a name given to a memory location". They need to have a type and a name. Before we get to discussing the types, let's discuss the names.

There are a few rules:
 - The variable name should begin with a letter;
 - Names are Case Sensetive;
 - Digits may be used in the variable name but not at the first place;
 - No special symbols are alowed except for the underscore;
 - Do not start variable names with double underscore (even though it's technically allowed, but it should be left to special compiler directives)
 - No keywords can be used for variable names.


Keywords have a special meaning to the C++ compiler. They can’t be used for a variable name or function name. You can say that they are the actual "words" of the C++ language. Example: all the in-built variable types' names, `if`, `else`, `new`, `delete`, `while`, `try`, [etc](https://en.cppreference.com/w/cpp/keyword). You don't have to remember all of them today, but don't be surptised when the compiler refuses to work with a "nice short variable name" you came up with - it might be a part of the language.

*Always try to give meaningful names to variables, like `some_counter` or `student_name`, not `ii` and `iii` (unless it's just a loop variable).*

The variables can have a `const` modifier, then they are called "constants". They cannot be modified.

```C
const int A;
```

Always make variables `const` if you don't plan to change them! This will help you avoid errors and will help the compiler create a faster program.

#### Initialization: difference from C

You can use `{}` instead of just `=`.

```C++
bool var{true};
double x{3.5};
float  xx{3.5f};
int a{1};
short int b{2};
long int c{3};
long long int d{4};
char s{'a'};
std::string name; //include the header <strings>
```

*While the C way still works, use this style in C++.*

Try the following:

```C++
int a=3.5;
int b{3.5};
```

The first one will just give a warning if you have them on, but still lets you to lose data. The second one just doesn't compile. So it's safer and thus preferable.

### Namespaces and input/output

You can put functions into namespaces like this:

```C++
#include <iostream>

namespace hello_world {
    void print() {
        std::cout << "Hello, World!" << std::endl;
    }
}

int main() {
    hello_world::print(); // Call the print function inside the hello_world namespace
    return 0;
}
```

You won't need to use this until you work on a large project, but you should understand what namesapces are.

You can bring the functions from inside the namespace into main by saying "using namespace NAME_OF_NAMESPACE", but it might cause confusion and name clash, so it's best to be avoided. Especially for huge namespaces like `std`.

The most used examples would be `std::cout` and `std::cin` used for writing/reading the standard output. (What those objects actually are, we will learn later, for now it's enough to know that they "live" inside `std`.)

```C++
int a{10};
std::cout<<"This is an example, a is " << a << std::endl;
std::cout<< "please enter new value for a " <<std::endl;
std::cin >> a;
std::cout <<"new value is: " <<a<<std::endl;

```

### References and passing parameters to functions:

*Forget about passing "by pointer", like f(int \* a) from  C.*

As we already know, pointer is a variable that stores the memory address of whatever it points to. It needs to have a type to know how to read that memory.

```C++
int a{0};
int* pointer{nullptr}; //note: use of NULL is not recommended in c++, use `nullptr` instead
pointer=&a; //here & means *address of the variable*
```

To get access to a, we need to **dereference** a pointer by placing a `*` before the name. We have already seen this (note how nice it is to not care what type it is in order to print):

```C
std::cout<< *pointer << std::endl;
```

A reference is defined with the `&` and *should be initialized at declaration*. 

**This is not the same `&` as we had when taking the address,** so things might look very confusing at first. Do "play around" with examples to understand what's going on.

```C++
int a{0};
int& b{a};
```
Now `b` becomes an alias for a. You do with `b` whatever you wanted to do with `a`. If you run the following, you will see that the addresses and values of the variable and a reference to it are equal.

```C++
    int a{77};
    int& c{a};//c becomes an alias for a
    std::cout<<"a is: "<<a<<std::endl;
    std::cout<<"c is: "<<c<<std::endl;
    std::cout<<"address of a is: "<<&a<<std::endl;
    std::cout<<"address of c is: "<<&c<<std::endl;
```

You can say that a reference is *a constant pointer that automatically dereferences itself*.


Now, when we pass something to functions in C++ and say we want to "pass by reference", we actually *pass by reference*:

```C++
#include <iostream>
void add_two(int& a){
    a=a+2;
}
int main(){
   int b{3};
   add_two(b);
   std::cout<<b<<std::endl;
}
```
Look how much simpler the syntax is - no stars inside and no `&` in passing! 


Always pass as `const &` to printing functions. They shouldn't get copies to avoid wasting memory, but they also shouldn't change anything.


In C++, there are also "r-value references". Those reference unnamed things, which are temporary. For example, is you call some function as `f(2)`, there is no need to make a copy of 2 since you don't care if 2 will be modified or not, it's not a variable. You can as well "pass it directly". This will use "move semantics" and we will come back to it when studying classes in-depth.

For example,

```C
void print(int &&a){...}
```

Will be called if you have `print(7)`. Note that `print(7)` would fail if you had `void print(int& a)` instead.


### Function overloading

In C++ you can overload functions to have the same name, but different number of type of parameters. Note that references also make the type different.

```C++
#include <iostream>

// Function to sum two integers, commented out or it won't compile
/*int sum(int a, int b) {
    std::cout << "Integer version called.\n";
    return a + b;
}
*/
// Function to sum two doubles
double sum(double a, double b) {
    std::cout << "Double version called.\n";
    return a + b;
}

//triple sum
int sum(int a, int b, int c) {
    std::cout << "Triple version called.\n";
    return a + b + c;
}

// Function to sum two integers using lvalue references
int sum(const int &a, const int &b) {
    std::cout << "Lvalue reference version called.\n";
    return a + b;
}

// Function to sum two integers using rvalue references
int sum(int &&a, int &&b) {
    std::cout << "Rvalue reference version called.\n";
    return a + b;
}

int main() {
    int a = 5, b = 3;

    // Call sum with int parameters
    std::cout << "Sum of integers: " << sum(a, b) << "\n\n";

    // Call sum with double parameters
    std::cout << "Sum of doubles: " << sum(2.5, 3.5) << "\n\n";

    // Call sum with lvalue reference parameters
    std::cout << "Sum using lvalue references: " << sum(a, b) << "\n\n";

    // Call sum with rvalue reference parameters
    std::cout << "Sum using rvalue references: " << sum(10, 20) << "\n\n";

   // Call triple sum
    std::cout << "Sum of 3 elements: " << sum(10, 20, 10) << "\n\n";

    return 0;
}


```

Let's uncomment the first function and see what happens. Compiler gets confused cause technially both `f(int a)` and `f(int& a)` can be called on a variable and both `f(int a)` and `f(int&& a)` can be called on an unnamed number.



### Introduction to templates

*Good news - outside of the big projects, you don't have to deal with separating headers from implementation and having complicated Makefiles. *

### Templates

extra reference book:

"C++ Templates: The Complete Guide 2nd Edition"
by David Vandevoorde

#### Function templates

What if you want to write a function to print different types of data? You would need to overload your `print()` function for every type you are going to use it with. It becomes cumbersome very fast and makes code hard to maintain if new types are added. Luckily, in c++ there is an easy solution: templates.

```C++
template <typename T>
void print(const T& x){
    //all we need is the operator << be defined for the type T
    std::cout<<x<<std::endl;
}
```

Now, if you call your `print()` function with whatever type, compiler will have an overloaded function for that type ready for you. The type needed will be deduced from the argument. If you want to have a different type from what the compiler would normally assume, you can specify that:

```C++
double a{3.9};
print<int>(a);
```

You can also have multiple templated arguments if you need. For example,

```C++
template <typename T, typename M>
void print(const T& x, const M& y){
    std::cout<<x<<" "<<y<<std::endl;
}
```

Templates need to be "instantiated" by the compiler at compile time, thus if you separate the declarations and definitions into different files as is done in `C`, you have to instatiate it manually. In many cases, that almost defeats the purpose of using templates and, unless working with projects where you care for executable size, can be avoided by simply creating "a header only library" ( which is not a library in a strict sense, but everyone is calling them that), that is, putting all the function/class definitions entirely into header files.




### Introduction to classes:

There are 2 keywords to define classes in c++: `class` and `struct`. 

**The `struct` is not the same as in C, it's still a class.** That is, you can add functions to it now.

```C++
struct CCoords{
    double x;
    double y;
    void print();
};
```
The `x` and `y` are "member variables" (or "fields"), `print` is a "member function". You can access them like this:

```C++
CCoords var;
var.x=2;
var.y=3;
var.print();
```

The difference of `class` from `struct` is that by default all it's members are "private" and the `var.x` call wouldn't work "outside the class". Usually, if you only have public members, it's recommended to use `struct`, but I prefer avoiding it to not confuse with `C` and just putting the `public` keyword at the start (more information about `public` and `private` variables will be given when we discuss classes in-depth).

```C++
class CAnotherCoords{
public:
    double x;
    double y;
    void print();
};
```

One of the special member functions that doesn't have a return type at all is *constructor*. Constructors exist to initialize class member variables. Default constructor takes no parameters (if you don't want it to exist, you can use `CCoords() = delete;`).

```C++
class CCoords{
    double x;
    double y;
public:
    //default constructor
    CCoords(){
      x=0;y=0;  
    }
    //constructor with a parameter
    //a different syntax with the initializer list
    //it's "just a syntax" here, but can be important when member variable is also of some class type
    //pay attention to the initialization order!
    CCoords(double x1, double y1):x(x1),y(y1){
    }
    //only need the declaration here
    void print();
    //try to implement them yourself!
    auto getx();//this is c++14 standard
    auto gety();
    void setx(double a);
    void sety(double a);
};
```

If defining all the functions inside a class makes it too long (anything longer then "one screen" is too long), you can take the definition outside the class with the following syntax.

```C++
void CCoords::print() {
    std::cout<<x<<" "<<y<<std::endl;
}
```



### Exercises:

#### Exercise 0:
Read the lecture notes and run all the examples mentioned in them. *Especially make sure you understand why each function is called in the example for functions overloading and what r-value references are.*

#### Exercise 1:

Take any of the simple C exercises we did which you implemented with functions and template them. Make sure you use the C++ way of passing parameters.


#### Exercise 3:
Rewrite the square root exercise with classes. The main should look like:

```C++
int main(){
    CCoeffs<double> coeffs;
    coeffs.get();
    CSolver<double> solver(coeffs);
    solver.solve();
}
```

#### Exercise 4 (bisection):
Rewrite the bisection exercise similar to the previous exercise.





