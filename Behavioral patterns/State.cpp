#include <iostream>

// Abstract base class for states
class State {
public:
    virtual void handle() = 0;
};

// Concrete state classes
class StateA : public State {
public:
    void handle() override {
        std::cout << "Handling State A\n";
    }
};

class StateB : public State {
public:
    void handle() override {
        std::cout << "Handling State B\n";
    }
};

// Context class
class Context {
private:
    State *currentState;

public:
    Context() : currentState(nullptr) {}

    void setState(State *state) {
        currentState = state;
    }

    void request() {
        if (currentState)
            currentState->handle();
        else
            std::cout << "No state set\n";
    }
};

int main() {
    // Create context and states
    Context context;
    StateA stateA;
    StateB stateB;

    // Set initial state
    context.setState(&stateA);
    context.request(); // Output: Handling State A

    // Change state
    context.setState(&stateB);
    context.request(); // Output: Handling State B

    return 0;
}

/*
Trong ví dụ này, State là một lớp abstract đại diện cho một trạng thái, và StateA, StateB là các lớp cụ thể của trạng thái đó. 
Context là lớp mà trạng thái được áp dụng. 
Khi gọi request() trên Context, nó sẽ gọi phương thức handle() của trạng thái hiện tại.
*/