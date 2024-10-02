#include <iostream>

class Singleton {
public:
    // Static method to access the singleton instance
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;

    // Example method
    void showMessage() {
        std::cout << "Hello from Singleton!" << std::endl;
    }

private:
    // Private constructor to prevent instantiation
    Singleton() {}
};

int main() {
    // Get the singleton instance
    Singleton& singleton = Singleton::getInstance();

    // Use the singleton object
    singleton.showMessage();

    return 0;
}

/*
Trong ví dụ này, lớp Singleton có một phương thức static getInstance() để truy cập đến một thể hiện duy nhất của lớp Singleton. 
Constructor của lớp Singleton được đặt là private để ngăn việc tạo ra các thể hiện mới từ bên ngoài lớp. 
Phương thức getInstance() tạo ra và trả về một thể hiện duy nhất của lớp Singleton thông qua biến static. 
Cuối cùng, trong hàm main(), chúng ta gọi phương thức showMessage() của Singleton để minh họa việc sử dụng singleton object.
*/