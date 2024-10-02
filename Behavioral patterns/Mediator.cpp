#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Mediator;

// Abstract Colleague
class Colleague {
public:
    virtual ~Colleague() {}
    virtual void sendMessage(const string& message) const = 0;
    virtual void receiveMessage(const string& message) const = 0;
protected:
    Mediator* mediator_;
};

// Concrete Colleague
class ConcreteColleague : public Colleague {
public:
    ConcreteColleague(Mediator* mediator, const string& name) : name_(name) {
        mediator_ = mediator;
    }
    void sendMessage(const string& message) const override {
        mediator_->sendMessage(message, this);
    }
    void receiveMessage(const string& message) const override {
        cout << name_ << " received: " << message << endl;
    }
private:
    string name_;
};

// Mediator
class Mediator {
public:
    virtual ~Mediator() {}
    virtual void sendMessage(const string& message, const Colleague* sender) const = 0;
protected:
    vector<Colleague*> colleagues_;
};

// Concrete Mediator
class ConcreteMediator : public Mediator {
public:
    void addColleague(Colleague* colleague) {
        colleagues_.push_back(colleague);
    }
    void sendMessage(const string& message, const Colleague* sender) const override {
        for (const auto& colleague : colleagues_) {
            if (colleague != sender) {
                colleague->receiveMessage(message);
            }
        }
    }
};

int main() {
    ConcreteMediator mediator;

    ConcreteColleague colleague1(&mediator, "Colleague 1");
    ConcreteColleague colleague2(&mediator, "Colleague 2");
    ConcreteColleague colleague3(&mediator, "Colleague 3");

    mediator.addColleague(&colleague1);
    mediator.addColleague(&colleague2);
    mediator.addColleague(&colleague3);

    colleague1.sendMessage("Hello from Colleague 1!");
    colleague2.sendMessage("Hi from Colleague 2!");
    colleague3.sendMessage("Greetings from Colleague 3!");

    return 0;
}

/*
Trong ví dụ này, chúng ta có một lớp Mediator và các lớp Colleague tương ứng. 
Lớp ConcreteMediator triển khai cách thức giao tiếp giữa các đồng nghiệp, trong khi ConcreteColleague thực hiện gửi và nhận thông điệp thông qua Mediator. 
Khi một Colleague gửi một thông điệp, nó sẽ chuyển nó cho Mediator, và Mediator sẽ chuyển nó đến tất cả các Colleague khác ngoại trừ người gửi.
*/