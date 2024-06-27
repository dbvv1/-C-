#include <bits/stdc++.h>

namespace Bridge
{
    class Implementor
    {
    public:
        virtual void OperationImpl() const = 0;
        virtual ~Implementor() = default;
    };

    // 抽象部分接口 (Abstraction)
    class Abstraction
    {
    protected:
        std::shared_ptr<Implementor> implementor;

    public:
        Abstraction(std::shared_ptr<Implementor> impl) : implementor(impl) {}
        virtual void Operation() const = 0;
        virtual ~Abstraction() = default;
    };

    // 具体实现类 (ConcreteImplementor)
    class ConcreteImplementorA : public Implementor
    {
    public:
        void OperationImpl() const override
        {
            // 实现具体逻辑 A
        }
    };

    class ConcreteImplementorB : public Implementor
    {
    public:
        void OperationImpl() const override
        {
            // 实现具体逻辑 B
        }
    };

    // 具体抽象部分 (RefinedAbstraction)
    class RefinedAbstraction : public Abstraction
    {
    public:
        RefinedAbstraction(std::shared_ptr<Implementor> impl) : Abstraction(impl) {}

        void Operation() const override
        {
            implementor->OperationImpl(); // 调用实现部分的具体方法
        }
    };
}
