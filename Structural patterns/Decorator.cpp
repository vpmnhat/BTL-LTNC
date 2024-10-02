#include <iostream>
#include <memory>
#include <string>

// Component
class Coffee {
public:
    virtual ~Coffee() = default;
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
};

// Concrete Component
class SimpleCoffee : public Coffee {
public:
    std::string getDescription() const override {
        return "Simple Coffee";
    }

    double cost() const override {
        return 2.0;
    }
};

// Decorator
class CoffeeDecorator : public Coffee {
protected:
    std::unique_ptr<Coffee> coffee;
public:
    CoffeeDecorator(std::unique_ptr<Coffee> c) : coffee(std::move(c)) {}
};

// Concrete Decorators
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(std::unique_ptr<Coffee> c) : CoffeeDecorator(std::move(c)) {}

    std::string getDescription() const override {
        return coffee->getDescription() + ", Milk";
    }

    double cost() const override {
        return coffee->cost() + 0.5;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(std::unique_ptr<Coffee> c) : CoffeeDecorator(std::move(c)) {}

    std::string getDescription() const override {
        return coffee->getDescription() + ", Sugar";
    }

    double cost() const override {
        return coffee->cost() + 0.2;
    }
};

int main() {
    std::unique_ptr<Coffee> myCoffee = std::make_unique<SimpleCoffee>();
    std::cout << myCoffee->getDescription() << " $" << myCoffee->cost() << std::endl;

    myCoffee = std::make_unique<MilkDecorator>(std::move(myCoffee));
    std::cout << myCoffee->getDescription() << " $" << myCoffee->cost() << std::endl;

    myCoffee = std::make_unique<SugarDecorator>(std::move(myCoffee));
    std::cout << myCoffee->getDescription() << " $" << myCoffee->cost() << std::endl;

    return 0;
}

/*
In this code:

Coffee is the base abstract component.
SimpleCoffee is a concrete component.
CoffeeDecorator is an abstract decorator class that implements the Coffee interface and contains a pointer to a Coffee object.
MilkDecorator and SugarDecorator are concrete decorators that add functionality (description and cost) to the base coffee.

The main function demonstrates creating a simple coffee and then decorating it with milk and sugar, showing the combined description and total cost.
*/