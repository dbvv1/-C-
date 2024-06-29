#include <bits/stdc++.h>

namespace ChainOfResponsibility
{
    // 抽象事件处理者 (GameEventHandler)
    class GameEventHandler
    {
    public:
        virtual ~GameEventHandler() = default;

        void SetNext(std::shared_ptr<GameEventHandler> nextHandler)
        {
            next = nextHandler;
        }

        void HandleEvent(const std::string& event)
        {
            if (CanHandleEvent(event))
            {
                ProcessEvent(event);
            }
            else if (next)
            {
                next->HandleEvent(event);
            }
            else
            {
                std::cout << "No handler could handle the event: " << event << std::endl;
            }
        }

    protected:
        virtual bool CanHandleEvent(const std::string& event) const = 0;
        virtual void ProcessEvent(const std::string& event) const = 0;

    private:
        std::shared_ptr<GameEventHandler> next = nullptr;
    };

    // 具体事件处理者 - 移动事件处理者 (MoveEventHandler)
    class MoveEventHandler : public GameEventHandler
    {
    protected:
        bool CanHandleEvent(const std::string& event) const override
        {
            return event == "move";
        }

        void ProcessEvent(const std::string& event) const override
        {
            std::cout << "MoveEventHandler handled the event: " << event << std::endl;
        }
    };

    // 具体事件处理者 - 攻击事件处理者 (AttackEventHandler)
    class AttackEventHandler : public GameEventHandler
    {
    protected:
        bool CanHandleEvent(const std::string& event) const override
        {
            return event == "attack";
        }

        void ProcessEvent(const std::string& event) const override
        {
            std::cout << "AttackEventHandler handled the event: " << event << std::endl;
        }
    };

    // 具体事件处理者 - 防御事件处理者 (DefendEventHandler)
    class DefendEventHandler : public GameEventHandler
    {
    protected:
        bool CanHandleEvent(const std::string& event) const override
        {
            return event == "defend";
        }

        void ProcessEvent(const std::string& event) const override
        {
            std::cout << "DefendEventHandler handled the event: " << event << std::endl;
        }
    };

    void fun()
    {
        std::shared_ptr<GameEventHandler> moveHandler = std::make_shared<MoveEventHandler>();
        std::shared_ptr<GameEventHandler> attackHandler = std::make_shared<AttackEventHandler>();
        std::shared_ptr<GameEventHandler> defendHandler = std::make_shared<DefendEventHandler>();

        moveHandler->SetNext(attackHandler);
        attackHandler->SetNext(defendHandler);

        std::vector<std::string> events = {"move", "attack", "defend", "jump"};

        for (const auto& event : events)
        {
            moveHandler->HandleEvent(event);
        }
    }
}
