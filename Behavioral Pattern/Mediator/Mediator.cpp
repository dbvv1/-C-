#include <memory>
#include <bits/stdc++.h>

namespace Mediator
{
    // 抽象中介者类 (Mediator)
    class Mediator
    {
    public:
        virtual void Send(const std::string& message, const std::shared_ptr<class Colleague>& colleague) const = 0;
        virtual ~Mediator() = default;
    };

    // 抽象同事类 (Colleague)
    class Colleague
    {
    public:
        Colleague(std::shared_ptr<Mediator> mediator) : mediator(mediator) {}

        virtual void Send(const std::string& message) const
        {
            mediator->Send(message, std::make_shared<Colleague>(*this));
        }

        virtual void Receive(const std::string& message) const = 0;

    protected:
        std::shared_ptr<Mediator> mediator;
    };

    // 具体中介者类 (ConcreteMediator)
    class ConcreteMediator : public Mediator
    {
    public:
        void AddColleague(const std::shared_ptr<Colleague>& colleague)
        {
            colleagues.push_back(colleague);
        }

        void Send(const std::string& message, const std::shared_ptr<Colleague>& sender) const override
        {
            for (const auto& colleague : colleagues)
            {
                if (colleague != sender)
                {
                    colleague->Receive(message);
                }
            }
        }

    private:
        std::vector<std::shared_ptr<Colleague>> colleagues;
    };

    // 具体同事类 (ConcreteColleague1)
    class ConcreteColleague1 : public Colleague, public std::enable_shared_from_this<ConcreteColleague1>
    {
    public:
        using Colleague::Colleague;

        void Receive(const std::string& message) const override
        {
            std::cout << "ConcreteColleague1 received message: " << message << std::endl;
        }
    };

    // 具体同事类 (ConcreteColleague2)
    class ConcreteColleague2 : public Colleague, public std::enable_shared_from_this<ConcreteColleague2>
    {
    public:
        using Colleague::Colleague;

        void Receive(const std::string& message) const override
        {
            std::cout << "ConcreteColleague2 received message: " << message << std::endl;
        }
    };

    void fun()
    {
        std::shared_ptr<ConcreteMediator> mediator = std::make_shared<ConcreteMediator>();

        std::shared_ptr<ConcreteColleague1> colleague1 = std::make_shared<ConcreteColleague1>(mediator);
        std::shared_ptr<ConcreteColleague2> colleague2 = std::make_shared<ConcreteColleague2>(mediator);

        mediator->AddColleague(colleague1);
        mediator->AddColleague(colleague2);

        colleague1->Send("Hello from Colleague1!");
        colleague2->Send("Hello from Colleague2!");
    }
}
