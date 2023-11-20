### Lambda functions (and some STL algorithms)

There is good [book](https://books.google.it/books/about/C++_Lambda_Story.html?id=wqw2zgEACAAJ&redir_esc=y) about lambdas if you want to know more than needed for "survival".

*While there is nothing to stop you from always using lambda functions instead of "normal" ones (except it being harder to write/read the code), they are usually only used with STL algorithms.*

But to better understand what they do, we must start with "lambda functions in the wild". Actually, sometimes they are called "lambda expressions" or just "lambdas".

The simplest lambda is just

```
[]{};
```

This defines a function that does nothing and can't even be called later as it has no name.

The general possible structure of a lambda function is 

```
[CAPTURES](PARAMETERS)->RETURN_TYPE{WHAT THE FUNCTION DOES}();
```

You can "capture" existing variables.

 - [] 	Empty capture list, nothing will be captured.
 - [something] 	Capture `something` by copy.
 - [&something] 	Capture something by reference.
 - [x, &y] 	Capture y by-copy and y by-reference.
 - [=] 	Capture anything named from the enclosing scope by-copy.
 - [&] 	Capture anything named from the enclosing scope by-reference.
 - [&, x, y] 	Capture anything named from the enclosing scope by reference, except x and y which are captured by-copy.
 - [=, &x] 	Capture anything named from the enclosing scope by copy, except x which must be captured by-reference

Since we are using lambdas outside of STL, we probably need to give them names. The easiest way is let the compiler decide the type for you (it's actually different for each function)

```
auto func = [](int i){ return i; };
```


The things captured by value are captured at the moment the lambda was created, not when it was called. Also, you can't change them by default. To do that, you need a keyword `mutable`

```
int a{0};
auto very_useful_lambda = [a]() mutable {a=a+2;
    std::cout << a << std::endl;
};
```

Now let's look at how to use them with algorithms:

```
int count{0};
//unfortunately, you need an external variable for index
std::generate(vec.begin(),vec.end(),[&count]{count++;return count*count;});
   
//sort wants a function that accepts two parameters and compares them
std::sort(vec.begin(),vec.end(),[](int x,int y){return x>y;});
  
//for_each can be replaced by a range loop usually
std::for_each(vec.begin(),vec.end(),[](int i){std::cout<<i<<std::endl;});


std::transform(vec.begin(),vec.end(),vec2.begin(),[](int& x){return x+2;});
```

### Random Numbers

These are a huge topic, where you need to be more of an expert in statistics than in C++, so I'll just provide examples that you can use for your basic needs.

The header you need to include is called `random`.

There are various algorithms to generate random numbers, in c++ they are called "engines".

For example, we can use

   - std::default_random_engine: The library implementation may choose any engine as the default.
   - std::mt19937: A Mersenne Twister engine //I usually use this
   - std::random_device: A non-deterministic random number generator

Then, we need a distribution:

  - std::uniform_int_distribution : Produces integer values, uniformly distributed across a specified range.
  - std::uniform_real_distribution : Produces floating-point values, uniformly distributed across a specified range.

Here is an example of how to put this together:

```C++
#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>

int main() {
    std::mt19937 engine(std::random_device{}()); // seeded Mersenne Twister engine
    std::uniform_int_distribution<int> dist(1, 100); // distribution in the range [1, 100]
    
    const size_t array_size = 10;
    int array[array_size];

    auto generate_random_number = [&]() { return dist(engine); };  //the lambda functions we just saw
    std::generate(std::begin(array), std::end(array), generate_random_number);
    
    //CODE TO PRINT HERE

    return 0;
}


```


### Exercises:

#### Exercise 0:

"Play around" with examples we saw, try to create a few simple lambda functions of your own to understand how they work. 

#### Exercise 1:

Time the `std::sort` with a lambda function and your own sort implementation (there was some in previous exercise) when sorting a large vector (large enough to take a few seconds).

#### Exercise 2:

Write a function that adds an integer to all your matrix entries (overload the + operator for your class and int, pay attention to it being commutative!). Use lambdas to actually add the number.


#### Exercise 3:

Use lambdas to write a random_fill function for your matrix.








