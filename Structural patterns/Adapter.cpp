#include <iostream>
#include <string>

// Giao diện Target mà client sử dụng
class Target {
public:
    virtual ~Target() = default;
    virtual std::string Request() const {
        return "Target: The default target's behavior.";
    }
};

// Lớp Adaptee có sẵn mà bạn muốn tích hợp
class Adaptee {
public:
    std::string SpecificRequest() const {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

// Lớp Adapter giúp chuyển đổi giao diện giữa Target và Adaptee
class Adapter : public Target {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* adaptee) : adaptee(adaptee) {}

    std::string Request() const override {
        std::string toReverse = adaptee->SpecificRequest();
        return "Adapter: (TRANSLATED) " + std::string(toReverse.rbegin(), toReverse.rend());
    }
};

// Hàm client code
void ClientCode(const Target* target) {
    std::cout << target->Request() << std::endl;
}

int main() {
    std::cout << "Client: I can work just fine with the Target objects:\n";
    Target* target = new Target;
    ClientCode(target);

    std::cout << "\nClient: The Adaptee class has a weird interface. See, I don't understand it:\n";
    Adaptee* adaptee = new Adaptee;
    std::cout << "Adaptee: " << adaptee->SpecificRequest() << std::endl;

    std::cout << "\nClient: But I can work with it via the Adapter:\n";
    Adapter* adapter = new Adapter(adaptee);
    ClientCode(adapter);

    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}

/*
Trong đoạn code trên:
Target là giao diện mà client của bạn sẽ sử dụng.
Adaptee là lớp hiện có với giao diện không phù hợp với Target.
Adapter là lớp chuyển đổi giữa Target và Adaptee bằng cách kế thừa từ Target và chứa một đối tượng của Adaptee.
ClientCode là hàm đại diện cho mã client sử dụng Target.

Khi chạy chương trình, bạn sẽ thấy cách Adapter chuyển đổi giao diện Adaptee thành Target, cho phép client sử dụng Adaptee thông qua Adapter.
*/