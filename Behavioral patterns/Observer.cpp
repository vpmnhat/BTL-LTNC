#include <iostream>
#include <vector>
#include <algorithm> // Thêm thư viện này để sử dụng hàm std::remove

// Observer class
class Observer {
public:
    virtual void update() = 0;
};

// Subject class
class Subject {
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        // detach observer from the list
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() {
        // notify all observers
        for (auto observer : observers) {
            observer->update();
        }
    }
};

// Concrete Observer class
class ConcreteObserver : public Observer {
public:
    void update() override {
        std::cout << "ConcreteObserver received update!\n";
    }
};

int main() {
    // Create subject and observer
    Subject subject;
    ConcreteObserver observer;

    // Attach observer to subject
    subject.attach(&observer);

    // Notify observers
    subject.notify();

    // Detach observer from subject
    subject.detach(&observer);

    return 0;
}


/*
Trong ví dụ này, Subject là lớp chứa dữ liệu và có khả năng gửi thông báo khi dữ liệu thay đổi. 
Observer là lớp trừu tượng đại diện cho các đối tượng quan sát dữ liệu từ Subject. 
Các lớp cụ thể như ConcreteObserver được triển khai để thực hiện hành vi cụ thể khi nhận được thông báo từ Subject.
*/