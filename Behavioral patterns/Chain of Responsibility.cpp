#include <iostream>
#include <string>

// Base Handler class
class Handler {
public:
    virtual ~Handler() {}
    virtual void handleRequest(const std::string& request) = 0;
    void setNext(Handler* next) { nextHandler = next; }
protected:
    Handler* nextHandler;
};

// Concrete Handlers
class ConcreteHandler1 : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "Request1") {
            std::cout << "ConcreteHandler1 handling Request1" << std::endl;
        } else if (nextHandler) {
            nextHandler->handleRequest(request);
        }
    }
};

class ConcreteHandler2 : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "Request2") {
            std::cout << "ConcreteHandler2 handling Request2" << std::endl;
        } else if (nextHandler) {
            nextHandler->handleRequest(request);
        }
    }
};

class ConcreteHandler3 : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "Request3") {
            std::cout << "ConcreteHandler3 handling Request3" << std::endl;
        } else if (nextHandler) {
            nextHandler->handleRequest(request);
        }
    }
};

int main() {
    // Creating the chain
    Handler* handler1 = new ConcreteHandler1();
    Handler* handler2 = new ConcreteHandler2();
    Handler* handler3 = new ConcreteHandler3();
    
    handler1->setNext(handler2);
    handler2->setNext(handler3);

    // Send requests
    handler1->handleRequest("Request1");
    handler1->handleRequest("Request2");
    handler1->handleRequest("Request3");
    handler1->handleRequest("InvalidRequest");

    delete handler1;
    delete handler2;
    delete handler3;

    return 0;
}

/*
Trong ví dụ này, Handler là một lớp cơ sở với một phương thức ảo handleRequest(), các lớp ConcreteHandler triển khai phương thức này. 
Mỗi handler có thể xử lý một loại request cụ thể, nếu không thể xử lý, nó sẽ chuyển request đó cho handler tiếp theo trong chuỗi. 
Trong main(), một chuỗi các handler được tạo và một số request được gửi thông qua chuỗi này.
*/