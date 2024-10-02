#include <iostream>
#include <string>
#include <vector>

// Originator: Object whose state needs to be saved
class Originator {
private:
    std::string state;

public:
    void setState(const std::string& newState) {
        state = newState;
    }

    std::string getState() const {
        return state;
    }

    // Save state to Memento
    Memento saveToMemento() {
        return Memento(state);
    }

    // Restore state from Memento
    void restoreFromMemento(const Memento& m) {
        state = m.getState();
    }
};

// Memento: Stores internal state of the Originator object
class Memento {
private:
    std::string state;

public:
    Memento(const std::string& state) : state(state) {}

    std::string getState() const {
        return state;
    }
};

// Caretaker: Manages Memento objects
class Caretaker {
private:
    std::vector<Memento> mementos;

public:
    void addMemento(const Memento& m) {
        mementos.push_back(m);
    }

    Memento getMemento(int index) const {
        return mementos[index];
    }
};

int main() {
    Originator originator;
    Caretaker caretaker;

    // Set initial state and save it
    originator.setState("State 1");
    caretaker.addMemento(originator.saveToMemento());

    // Change state and save it
    originator.setState("State 2");
    caretaker.addMemento(originator.saveToMemento());

    // Restore previous state
    originator.restoreFromMemento(caretaker.getMemento(0));
    std::cout << "Current State: " << originator.getState() << std::endl;

    return 0;
}

/*
Trong ví dụ này, Originator là đối tượng mà trạng thái của nó cần được lưu trữ và phục hồi. 
Memento là lớp lưu trữ trạng thái của Originator. 
Caretaker quản lý các đối tượng Memento.
*/