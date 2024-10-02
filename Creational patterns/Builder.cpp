#include <iostream>
#include <string>

// Product
class Pizza {
public:
    void setDough(const std::string& dough) {
        dough_ = dough;
    }

    void setSauce(const std::string& sauce) {
        sauce_ = sauce;
    }

    void setTopping(const std::string& topping) {
        topping_ = topping;
    }

    void describePizza() const {
        std::cout << "Pizza with " << dough_ << " dough, " << sauce_ << " sauce and " << topping_ << " topping.\n";
    }

private:
    std::string dough_;
    std::string sauce_;
    std::string topping_;
};

// Builder
class PizzaBuilder {
public:
    virtual ~PizzaBuilder() {}

    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza getPizza() = 0;
};

// Concrete Builder for Cheese Pizza
class CheesePizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override {
        pizza_.setDough("thin");
    }

    void buildSauce() override {
        pizza_.setSauce("tomato");
    }

    void buildTopping() override {
        pizza_.setTopping("cheese");
    }

    Pizza getPizza() override {
        return pizza_;
    }

private:
    Pizza pizza_;
};

// Director
class Waiter {
public:
    void makePizza(PizzaBuilder& builder) {
        builder.buildDough();
        builder.buildSauce();
        builder.buildTopping();
    }
};

int main() {
    Waiter waiter;
    CheesePizzaBuilder cheesePizzaBuilder;

    waiter.makePizza(cheesePizzaBuilder);
    Pizza pizza = cheesePizzaBuilder.getPizza();
    pizza.describePizza();

    return 0;
}

/*
Trong ví dụ này, có một lớp giao diện PizzaBuilder định nghĩa các phương thức cần thiết để xây dựng một pizza. 
Lớp ConcreteBuilder (CheesePizzaBuilder) triển khai các phương thức này để xây dựng một pizza cụ thể (pizza với phô mai). 
Cuối cùng, lớp Waiter là người điều khiển quá trình xây dựng pizza, sử dụng một Builder cụ thể để tạo ra một pizza và trả về kết quả cuối cùng.
*/