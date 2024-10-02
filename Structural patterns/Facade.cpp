#include <iostream>

// Hệ thống con 1
class Subsystem1 {
public:
    void operation1() {
        std::cout << "Subsystem1: Operation 1\n";
    }
};

// Hệ thống con 2
class Subsystem2 {
public:
    void operation2() {
        std::cout << "Subsystem2: Operation 2\n";
    }
};

// Hệ thống con 3
class Subsystem3 {
public:
    void operation3() {
        std::cout << "Subsystem3: Operation 3\n";
    }
};

// Facade
class Facade {
private:
    Subsystem1* subsystem1;
    Subsystem2* subsystem2;
    Subsystem3* subsystem3;

public:
    Facade() {
        subsystem1 = new Subsystem1();
        subsystem2 = new Subsystem2();
        subsystem3 = new Subsystem3();
    }

    ~Facade() {
        delete subsystem1;
        delete subsystem2;
        delete subsystem3;
    }

    void operationA() {
        std::cout << "Facade: Operation A\n";
        subsystem1->operation1();
        subsystem2->operation2();
    }

    void operationB() {
        std::cout << "Facade: Operation B\n";
        subsystem2->operation2();
        subsystem3->operation3();
    }
};

// Main function
int main() {
    Facade* facade = new Facade();
    facade->operationA();
    facade->operationB();
    delete facade;
    return 0;
}

/*
Subsystem1, Subsystem2, và Subsystem3 là các hệ thống con, mỗi hệ thống cung cấp một số phương thức cụ thể.
Facade cung cấp các phương thức operationA và operationB để tương tác với các hệ thống con mà không cần quan tâm đến chi tiết cài đặt của chúng.
Người dùng chỉ cần sử dụng lớp Facade để gọi các phương thức cần thiết mà không cần trực tiếp tương tác với các hệ thống con.
*/