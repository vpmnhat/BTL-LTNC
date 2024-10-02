#include <iostream>
#include <unordered_map>
#include <vector>

// Flyweight class
class Flyweight {
public:
    Flyweight(const std::string& intrinsicState) : intrinsicState_(intrinsicState) {}

    void operation(const std::string& extrinsicState) {
        std::cout << "Intrinsic State = " << intrinsicState_ << ", Extrinsic State = " << extrinsicState << std::endl;
    }

private:
    std::string intrinsicState_;
};

// Flyweight Factory class
class FlyweightFactory {
public:
    Flyweight* getFlyweight(const std::string& intrinsicState) {
        if (flyweights_.find(intrinsicState) == flyweights_.end()) {
            flyweights_[intrinsicState] = new Flyweight(intrinsicState);
        }
        return flyweights_[intrinsicState];
    }

    ~FlyweightFactory() {
        for (auto& pair : flyweights_) {
            delete pair.second;
        }
    }

private:
    std::unordered_map<std::string, Flyweight*> flyweights_;
};

// Client code
int main() {
    FlyweightFactory factory;
    
    std::vector<std::string> extrinsicStates = {"State1", "State2", "State3"};
    std::vector<std::string> intrinsicStates = {"Flyweight1", "Flyweight2"};

    for (const auto& intrinsicState : intrinsicStates) {
        Flyweight* flyweight = factory.getFlyweight(intrinsicState);
        for (const auto& extrinsicState : extrinsicStates) {
            flyweight->operation(extrinsicState);
        }
    }

    return 0;
}

/*
Flyweight là lớp biểu diễn các đối tượng nhẹ có thể chia sẻ, với intrinsicState là trạng thái nội tại được chia sẻ giữa các đối tượng.
FlyweightFactory là lớp tạo ra và quản lý các đối tượng Flyweight. Nó đảm bảo rằng các đối tượng Flyweight được tái sử dụng thay vì tạo mới mỗi lần.
Trong phần main, chúng ta tạo ra các Flyweight với các trạng thái nội tại khác nhau và sử dụng chúng với các trạng thái ngoại tại khác nhau để biểu diễn hành vi của mẫu thiết kế Flyweight.
*/