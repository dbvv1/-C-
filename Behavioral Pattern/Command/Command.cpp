#include <bits/stdc++.h>

namespace Command
{
    // 抽象命令类 (Command)
    class Command
    {
    public:
        virtual ~Command() = default;
        virtual void Execute() = 0;
        virtual void Undo() = 0;
    };

    // 接收者类 (Receiver)
    class Receiver
    {
    public:
        void Action()
        {
            std::cout << "Receiver: Performing action." << std::endl;
        }

        void RevertAction()
        {
            std::cout << "Receiver: Reverting action." << std::endl;
        }
    };

    // 具体命令类 (ConcreteCommand)
    class ConcreteCommand : public Command
    {
    public:
        ConcreteCommand(std::shared_ptr<Receiver> receiver) : receiver(receiver) {}

        void Execute() override
        {
            receiver->Action();
        }

        void Undo() override
        {
            receiver->RevertAction();
        }

    private:
        std::shared_ptr<Receiver> receiver;
    };

    // 调用者类 (Invoker)
    class Invoker
    {
    public:
        void SetCommand(std::shared_ptr<Command> command)
        {
            this->command = command;
        }

        void ExecuteCommand()
        {
            if (command)
            {
                command->Execute();
                commandHistory.push(command);
            }
        }

        void UndoCommand()
        {
            if (!commandHistory.empty())
            {
                commandHistory.top()->Undo();
                commandHistory.pop();
            }
        }

    private:
        std::shared_ptr<Command> command;
        std::stack<std::shared_ptr<Command>> commandHistory;
    };

    void fun()
    {
        std::shared_ptr<Receiver> receiver = std::make_shared<Receiver>();
        std::shared_ptr<Command> command = std::make_shared<ConcreteCommand>(receiver);
        Invoker invoker;

        invoker.SetCommand(command);
        invoker.ExecuteCommand();
        invoker.UndoCommand();

    }
}
