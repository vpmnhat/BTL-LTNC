#include <iostream>
#include <memory>

// Interface for the product
class Product {
public:
    virtual void operation() = 0;
    virtual ~Product() {}
};

// Concrete Product 1
class ConcreteProduct1 : public Product {
public:
    void operation() override {
        std::cout << "ConcreteProduct1 operation\n";
    }
};

// Concrete Product 2
class ConcreteProduct2 : public Product {
public:
    void operation() override {
        std::cout << "ConcreteProduct2 operation\n";
    }
};

// Creator Interface
class Creator {
public:
    virtual std::unique_ptr<Product> factoryMethod() = 0;
    virtual ~Creator() {}
    
    void anOperation() {
        std::cout << "Creator operation\n";
        std::unique_ptr<Product> product = factoryMethod();
        product->operation();
    }
};

// Concrete Creator 1
class ConcreteCreator1 : public Creator {
public:
    std::unique_ptr<Product> factoryMethod() override {
        return std::make_unique<ConcreteProduct1>();
    }
};

// Concrete Creator 2
class ConcreteCreator2 : public Creator {
public:
    std::unique_ptr<Product> factoryMethod() override {
        return std::make_unique<ConcreteProduct2>();
    }
};

int main() {
    // Create Concrete Creator 1
    std::unique_ptr<Creator> creator1 = std::make_unique<ConcreteCreator1>();
    creator1->anOperation();
    
    // Create Concrete Creator 2
    std::unique_ptr<Creator> creator2 = std::make_unique<ConcreteCreator2>();
    creator2->anOperation();
    
    return 0;
}

/*
Trong ví dụ này, có các lớp interface và lớp cụ thể cùng với lớp Creator và lớp cụ thể của nó. 
Lớp Creator có một phương thức factoryMethod() mà các lớp con sẽ triển khai để tạo ra các đối tượng cụ thể. 
Bên trong phương thức factoryMethod(), các đối tượng cụ thể được tạo ra và trả về. 
Bằng cách này, người dùng chỉ cần tương tác với lớp Creator và không cần quan tâm đến việc tạo ra đối tượng cụ thể.
*/