#### Iterators

Iterators provide a bridge between container-like structures and algorithms. They abstract the idea of "pointing to an element" so that you can traverse and manipulate elements regardless of the underlying container.

*Algorithms written with iterators can be applied to any container that provides suitable iterators.*

Iterator categories:

 - Input Iterators: Can read from the pointed-to element.
 - Output Iterators: Can write to the pointed-to element.
 - Forward Iterators: Can read, write, and move forward.
 - Bidirectional Iterators: Like forward iterators but can also move backward.
 - Random Access Iterators: Can jump directly to any element, providing constant-time access.


###  Creating a Custom Iterator

Every iterator should provide the following type definitions (traits) (so that other c++ standard algorithms could understand that it's an iterator) :

```cpp
using value_type = ...;
using difference_type = ...;
using pointer = ...;
using reference = ...;
using iterator_category = ...;
```

Let's look at a full example:


```cpp
#include <iostream>
#include <vector>

template <typename T>
class CMyVector {
public:
    std::vector<T> data;
    CMyVector(std::initializer_list<T> init) : data(init) {}

    class CIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        typename std::vector<T>::iterator iter;

        CIterator(typename std::vector<T>::iterator it) : iter(it) {}

        reference operator*() {
            return *iter;
        }

        CIterator& operator++() {
            ++iter;
            return *this;
        }

        bool operator!=(const CIterator& other) const {
            return iter != other.iter;
        }
    };

    CIterator begin() {
        return CIterator(data.begin());
    }

    CIterator end() {
        return CIterator(data.end());
    }
};

int main() {
    CMyVector<int> vec = {1, 2, 3, 4, 5};
    for (int val : vec) {
        std::cout << val << ' ';
    }
}


```


### Exercise  :

Turn your exam's Linked List into a class and write an iterator over it, so that you could run the following `main`:

```cpp

int main() {
    CLinkedList<int> list;
     for(int i=0;i<8;i++)}{
        list.push_front(i);
     };

    for (const auto& val : list) {
        std::cout << val << " ";
    }

    return 0;
}

```

