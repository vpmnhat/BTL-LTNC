#include <iostream>
#include <memory>

// Định nghĩa giao diện chung cho đối tượng gốc và proxy
class Subject {
public:
    virtual void request() const = 0;
};

// Đối tượng gốc (RealSubject)
class RealSubject : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject: Handling request." << std::endl;
    }
};

// Đối tượng proxy
class Proxy : public Subject {
private:
    std::unique_ptr<RealSubject> real_subject;

    bool checkAccess() const {
        // Kiểm tra quyền truy cập trước khi gọi phương thức của RealSubject
        std::cout << "Proxy: Checking access prior to firing a real request." << std::endl;
        return true;
    }

    void logAccess() const {
        // Ghi lại thông tin truy cập sau khi gọi phương thức của RealSubject
        std::cout << "Proxy: Logging the time of request." << std::endl;
    }

public:
    Proxy() : real_subject(std::make_unique<RealSubject>()) {}

    void request() const override {
        if (this->checkAccess()) {
            this->real_subject->request();
            this->logAccess();
        }
    }
};

void clientCode(const Subject& subject) {
    // Code của client hoạt động với tất cả các đối tượng thông qua giao diện Subject
    subject.request();
}

int main() {
    std::cout << "Client: Executing the client code with a real subject:" << std::endl;
    RealSubject real_subject;
    clientCode(real_subject);

    std::cout << "\nClient: Executing the same client code with a proxy:" << std::endl;
    Proxy proxy;
    clientCode(proxy);

    return 0;
}

/*
Trong ví dụ trên:

Subject: Là giao diện chung cho RealSubject và Proxy. Nó khai báo phương thức request() mà cả hai lớp đều phải triển khai.
RealSubject: Là lớp thực hiện công việc thực sự khi phương thức request() được gọi.
Proxy: Là lớp đại diện cho RealSubject. Nó kiểm soát truy cập đến RealSubject, có thể kiểm tra quyền truy cập và ghi lại thông tin truy cập.

Phương thức clientCode nhận một tham chiếu tới đối tượng kiểu Subject, cho phép nó hoạt động với cả RealSubject và Proxy.

Khi chạy chương trình, bạn sẽ thấy rằng khi gọi phương thức thông qua Proxy, nó sẽ kiểm tra quyền truy cập và ghi lại thông tin trước và sau khi gọi phương thức của RealSubject.
*/