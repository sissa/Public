### std::array

The header you need to include is:
```
#include <array>
```

To define a variable, do:

```
std::array<int,5> arr;//you need to pass the number of elements just like with the static array
```

*From now on, you can safely forget about "c-style" static arrays and always use std::array*. Why? It has the same performance, but causes no confusion with pointers, knows it's size and can be used with many C++ algorithms (that we'll see later).

### std::vector

```
include <vector>
```

std::vector provides dynamic array functionality that handles its own memory management. This saves a lot of time, especially on debugging stage. You don't yet know all the horrors of memory management for classes and with vectors you will only need to know them for cuda and the like.

However, it's easy to lose perfomance if you don't know what you are doing. Specifically, there is a handy function `push_back`, which should be used with caution or outright avoided in hpc.

```
std::vector<int> V;
for (int i=0;i<100000;i++){
    V.push_back(i);
}
```

What happens behind the scnenes is that the vector will reserve the memory for itself with what it believs as "enough", then allocate new elemement in that area. Once it runs out of reserved memory, it will *copy eveything to a new location*, which you obvioulsy want to avoid when working with anything big.

So, when working with vectors in hpc, try to treat them like arrays and awaid resizing more than once. Always use `resize(NUMBER)` function, then fill in the values normally. As an alternative, you can call `reserve(NUMBER)` and then do `push_back`, but this way it's not always clear when the vector decides it's time to "move", it's safer to stick with "resize()".

When you work with C-style functions that require a pointer, you can pass vector's contents either as `&myvec[0]` or `myvec.data()`.

#### Iterations over vector:

```C++
    std::vector<int> vec = {1, 2, 3, 4, 5};

    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';
```


While most of the time in scientific codes you do need the index of the vector element to do something, in cases you don't, like in printing, there are other ways to go:

```C++
    std::vector<int> vec = {1, 2, 3, 4, 5};

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

```

less clunky way: (almost like python)

```C++
   for (const auto& elem : vec) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

```



#### Exercise 

Write a version of your matrix exercises using `std::vector` to store data.







