#include <iostream>
#include <vector>
#include <memory>

// Command interface
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

// Receiver class
class Light {
public:
    void turnOn() {
        std::cout << "Light is on" << std::endl;
    }

    void turnOff() {
        std::cout << "Light is off" << std::endl;
    }
};

// Concrete Command classes
class TurnOnCommand : public Command {
public:
    TurnOnCommand(Light& light) : light(light) {}
    void execute() override {
        light.turnOn();
    }

private:
    Light& light;
};

class TurnOffCommand : public Command {
public:
    TurnOffCommand(Light& light) : light(light) {}
    void execute() override {
        light.turnOff();
    }

private:
    Light& light;
};

// Invoker class
class RemoteControl {
public:
    void setCommand(std::shared_ptr<Command> command) {
        this->command = command;
    }

    void pressButton() {
        command->execute();
    }

private:
    std::shared_ptr<Command> command;
};

int main() {
    Light light;
    RemoteControl remote;

    std::shared_ptr<Command> turnOnCmd = std::make_shared<TurnOnCommand>(light);
    std::shared_ptr<Command> turnOffCmd = std::make_shared<TurnOffCommand>(light);

    remote.setCommand(turnOnCmd);
    remote.pressButton(); // Output: Light is on

    remote.setCommand(turnOffCmd);
    remote.pressButton(); // Output: Light is off

    return 0;
}

/*
Command: Là một interface định nghĩa một phương thức execute.
Light: Là receiver, là đối tượng thực hiện các hành động cụ thể.
TurnOnCommand và TurnOffCommand: Là các Concrete Command, mỗi Command đại diện cho một hành động cụ thể (mở hoặc tắt đèn).
RemoteControl: Là invoker, nó giữ một Command và khi gọi pressButton, nó gọi execute trên Command hiện tại.
*/