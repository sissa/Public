### Inheritance

#### simple member access and inheritance modes:

Inheritance usually is explained as "is a" relationship. Like, if you inherit "triangle" from "shape", then you can say "triangle is a shape".

We can derive a child class from the base class in different access modes: public, protected, private. For example:

`class Derived : public Base`


 - Public inheritance makes public members of the base class public in the derived class, and the protected members ("protected" means friends and derived classes can access) of the base class remain protected in the derived class.
 - protected inheritance makes the public and protected members of the base class protected in the derived class.
 - private inheritance makes the public and protected members of the base class private in the derived class.

Note: private members of the base class are inaccessible to the derived class.

```cpp
class CBase {
  public:
    int x;
  protected:
    int y;
  private:
    int z;
};

class CPublicDerived: public CBase {
  // x is public
  // y is protected
  // z is not accessible from CPublicDerived
};

class CProtectedDerived: protected CBase {
  // x is protected
  // y is protected
  // z is not accessible from CProtectedDerived
};

class CPrivateDerived: private CBase {
  // x is private
  // y is private
  // z is not accessible from CPrivateDerived
};
```

It's possible to inherit from multiple classes at once.

Look at the files `basic.cpp` and `multi.cpp` in examples/ineritance folder.


#### Polymorphism:  virtual functions

One of the key features of class inheritance is that **a pointer to a derived class is type-compatible with a pointer to its base class**. This is called runtime or dynamic polymorhism and is one of the key features of the object oriented design. (It's mostly not recommended in high performace applications, as it's slow.)

```cpp
 #include <iostream>

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b){ 
        width=a; height=b; 
    }
};

class Rectangle: public Polygon {
  public:
    int area(){ 
        return width*height;
    }
};

class Triangle: public Polygon {
  public:
    int area(){ 
        return width*height/2;
    }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  std::cout << rect.area() << '\n';
  std::cout << trgl.area() << '\n';
  return 0;
}
```
Here you used `area()` function as an overloaded one, you knew what you called it on.

Instead of overloading the functions (happens at compile time), you can override them. This requires a `virtual` keyword.


A class that declares or inherits a virtual function is called a polymorphic class.

```cpp
#include <iostream>

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area (){ 
        return 0; 
    }
 //  virtual int area ()=0;//makes the class abstract, then you can't have an object of it
    
};

class Rectangle: public Polygon {
  public:
      //override helps compiler and makes sure you don't type anything wrong
    int area() override{ 
        return width * height;
    }
};

class Triangle: public Polygon {
  public:
    int area() override{ 
        return (width * height / 2); 
    }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon poly;
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  Polygon * ppoly3 = &poly;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  ppoly3->set_values (4,5);
  std::cout << ppoly1->area() << std::endl;
  std::cout << ppoly2->area() << std::endl;
  std::cout << ppoly3->area() << std::endl;
  return 0;
}
```

One important note is that destructors should be made virtual, otherwise the destructor of the base class is going to be called if you are using the pointer to base class. See the file `virtual_dctor.cpp`.


If a class has a pure virtual function (declared with `=0`), then it's an "abstract class" and you cannot have an object of it. It's used for interface only purposes. Virtual functions must be overriden in derived classes, otherwise they become abstract too.



### Exercises:

#### Exercise 0:

Understand the lecture notes. "Play around" with changing inheritance modes, commenting out default constructors, making functions pure virtual, etc.

#### Exercise 1:
Create an abstract base class "shape" and inherit classes triangle (should have 3 vectices member variables) and polygon from it (polygon should have a raw pointer to vertices coordinates within to make life harder). The classes should have functions to calulate perimeter and to print vertice coordinates that work with runtime polymorhism.


 
