#include <iostream>

// Interface cho các thuật toán
class Strategy {
public:
    virtual void execute() = 0;
    virtual ~Strategy() {}
};

// Các thuật toán cụ thể
class ConcreteStrategyA : public Strategy {
public:
    void execute() override {
        std::cout << "Executing strategy A" << std::endl;
    }
};

class ConcreteStrategyB : public Strategy {
public:
    void execute() override {
        std::cout << "Executing strategy B" << std::endl;
    }
};

// Context sử dụng thuật toán
class Context {
private:
    Strategy *strategy;

public:
    Context(Strategy *strategy) : strategy(strategy) {}

    void setStrategy(Strategy *strategy) {
        this->strategy = strategy;
    }

    void executeStrategy() {
        strategy->execute();
    }
};

int main() {
    ConcreteStrategyA strategyA;
    ConcreteStrategyB strategyB;

    Context context(&strategyA);
    context.executeStrategy();

    context.setStrategy(&strategyB);
    context.executeStrategy();

    return 0;
}

/*
Trong ví dụ này, chúng ta có một interface Strategy, một số lớp cụ thể thực hiện interface này (ví dụ ConcreteStrategyA và ConcreteStrategyB), và một lớp Context sử dụng một trong các thuật toán này. 
Bằng cách này, Context không phụ thuộc vào bất kỳ thuật toán cụ thể nào và có thể chuyển đổi giữa các thuật toán tùy thuộc vào nhu cầu.
*/