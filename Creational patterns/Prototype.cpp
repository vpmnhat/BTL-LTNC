#include <iostream>
#include <string>
#include <memory>

// Abstract base class for prototype
class Prototype {
public:
    virtual std::unique_ptr<Prototype> clone() const = 0;
    virtual void describe() const = 0;
    virtual ~Prototype() {}
};

// Concrete prototype
class ConcretePrototype : public Prototype {
public:
    ConcretePrototype(int id, const std::string& name) : id_(id), name_(name) {}

    std::unique_ptr<Prototype> clone() const override {
        return std::make_unique<ConcretePrototype>(*this);
    }

    void describe() const override {
        std::cout << "ID: " << id_ << ", Name: " << name_ << std::endl;
    }

private:
    int id_;
    std::string name_;
};

int main() {
    // Create a prototype object
    std::unique_ptr<Prototype> original = std::make_unique<ConcretePrototype>(1, "Prototype");

    // Clone the prototype
    std::unique_ptr<Prototype> clone = original->clone();

    // Describe the original object
    std::cout << "Original object: ";
    original->describe();

    // Describe the cloned object
    std::cout << "Cloned object: ";
    clone->describe();

    return 0;
}

/*
Trong ví dụ này, có một lớp giao diện Prototype định nghĩa phương thức clone() để tạo ra một bản sao của đối tượng và một phương thức describe() để mô tả đối tượng. 
Lớp ConcretePrototype triển khai các phương thức này và cung cấp một cách để tạo ra một bản sao của nó. 
Trong hàm main(), ta tạo một đối tượng prototype ban đầu và sau đó tạo một bản sao của nó bằng cách sử dụng phương thức clone(). 
Cuối cùng, ta mô tả cả đối tượng ban đầu và đối tượng đã được sao chép.
*/