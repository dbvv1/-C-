#include<bits/stdc++.h>

// 先自己写  工厂方法模式
namespace FactoryMethod
{
    // 抽象产品类
    class IProduct
    {
    public:
        virtual void Use() const = 0;
        virtual ~IProduct() = default;
    };

    // 具体产品类
    class ConcreteProductA : public IProduct
    {
    public:
        virtual void Use() const override
        {
            std::cout << "使用具体产品 A " << std::endl;
        }
    };

    class ConcreteProductB : public IProduct
    {
    public:
        virtual void Use() const override
        {
            std::cout << "使用具体产品 B " << std::endl;
        }
    };

    // 抽象工厂类
    class IFactory
    {
    public:
        virtual IProduct* Create() = 0;
        virtual ~IFactory() = default;
    };

    // 具体工厂类
    class ConcreteFactoryA : public IFactory
    {
    public:
        virtual IProduct* Create() override
        {
            return new ConcreteProductA();
        }
    };

    class ConcreteFactoryB : public IFactory
    {
    public:
        virtual IProduct* Create() override
        {
            return new ConcreteProductA();
        }
    };

    void fun()
    {
        // 使用具体工厂类A
        IFactory* factoryA = new ConcreteFactoryA();
        IProduct* productA = factoryA->Create();
        productA->Use();

        // 使用具体工厂类B
        IFactory* factoryB = new ConcreteFactoryB();
        IProduct* productB = factoryB->Create();
        productB->Use();

        // 清理资源
        delete productA;
        delete factoryA;
        delete productB;
        delete factoryB;
    }
}
