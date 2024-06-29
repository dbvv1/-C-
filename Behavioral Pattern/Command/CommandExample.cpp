#include <bits/stdc++.h>

namespace CommandExample
{
    // 抽象命令类 (Command)
    class Command
    {
    public:
        virtual ~Command() = default;
        virtual void Execute() = 0;
        virtual void Undo() = 0;
    };

    // 接收者类 (GameActor)
    class GameActor
    {
    public:
        void Move()
        {
            std::cout << "GameActor: Moving." << std::endl;
        }

        void Attack()
        {
            std::cout << "GameActor: Attacking." << std::endl;
        }

        void Defend()
        {
            std::cout << "GameActor: Defending." << std::endl;
        }

        void RevertMove()
        {
            std::cout << "GameActor: Reverting move." << std::endl;
        }

        void RevertAttack()
        {
            std::cout << "GameActor: Reverting attack." << std::endl;
        }

        void RevertDefend()
        {
            std::cout << "GameActor: Reverting defend." << std::endl;
        }
    };

    // 具体命令类 - 移动命令 (MoveCommand)
    class MoveCommand : public Command
    {
    public:
        MoveCommand(std::shared_ptr<GameActor> actor) : actor(actor) {}

        void Execute() override
        {
            actor->Move();
        }

        void Undo() override
        {
            actor->RevertMove();
        }

    private:
        std::shared_ptr<GameActor> actor;
    };

    // 具体命令类 - 攻击命令 (AttackCommand)
    class AttackCommand : public Command
    {
    public:
        AttackCommand(std::shared_ptr<GameActor> actor) : actor(actor) {}

        void Execute() override
        {
            actor->Attack();
        }

        void Undo() override
        {
            actor->RevertAttack();
        }

    private:
        std::shared_ptr<GameActor> actor;
    };

    // 具体命令类 - 防御命令 (DefendCommand)
    class DefendCommand : public Command
    {
    public:
        DefendCommand(std::shared_ptr<GameActor> actor) : actor(actor) {}

        void Execute() override
        {
            actor->Defend();
        }

        void Undo() override
        {
            actor->RevertDefend();
        }

    private:
        std::shared_ptr<GameActor> actor;
    };

    // 调用者类 (Invoker)
    class Invoker
    {
    public:
        void ExecuteCommand(std::shared_ptr<Command> command)
        {
            command->Execute();
            commandHistory.push(command);
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
        std::stack<std::shared_ptr<Command>> commandHistory;
    };

    void fun()
    {
        std::shared_ptr<GameActor> actor = std::make_shared<GameActor>();
        std::shared_ptr<Command> moveCommand = std::make_shared<MoveCommand>(actor);
        std::shared_ptr<Command> attackCommand = std::make_shared<AttackCommand>(actor);
        std::shared_ptr<Command> defendCommand = std::make_shared<DefendCommand>(actor);
        Invoker invoker;

        invoker.ExecuteCommand(moveCommand);
        invoker.ExecuteCommand(attackCommand);
        invoker.ExecuteCommand(defendCommand);

        std::cout << "Undoing last command..." << std::endl;
        invoker.UndoCommand();
    }
}
