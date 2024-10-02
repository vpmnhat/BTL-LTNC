#include <iostream>
#include <memory>

// Abstract Product
class AbstractProduct {
public:
    virtual void operation() = 0;
    virtual ~AbstractProduct() {}
};

// Concrete Product 1
class ConcreteProduct1 : public AbstractProduct {
public:
    void operation() override {
        std::cout << "ConcreteProduct1 operation\n";
    }
};

// Concrete Product 2
class ConcreteProduct2 : public AbstractProduct {
public:
    void operation() override {
        std::cout << "ConcreteProduct2 operation\n";
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual std::unique_ptr<AbstractProduct> createProduct() = 0;
    virtual ~AbstractFactory() {}
};

// Concrete Factory 1
class ConcreteFactory1 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProduct> createProduct() override {
        return std::make_unique<ConcreteProduct1>();
    }
};

// Concrete Factory 2
class ConcreteFactory2 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProduct> createProduct() override {
        return std::make_unique<ConcreteProduct2>();
    }
};

int main() {
    // Create Concrete Factory 1
    std::unique_ptr<AbstractFactory> factory1 = std::make_unique<ConcreteFactory1>();
    std::unique_ptr<AbstractProduct> product1 = factory1->createProduct();
    product1->operation();

    // Create Concrete Factory 2
    std::unique_ptr<AbstractFactory> factory2 = std::make_unique<ConcreteFactory2>();
    std::unique_ptr<AbstractProduct> product2 = factory2->createProduct();
    product2->operation();

    return 0;
}

/*
Trong ví dụ này, có một lớp giao diện AbstractProduct và hai lớp cụ thể của nó. 
Cũng có một lớp giao diện AbstractFactory và hai lớp cụ thể của nó. 
Trong hàm main(), ta tạo ra các đối tượng của các Factory và sử dụng chúng để tạo ra các sản phẩm tương ứng.
*/