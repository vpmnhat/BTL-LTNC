#include <iostream>

// Abstract base class defining the template method
class AbstractClass {
public:
    void TemplateMethod() {
        PrimitiveOperation1();
        PrimitiveOperation2();
    }

    virtual ~AbstractClass() = default;

private:
    // Primitive operations to be implemented by subclasses
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
};

// Concrete class implementing the template method
class ConcreteClass : public AbstractClass {
private:
    // Implementation of primitive operation 1
    void PrimitiveOperation1() override {
        std::cout << "ConcreteClass: PrimitiveOperation1\n";
    }

    // Implementation of primitive operation 2
    void PrimitiveOperation2() override {
        std::cout << "ConcreteClass: PrimitiveOperation2\n";
    }
};

int main() {
    // Create an object of the concrete class
    ConcreteClass concreteObject;

    // Call the template method
    concreteObject.TemplateMethod();

    return 0;
}

/*
Trong ví dụ này, AbstractClass là lớp trừu tượng định nghĩa phương thức mẫu (TemplateMethod) và khai báo các phương thức nguyên thủy (PrimitiveOperation1, PrimitiveOperation2) mà các lớp con cần phải triển khai. 
ConcreteClass triển khai các phương thức nguyên thủy và sử dụng chúng trong phương thức mẫu. 
Khi chạy, chúng ta sẽ thấy output là các hàm nguyên thủy được gọi trong phương thức mẫu theo thứ tự đã định.
*/