### Measuring time

We can use the `std::chrono` from the header `chrono`. The old c-style timing from `<ctime>` header also works, but is less accurate and less flexible for uses with modern interfaces, so we will not discuss any examples from it. To start the timings, do:

```
  std::chrono::time_point<std::chrono::steady_clock> t_start;
  t_start = std::chrono::steady_clock::now();//we could just use auto
```

To end:

```
auto t_end = std::chrono::steady_clock::now();
auto total = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count();
```

There are other clocks in `chrono`, for example `system_clock` and `high_resolution_clock`, but the first one depends on your laptop time and might give surprises if it changes during the execution (for example, corrected from time server) and the second one is implementation-dependent, so you never know what it really is.



Here is a full example:

```C++
#include <iostream>
#include <chrono>
#include <thread> //WE WILL NOT REALLY LEARN THREADS, IT'S FOR PARRALEL STUFF, BUT SLEEP IS NICE TO KNOW

int main() {
    //the actual start type is std::chrono::time_point<std::chrono::steady_clock>
    // see now how cool "auto" is?
    auto start = std::chrono::steady_clock::now();

    // Code to measure time for
    std::this_thread::sleep_for(std::chrono::seconds(2));

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Time taken by function: " << duration << " milliseconds" << std::endl;

    return 0;
}
```




#### Exercise:

Write a simple scoped timer. It should start timing in the constructor, then stop and print the result in the destructor. It should also take a string in the constructor so that it could print what it measured in words.


First, you should be able to test is with this `main`:

```C++
int main(){

    double a{0};
    {CSimple_Timer t{"test"};
    for (int i=0;i<100000000;i++){
        a+=std::sqrt(i*std::sqrt(i))*pow(i,0.234);
    }
    std::cout<<a<<std::endl;
    }//of timer
     
}
```

Then, time your matrix exercise.

#### Exercise 2: (THIS WILL BE CHECKED AT THE EXAM, CAUSE YOU WILL NEED A GOOD TIMER FOR USE LATER)

Use `std::map` to modify your timer in such a way that you could now call it with the same string several timeS and get cumulative timings, for example:

```C++
 {CSimple_Timer t{"function 1"};
   f1();
  }
 {CSimple_Timer t{"function 2"};
   f2();
  }
 {CSimple_Timer t{"function 1"};
   f1();
 }
 {CSimple_Timer t{"function 2"};
   f2();
 }
```

Should output that the each function has been called twice and report the total timing for each function.




 
