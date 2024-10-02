#include <iostream>
#include <vector>

// Forward declarations
class ConcreteElementA;
class ConcreteElementB;

// Visitor interface
class Visitor {
public:
    virtual void visit(ConcreteElementA* element) = 0;
    virtual void visit(ConcreteElementB* element) = 0;
};

// Element interface
class Element {
public:
    virtual void accept(Visitor* visitor) = 0;
};

// Concrete Element A
class ConcreteElementA : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visit(this);
    }

    void operationA() {
        std::cout << "Operation A on ConcreteElementA\n";
    }
};

// Concrete Element B
class ConcreteElementB : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visit(this);
    }

    void operationB() {
        std::cout << "Operation B on ConcreteElementB\n";
    }
};

// Concrete Visitor
class ConcreteVisitor : public Visitor {
public:
    void visit(ConcreteElementA* element) override {
        element->operationA();
    }

    void visit(ConcreteElementB* element) override {
        element->operationB();
    }
};

int main() {
    std::vector<Element*> elements = {new ConcreteElementA(), new ConcreteElementB()};
    ConcreteVisitor visitor;

    // Perform operations on elements using the visitor
    for (Element* element : elements) {
        element->accept(&visitor);
    }

    // Clean up
    for (Element* element : elements) {
        delete element;
    }

    return 0;
}

/*
Trong ví dụ này, chúng ta có hai lớp ConcreteElementA và ConcreteElementB kế thừa từ lớp Element. 
Mỗi lớp này đều cung cấp một phương thức accept để cho phép một đối tượng Visitor thăm thú và thực thi các hành động phù hợp.

Visitor là một lớp abstract với các phương thức visit() tương ứng với mỗi loại ConcreteElement. 
ConcreteVisitor triển khai các phương thức visit() để thực hiện các hành động cụ thể trên từng loại ConcreteElement.

Trong hàm main(), chúng ta tạo ra một vector các đối tượng ConcreteElement và sử dụng ConcreteVisitor để thăm thú từng đối tượng và thực hiện các hành động tương ứng.
*/