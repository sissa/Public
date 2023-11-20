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

