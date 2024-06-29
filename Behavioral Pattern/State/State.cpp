#include <bits/stdc++.h>

namespace State
{
    // 抽象状态类 (State)
    class State
    {
    public:
        virtual ~State() = default;
        virtual void Handle() = 0;
    };

    // 具体状态类A (ConcreteStateA)
    class ConcreteStateA : public State
    {
    public:
        void Handle() override
        {
            std::cout << "Handling state A" << std::endl;
        }
    };

    // 具体状态类B (ConcreteStateB)
    class ConcreteStateB : public State
    {
    public:
        void Handle() override
        {
            std::cout << "Handling state B" << std::endl;
        }
    };

    // 环境类 (Context)
    class Context
    {
    public:
        Context(std::shared_ptr<State> state) : state_(state) {}

        void SetState(std::shared_ptr<State> state)
        {
            state_ = state;
        }

        void Request()
        {
            state_->Handle();
        }

    private:
        std::shared_ptr<State> state_;
    };

    void fun()
    {
        std::shared_ptr<Context> context = std::make_shared<Context>(std::make_shared<ConcreteStateA>());
        context->Request();

        context->SetState(std::make_shared<ConcreteStateB>());
        context->Request();
    }
}
