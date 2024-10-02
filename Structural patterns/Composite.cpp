#include <iostream>
#include <vector>
#include <memory>

// Interface thành phần
class Component {
public:
    virtual void operation() const = 0;
    virtual ~Component() = default;
};

// Lớp Leaf, đại diện cho các thành phần không có con
class Leaf : public Component {
public:
    void operation() const override {
        std::cout << "Leaf operation\n";
    }
};

// Lớp Composite, đại diện cho các thành phần có thể chứa các thành phần khác
class Composite : public Component {
public:
    void add(const std::shared_ptr<Component>& component) {
        children.push_back(component);
    }

    void operation() const override {
        std::cout << "Composite operation\n";
        for (const auto& child : children) {
            child->operation();
        }
    }

private:
    std::vector<std::shared_ptr<Component>> children;
};

int main() {
    std::shared_ptr<Component> leaf1 = std::make_shared<Leaf>();
    std::shared_ptr<Component> leaf2 = std::make_shared<Leaf>();
    std::shared_ptr<Composite> composite = std::make_shared<Composite>();

    composite->add(leaf1);
    composite->add(leaf2);

    composite->operation();

    return 0;
}

/*
Component: Interface thành phần định nghĩa một phương thức operation() mà tất cả các lớp con phải cài đặt.

Leaf: Lớp lá (Leaf) là một thành phần cụ thể không có con. Nó cài đặt phương thức operation() để thực hiện hành vi riêng của nó.

Composite: Lớp composite chứa một tập hợp các thành phần khác (có thể là Leaf hoặc Composite). Nó cài đặt phương thức operation() để thực hiện hành vi riêng của nó và gọi operation() trên tất cả các thành phần con.

main(): Chúng ta tạo một số đối tượng Leaf và một đối tượng Composite. Sau đó, chúng ta thêm các đối tượng Leaf vào đối tượng Composite và gọi operation() trên đối tượng Composite. Phương thức này sẽ gọi operation() trên tất cả các đối tượng con của nó.
*/