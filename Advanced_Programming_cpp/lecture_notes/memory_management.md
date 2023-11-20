### Memory management

#### C-like style memory management 


To allocate the memory on a "heap", use `new`, to free it, use `delete` or `delete[]` (do not use malloc in c++):

```
int* p1 =new int;
int* p =new int[N];
for(int i=0;i<N;i++){
    p[i]=i;
}
delepe p1;
delete[] p;
```

If you are only allocating one object and not an array, use `delete` without brackets:

```
int* p =new int;
...

delete p; 

```

This is easy, basically just replace `malloc` with `new` and `free` with `delete`.
*The "problems" start when we have the allocation happen inside the classes.*


At the very least, we now have a constructor and destructor obligatory:

*Constructor role is to initialize and allocate resources. Destructor's role is to free resources.*

Destructor's syntax requires it to have the same name was a class with a `~` in front. You cannot manually call the destructor, it will be called automatically when the class variable goes out of scope.

```C++
template <typename T>
class CMyClass{
public:
    T* data;
    CMyClass(const int& N);
    ~CMyClass();
};

template<typename T> 
    CMyClass<T>::CMyClass(const int& N) {
    data=new T[N];
    for(int i=0;i<N;i++){
        data[i]=i;
    }
}

template<typename T> 
    CMyClass<T>::~CMyClass() {
    delete[] data;
    data=nullptr;
}

```

This might be enough as a "minimal survival", but what happens if you do

```C++
CMyClass A(10),B(10);
A=B;
```
?

It will crash.
The compiler doesn't know how to make a "deep copy", only a pointer gets copied, so you need to tell it:

``` C++
template <typename T>
CMyClass<T>& CMyClass<T>::operator=(const CMyClass<T>& p){
//first check for self-assignment
if (this != &p) { 
//copy non-dynamic variables
	size=p.size;
//free memory of existing dynamic variables
	if (data != nullptr){
		delete[] data;
		data=nullptr;
    }	
//create and copy dynamic variables
	if(p.data==nullptr){data=nullptr;}
	else{
		data = new T[size];
		for(int i=0;i<size;i++){
			data[i]=p.data[i];
        };
	}//else	
}//of cheking for self-assignement
return *this;
};

```


Note, that if you overload `+` operator, and then call `C=A+B`, the `=` will actually never get called due to the process called ["copy elision"](https://en.cppreference.com/w/cpp/language/copy_elision).

#### Copy constructors


What happens if you now try to pass the object of your class to a function by value? Another crash, because we are missing a "copy constructor". A general rule is that, if you are having pointers in your class and need a destructor, you also need to overload assignment operator and the copy constructor. If you are sure that you will never use them, make them `delete`, otherwise you or someone else later might try to do unexpected things with your class and get a strange crash instead of a clear error message. So, do ` CMyClass& operator=(const CMyClass& p) = delete;`

Here is how you create a copy constructor:

```
template<typename T> 
CMyClass<T>::CMyClass ( const CMyClass<T>& p ) {
//first check for self-assignment
if (this != &p) {
//copy non-dynamic variables
	size=p.size;
//create and copy dynamic variables
	if(p.data==nullptr){data=nullptr;}
	else{
		data = new T[size];
		for(int i=0;i<size;i++){
			data[i]=p.data[i];
        };
	}//else
	
}//of cheking for self-assignement
    
}//copy constructor
```

#### Move constructors

This is not the end of the story. Sometimes you might want to "move" your object instead of copying it (for example, if the object was temporary). There is `std::move` that does that for standard objects and can also do that for you if you create a *move constructor* and *move assignment operator*

```
template<typename T> 
CMyClass<T>::CMyClass ( CMyClass<T> && p ) {
//first check for self-assignment
if (this != &p) {
//copy non-dynamic variables
	size=p.size;
    p.size=0;
//create and copy dynamic variables
    data=p.data;
    p.data=nullptr;
}//of checking for self-assignment

}
```

Now if you do

```C
auto obj5=std::move(obj3);
```

move constructor will be called. Notice, how the above case doesn't call an assignment operator. However,

```
 obj5=std::move(obj2);
```

does.



#### Smart Pointers: Unique Pointer

You can save yourself some typing if you use "smart pointers" from header `memory`. It is considered good practice to never use "raw pointers" if smart ones can be used.

```
 std::unique_ptr<int[]> p(new int[5]);
```

This object will call `delete[]` automatically when going out of scope, so you don't have to worry about freeing the memory manually.

The file `unique2.cpp` has the examples of how to use it inside a class.

If you need to pass the pointer to a C-Style function, use p.get() to get the raw pointer. However, you need to trust the function to not try to deallocating the memory as that would crash your program.



**THESE EXERCISES WILL BE PART OF THE "EXAM DISCUSSION"**

### Exercise1: (continuation of exercise from operator overloading)

   Now that your matrix is a class, use raw pointers to store the data. 
   Make your constructors and assignment operator print something so that you see when they are called.

   I should be able to run the following main:

```C++
int main(){
    CMatrix<double> A(N), B(N); //feel free to have non-square matrices if you had them before, but it's not required
    A.fill();
    B.fill();
    std::cout<<"A is"<<std::endl;
    std::cout<< A << std::endl;
    std::cout<<"B is"<<std::endl;
    std::cout<< B <<std::endl;
    auto C=A*B;
    auto D=A+B;
    std::cout<<"product is"<<std::endl;
    std::cout<< C << std::endl;
    std::cout<<"sum is"<<std::endl;
    std::cout<< D <<std::endl;
    auto E(A);
    std::cout<<"copy of A is"<<std::endl;
    std::cout<< E << std::endl;
    E=B;
    std::cout<<"copy of B is"<<std::endl;
    std::cout<< E << std::endl;
    auto E2(std::move(C));
    std::cout<<"copy of C is"<<std::endl;
    std::cout<< E2 << std::endl;
    //can you print C after this? What happens?
    return 0;
}
```

You need to also have copy and move contructors, as well as assignment operator.

### Exercise2:

   Modify the previous exercise using smart (unique) pointers.






