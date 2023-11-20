 
### Operator overloading

All the operators can be overloaded for class members. Technically, this term is not fully correct, as "overloading" implies that the operator already exists, but this term is often used even when it doesn't.

Example of arithmetic operator overloading:

```C++
CCoords operator+(const CCoords& b) {
        CCoords result;
        result.x = x + b.x;
        result.y = y + b.y;
        return result;
    }
```

What if you want to add an integer to your class variable? You need to define the operator out of the class rather than making it a class member function. Make it a `friend`, so that it could access private member variables. 

inside the class:
```C++
friend CCoords operator+(const int& b, const CCoords& c);
```

outside the class:

```C++
CCoords operator+(const int& b, const CCoords& c){
    CCoords result;
    result.x=c.x+b;
    result.y=c.y+b;
    return result;
};
```

The order of the argumenets matter, you need a separate operator overload for coords+int.

You can also overload non-arithmetic operators, like `()`, `[]`,`<<`, etc. See the example file `operators2.cpp`.


**STEP 1 OF THE EXERCISE THAT YOU WILL NEED FOR THE EXAM**

  Rewrite your matrix multiplication exercise (no blas) as a class and use static arrays to store the data (we didn't see the random numbers generators so far, so just use the C things). Overload the multiplication AND addition operators. Overload put to (`<<`) operator. Don't write them to files so far, only work with small matrixes you can print on screen.
I should be able to run the following main:

```C++
int main(){
    CMatrix<double> A, B;
    A.fill();
    B.fill();
    std::cout<<"A is"<<std::endl;
    std::cout<< A << std::endl;
    std::cout<<"B is"<<std::endl;
    std::cout<< B <<std::endl;
    std::cout<<"product is"<<std::endl;
    std::cout<< A*B << std::endl;
    std::cout<<"sum is"<<std::endl;
    std::cout<< A+B <<std::endl;
    return 0;
}
```











