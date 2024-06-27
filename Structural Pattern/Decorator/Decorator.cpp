#include <bits/stdc++.h>

namespace Decorator
{
    // 抽象组件类 (Component)
    class Component
    {
    public:
        virtual void Operation() const = 0;
        virtual ~Component() = default;
    };

    // 具体组件类 (ConcreteComponent)
    class ConcreteComponent : public Component
    {
    public:
        void Operation() const override
        {
            std::cout << "ConcreteComponent Operation" << std::endl;
        }
    };

    // 装饰抽象类 (Decorator)
    class Decorator : public Component
    {
    protected:
        std::shared_ptr<Component> component;

    public:
        Decorator(std::shared_ptr<Component> comp) : component(comp) {}

        void Operation() const override
        {
            if (component)
            {
                component->Operation();
            }
        }
    };

    // 具体装饰类A (ConcreteDecoratorA)
    class ConcreteDecoratorA : public Decorator
    {
    public:
        ConcreteDecoratorA(std::shared_ptr<Component> comp) : Decorator(comp) {}

        void Operation() const override
        {
            Decorator::Operation();
            AdditionalBehavior();
        }

    private:
        void AdditionalBehavior() const
        {
            std::cout << "ConcreteDecoratorA Additional Behavior" << std::endl;
        }
    };

    // 具体装饰类B (ConcreteDecoratorB)
    class ConcreteDecoratorB : public Decorator
    {
    public:
        ConcreteDecoratorB(std::shared_ptr<Component> comp) : Decorator(comp) {}

        void Operation() const override
        {
            Decorator::Operation();
            AdditionalBehavior();
        }

    private:
        void AdditionalBehavior() const
        {
            std::cout << "ConcreteDecoratorB Additional Behavior" << std::endl;
        }
    };

    void fun()
    {
        std::shared_ptr<Component> component = std::make_shared<ConcreteComponent>();
        std::shared_ptr<Component> decoratorA = std::make_shared<ConcreteDecoratorA>(component);
        std::shared_ptr<Component> decoratorB = std::make_shared<ConcreteDecoratorB>(decoratorA);

        decoratorB->Operation(); // 执行ConcreteComponent和两个装饰者的操作

    }
}
