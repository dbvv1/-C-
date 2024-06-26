#include<bits/stdc++.h>
namespace AbstractFactory
{
    // 抽象产品类A
    class AbstractProductA {
    public:
        virtual void Use() const = 0;
        virtual ~AbstractProductA() = default; 
    };

    // 抽象产品类B
    class AbstractProductB {
    public:
        virtual void Use() const = 0; 
        virtual ~AbstractProductB() = default;
    };

    // 具体产品类A1
    class ConcreteProductA1 : public AbstractProductA {
    public:
        void Use() const override {
            std::cout << "Using ConcreteProductA1" << std::endl;
        }
    };

    // 具体产品类B1
    class ConcreteProductB1 : public AbstractProductB {
    public:
        void Use() const override {
            std::cout << "Using ConcreteProductB1" << std::endl;
        }
    };

    // 具体产品类A2
    class ConcreteProductA2 : public AbstractProductA {
    public:
        void Use() const override {
            std::cout << "Using ConcreteProductA2" << std::endl;
        }
    };

    // 具体产品类B2
    class ConcreteProductB2 : public AbstractProductB {
    public:
        void Use() const override {
            std::cout << "Using ConcreteProductB2" << std::endl;
        }
    };

    // 抽象工厂类
    class AbstractFactory {
    public:
        virtual AbstractProductA* CreateProductA() const = 0; 
        virtual AbstractProductB* CreateProductB() const = 0; 
        virtual ~AbstractFactory() = default; 
    };

    // 具体工厂类1
    class ConcreteFactory1 : public AbstractFactory {
    public:
        AbstractProductA* CreateProductA() const override {
            return new ConcreteProductA1();
        }

        AbstractProductB* CreateProductB() const override {
            return new ConcreteProductB1();
        }
    };

    // 具体工厂类2
    class ConcreteFactory2 : public AbstractFactory {
    public:
        AbstractProductA* CreateProductA() const override {
            return new ConcreteProductA2();
        }

        AbstractProductB* CreateProductB() const override {
            return new ConcreteProductB2();
        }
    };

    void Fun() {
        // 使用具体工厂1
        AbstractFactory* factory1 = new ConcreteFactory1();
        AbstractProductA* productA1 = factory1->CreateProductA();
        AbstractProductB* productB1 = factory1->CreateProductB();
        productA1->Use(); // 输出：Using ConcreteProductA1
        productB1->Use(); // 输出：Using ConcreteProductB1

        // 使用具体工厂2
        AbstractFactory* factory2 = new ConcreteFactory2();
        AbstractProductA* productA2 = factory2->CreateProductA();
        AbstractProductB* productB2 = factory2->CreateProductB();
        productA2->Use(); // 输出：Using ConcreteProductA2
        productB2->Use(); // 输出：Using ConcreteProductB2

        // 清理资源
        delete productA1;
        delete productB1;
        delete factory1;
        delete productA2;
        delete productB2;
        delete factory2;
    }
}
