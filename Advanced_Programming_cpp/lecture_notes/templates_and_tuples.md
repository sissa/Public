 
#### Non-type template parameters:

We can also template something on "integer" numbers. By "integer" here is meant anything that is mathematically integer, not just `int`. We have already seen this in `std::array<TYPE, LENGTH>`.

```cpp
template <typename T, short int N>
void add_number(T& var){
    var=var+N;
}

int main(){
    double b{4.7};
    add_number<double,7>(b);
    std::cout<<b<<std::endl;
    return 0;
}
```


#### Compile-time recursion:

(even though this looks exotic and unnecessary, later today we will see where it actually can be used)

In fact, templates are "Turing complete", you can "build a computer" out of just c++ templates.

But let's do a simple thing - use "compile time recursion" to calculate a factorial:

```cpp
#include <iostream>

template <size_t N>
constexpr size_t factorial() {
    if constexpr (N == 0) {
        return 1;
    } else {
        return N * factorial<N - 1>();
    }
}

int main() {
    std::cout << "Factorial of 5: " << factorial<5>() << std::endl;
    std::cout << "Factorial of 10: " << factorial<10>() << std::endl;
}

```

The `constexpr` is available from C++11 and denotes that it's possible to evaluate the value of a function or variable at compile time. It was very basic at C++11 though, `if` is only allowed from C++17.


#### Compile time class definition recursion:

```cpp
#include <iostream>

template <size_t N>
struct Factorial {
    static const size_t value = N * Factorial<N - 1>::value;
};

// Base case
template <>
struct Factorial<0> {
    static const size_t value = 1;
};

int main() {
    const size_t fact5 = Factorial<5>::value;  // 120
    std::cout << "Factorial(5) = " << fact5 << std::endl;
}

```


#### Variadic templates:

Variadic templates, introduced in C++11, are a feature that allows a template to accept a variable number of template arguments of any type, that is, you can template on a variable number of arguments, for example if you wanted to have a function that can be called as

```cpp
myPrint(1,2,"Hi",9.0);
myPrint('c', 1.4, 9,0, "kjhkjhkjh");

```

First, you need to write a "normal" print function:

```
template <typename T>
void myPrint(const T& arg){
     std::cout<<arg<<" ";
}
```

Then, you use `...` (ellipsis) to tell the compiler that the number of variables can change:

```
template <typename T, typename... Types>
void myPrint(const T& arg, const Types&... args){
    std::cout<<arg<<" ";
    myPrint(args...);
}
```
You need the "normal" print function here to stop the recursion.


Here is the full program:

```cpp
#include <iostream>
template <typename T>
void myPrint(const T& arg){
     std::cout<<arg<<" ";
}

template <typename T, typename... Types>
void myPrint(const T& arg, const Types&... args){
    std::cout<<arg<<" ";
    myPrint(args...);
}

int main(){
    myPrint(1,2,3.0,"meow",'c');
    return 0;
}

```

#### Compile time loops


```cpp
#include <iostream>
#include <utility>

template <size_t... Ints>
constexpr size_t factorial_impl(std::index_sequence<Ints...>) {
    return (... * (Ints + 1));
}

template <size_t N>
constexpr size_t factorial() {
    return factorial_impl(std::make_index_sequence<N>());
}

int main() {
    constexpr size_t result = factorial<5>();
    std::cout << result << std::endl;  // Outputs: 120
}

```


#### std::tuple

what if you want to keep objects of different type in one container?

`std::tuple` allows exactly that.

```cpp
#include <iostream>
#include <tuple>

int main(){
    auto t = std::make_tuple(0, "hello", 4.9,'c',7,90);
    constexpr int size = std::tuple_size<decltype(t)>::value; // this is how you know how many elements there are
    std::cout<<size<<std::endl;
    //this will not work in a loop
    std::cout<<std::get<0>(t)<<std::endl;
    std::cout<<std::get<1>(t)<<std::endl;
    std::cout<<std::get<2>(t)<<std::endl;
    std::cout<<std::get<3>(t)<<std::endl;
    //std::cout<<std::get<6>(t)<<std::endl; <--- complains as there are not enough elements in t

    //implement this function using compile-time recursion and variadic templates
   // print_tuple(t);
    return 0;
}
```

Why don't we just store data in a class instead of this? Because it might be that we don't know how many "fields" there should be and don't want to name them. Tuples are more flexible for certain cases.


#### Template specialization:

You can make the compiler produce very different functions based on the type. This is useful when dealing with old C-interface or when some operations are not permitted for certain types. Or when your algorithm just requires different actions based on the type of the variable.

There are 3 ways to specialize a template.


#### The straighforward way way

This requires to create "default version" and then just list the other versions manually:

```cpp
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
```

But this might require too much "code reduplication" and also doesn't allow  to "group the types" (like, long int and int or double and float).

#### SFINAE (Substitution Failure Is Not An Error)

Let's look at the code:


```cpp

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

```

So,  what happens here? 

Let's look at the ` template <typename U = T, typename std::enable_if<std::is_same<U, int>::value, int>::type = 0>`:

   - `template <typename U = T`:
     This defines a new template type parameter U and gives it a default value of T (which might be another template parameter defined elsewhere in the code).
   - `typename std::enable_if<...>::type`:
    `std::enable_if` is a type trait used in SFINAE to conditionally remove methods, functions, or class specializations from overload resolution based on a compile-time boolean value. It provides a member typedef type only if its first template argument is true. Otherwise, std::enable_if has no member type.
   - `std::is_same<U, int>::value`:
     This is another type trait. It checks if U is the same type as int. `::value` will be true if `U` is `int` and false otherwise.
   - `std::enable_if<std::is_same<U, int>::value, int>`:

  If U is int (meaning std::is_same<U, int>::value is true), then `std::enable_if` provides a type typedef, which, in this case, would be int.
   - = 0:
   This is a default value for a non-type template parameter. It effectively creates an optional template parameter that is only valid if the conditions in enable_if are met. If the conditions are not met, trying to instantiate the template will lead to a substitution failure (which is not an error).

*In simpler terms, this line is saying*:

"Enable this piece of code if U (which defaults to T) is of type int."

This is hard to understand at first, but now we don't have to provide "default" version (although we did in the example), so we can let it fail if the user of the class gives something that was not intended.

However, if you have any choice, use C++17:

#### By using constexpr

This is probably the easiest way, but it's only available from C++17.

```cpp
#include <typeinfo>

template <typename T>
void CMyClass<T>::Function(){
    if constexpr(std::is_same_v<int,T>){
        std::cout<<"we are dealing with int"<<std::endl;
    }
    if constexpr(std::is_same_v<double,T>){
        std::cout<<"we are dealing with double"<<std::endl;
    }
    if constexpr(std::is_integral_v<T>){
        std::cout<<"we are dealing with something \"integer\", but not int "<<std::endl;
    }else{
        std::cout<<"this is something something non \"integer\" "<<std::endl;
    }
}

```

#### Exercise0:

Read and understand and run all the examples.


#### Exercise1:

Use "non-type template parameters" to calculate [Fibboncci numbers](https://en.wikipedia.org/wiki/Fibonacci_sequence), just like we did with factorial. Use `size_t` instead of `int` and find out what's the default recursion depth limit of your compiler. Write 2 versions of the program  - one with "plain template specialization" and another with `constexpr if`. The "plain templates" can just use functions (no ifs) or follow example for the class instead.


#### Exercise2:

Write a function that uses variadic templates to return the smallest of its arguments.

#### Exercise3:

Implement a function to print a tuple using compile time recursion and variadic templates. 

Hints:

 - you will need to write 2 functions, one templated on a size parameter as well as on types
 - you can know how many parameters are in a pack with `sizeof...(Types)`
 - if you template on `<typename class... TupleTypes>`, then  your tuple type is `std::tuple<TupleTypes...>`


#### Exercise4:

This time print the tuple using `index_sequence`.

#### Exercise5:

Specialize the template in your "matrix fill" function, so that it uses "random int" distribution or "random float" distribution (look for exact names in the notes about random numbers) based on the matrix entries' type. You can choose the way to do this.

#### Exercise6:

*This is an exercise that will be useful in the future. You don't have to understand the code below, but you should be able to template and specialize the class for ints and doubles.*


You need to template this class on the type of "data", then specialize the templates for send and recv functions so that they use `MPI_DOUBLE` for double (like it is now), `MPI_INT` for int and `MPI_BYTE` for everything else (you will need to `reinterpret_cast` just like we did for when printing/reading binary file). Do this in 3 different ways mentioned in the lecture.


```cpp

#include <iostream>
#include <vector>
#include <mpi.h>

class CMPIVector {
public:
    std::vector<double> data;

   //SPECIALIZE THESE 2 FUNCTIONS FOR INTS AND DOUBLES, FOR INTS USE MPI_INT
   //FOR THE OTHER TYPES, USE REINTERPRET_CAST LIKE WE DID FOR WRITING BINARY FILES
   //AND SEND AS MPI_BYTE 
    void send(int dest, int tag, MPI_Comm comm) const {
        MPI_Send(data.data(), data.size(), MPI_DOUBLE, dest, tag, comm);
    }

    void recv(int source, int tag, MPI_Comm comm) {
        MPI_Recv(data.data(), data.size(), MPI_DOUBLE, source, tag, comm, MPI_STATUS_IGNORE);
    }
    void print() const {
        for (const double& val : data) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    CMPIVector vec;
    vec.data.resize(5);
    
    if (rank == 0) {
        std::fill(vec.data.begin(), vec.data.end(),7);
        vec.send(1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        vec.recv(0, 0, MPI_COMM_WORLD);
        std::cout << "Rank 1 received: ";
        vec.print();
    }

    MPI_Finalize();
    return 0;
}

```

First, test that this works on your computer (it should seeing we installed mpi, but don't forget to load the corresponding module). Compile with 

```
mpic++ -o mpi_temp_spec.x WHATEVER_YOU_CALLED_THIS.cpp
```

Then, run with 

```
mpirun -np 2 mpi_temp_spec.x
```


Then, after modification, the following `main` should also work:

```cpp

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    CMPIVector<int> vec_int;
    vec_int.data.resize(5);
    CMPIVector<double> vec_double;
    vec_double.data.resize(5);
    CMPIVector<float> vec_float;
    vec_float.data.resize(5);
     

    if (rank == 0) {
        std::fill(vec_int.data.begin(), vec_int.data.end(),7);
        std::fill(vec_double.data.begin(), vec_double.data.end(),5.3);
        std::fill(vec_float.data.begin(), vec_float.data.end(),1.4);
        vec_int.send(1, 0, MPI_COMM_WORLD);
        vec_double.send(1, 0, MPI_COMM_WORLD);
        vec_float.send(1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        vec_int.recv(0, 0, MPI_COMM_WORLD);
        vec_double.recv(0, 0, MPI_COMM_WORLD);
        vec_float.recv(0, 0, MPI_COMM_WORLD);
        std::cout << "Rank 1 received: ";
        vec_int.print();
        vec_double.print();
        vec_float.print();
    }

    MPI_Finalize();
    return 0;
}

```



```






