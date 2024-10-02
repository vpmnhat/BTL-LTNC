#include <iostream>
#include <memory>

// Interface Implementor
class DrawingAPI {
public:
    virtual void drawCircle(double x, double y, double radius) = 0;
    virtual ~DrawingAPI() = default;
};

// Concrete Implementor A
class DrawingAPI1 : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) override {
        std::cout << "API1.circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }
};

// Concrete Implementor B
class DrawingAPI2 : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) override {
        std::cout << "API2.circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }
};

// Abstraction
class Shape {
public:
    virtual void draw() = 0;
    virtual void resizeByPercentage(double pct) = 0;
    virtual ~Shape() = default;
};

// Refined Abstraction
class CircleShape : public Shape {
public:
    CircleShape(double x, double y, double radius, std::shared_ptr<DrawingAPI> drawingAPI)
        : x_(x), y_(y), radius_(radius), drawingAPI_(drawingAPI) {}

    void draw() override {
        drawingAPI_->drawCircle(x_, y_, radius_);
    }

    void resizeByPercentage(double pct) override {
        radius_ *= (1.0 + pct / 100.0);
    }

private:
    double x_, y_, radius_;
    std::shared_ptr<DrawingAPI> drawingAPI_;
};

int main() {
    std::shared_ptr<DrawingAPI> api1 = std::make_shared<DrawingAPI1>();
    std::shared_ptr<DrawingAPI> api2 = std::make_shared<DrawingAPI2>();

    CircleShape circle1(1, 2, 3, api1);
    CircleShape circle2(5, 7, 11, api2);

    circle1.draw();
    circle2.draw();

    circle1.resizeByPercentage(10);
    circle1.draw();

    return 0;
}

/*
Trong ví dụ này:

DrawingAPI là giao diện Implementor với phương thức drawCircle().
DrawingAPI1 và DrawingAPI2 là các lớp cụ thể (ConcreteImplementor) triển khai giao diện DrawingAPI.
Shape là lớp trừu tượng (Abstraction) với các phương thức ảo draw() và resizeByPercentage().
CircleShape là lớp mở rộng (RefinedAbstraction) của Shape, sử dụng một đối tượng DrawingAPI để thực hiện việc vẽ hình tròn.

Nhờ vậy, chúng ta có thể dễ dàng thay đổi cách thức vẽ (chọn DrawingAPI1 hoặc DrawingAPI2) mà không cần thay đổi lớp CircleShape.
*/