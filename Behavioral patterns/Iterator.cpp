#include <iostream>
#include <vector>

// Abstract Iterator Interface
template <typename T>
class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual T next() = 0;
};

// Concrete Iterator
template <typename T>
class VectorIterator : public Iterator<T> {
private:
    typename std::vector<T>::iterator iter;
    typename std::vector<T>::iterator end;

public:
    VectorIterator(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) : iter(begin), end(end) {}

    bool hasNext() const override {
        return iter != end;
    }

    T next() override {
        if (hasNext()) {
            return *(iter++);
        }
        throw std::out_of_range("Iterator has reached the end.");
    }
};

// Aggregate Interface
template <typename T>
class Container {
public:
    virtual Iterator<T>* createIterator() = 0;
};

// Concrete Aggregate
template <typename T>
class VectorContainer : public Container<T> {
private:
    std::vector<T> elements;

public:
    void add(const T& element) {
        elements.push_back(element);
    }

    Iterator<T>* createIterator() override {
        return new VectorIterator<T>(elements.begin(), elements.end());
    }
};

int main() {
    VectorContainer<int> container;
    container.add(1);
    container.add(2);
    container.add(3);

    Iterator<int>* iter = container.createIterator();
    while (iter->hasNext()) {
        std::cout << iter->next() << " ";
    }
    std::cout << std::endl;

    delete iter;

    return 0;
}

/*
Trong ví dụ này, VectorContainer là một lớp chứa các phần tử (aggregate), và nó cung cấp một Iterator để duyệt qua các phần tử đó. 
VectorIterator là một lớp iterator cụ thể dành cho vector.
*/