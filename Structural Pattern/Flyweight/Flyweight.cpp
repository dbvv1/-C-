#include <bits/stdc++.h>

namespace Flyweight
{
    // 享元接口 (Flyweight)
    class Flyweight
    {
    public:
        virtual void Operation(const std::string& externalState) const = 0;
        virtual ~Flyweight() = default;
    };

    // 具体享元类 (ConcreteFlyweight)
    class ConcreteFlyweight : public Flyweight
    {
    private:
        std::string intrinsicState; // 内部状态

    public:
        ConcreteFlyweight(const std::string& intrinsicState) : intrinsicState(intrinsicState) {}

        void Operation(const std::string& externalState) const override
        {
            std::cout << "Intrinsic State: " << intrinsicState << ", External State: " << externalState << std::endl;
        }
    };

    // 享元工厂 (FlyweightFactory)
    class FlyweightFactory
    {
    private:
        std::unordered_map<std::string, std::shared_ptr<Flyweight>> flyweights;

    public:
        std::shared_ptr<Flyweight> GetFlyweight(const std::string& key)
        {
            if (flyweights.find(key) == flyweights.end())
            {
                flyweights[key] = std::make_shared<ConcreteFlyweight>(key);
                std::cout << "Creating new flyweight for key: " << key << std::endl;
            }
            else
            {
                std::cout << "Reusing existing flyweight for key: " << key << std::endl;
            }
            return flyweights[key];
        }
    };

    void fun()
    {
        FlyweightFactory factory;

        std::shared_ptr<Flyweight> flyweight1 = factory.GetFlyweight("StateA");
        std::shared_ptr<Flyweight> flyweight2 = factory.GetFlyweight("StateB");
        std::shared_ptr<Flyweight> flyweight3 = factory.GetFlyweight("StateA"); // 应该重用已有的"StateA"享元

        flyweight1->Operation("External1");
        flyweight2->Operation("External2");
        flyweight3->Operation("External3");

    }
}
