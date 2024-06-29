#include <bits/stdc++.h>

namespace TemplateMethod
{
    // 抽象类 (AbstractClass)
    class AbstractClass
    {
    public:
        // 模板方法定义了算法的骨架
        void TemplateMethod() const
        {
            BaseOperation1();
            RequiredOperation1();
            BaseOperation2();
            Hook1();
            RequiredOperation2();
            BaseOperation3();
            Hook2();
        }

        // 基本操作实现
        void BaseOperation1() const
        {
            std::cout << "AbstractClass says: I am doing the bulk of the work" << std::endl;
        }

        void BaseOperation2() const
        {
            std::cout << "AbstractClass says: But I let subclasses override some operations" << std::endl;
        }

        void BaseOperation3() const
        {
            std::cout << "AbstractClass says: But I am doing the bulk of the work anyway" << std::endl;
        }

        // 子类必须实现的基本操作 (抽象方法)
        virtual void RequiredOperation1() const = 0;
        virtual void RequiredOperation2() const = 0;

        // 钩子是可选的
        virtual void Hook1() const {}
        virtual void Hook2() const {}
    };

    // 具体类 (ConcreteClass)
    class ConcreteClass : public AbstractClass
    {
    protected:
        void RequiredOperation1() const override
        {
            std::cout << "ConcreteClass says: Implemented Operation1" << std::endl;
        }

        void RequiredOperation2() const override
        {
            std::cout << "ConcreteClass says: Implemented Operation2" << std::endl;
        }

        void Hook1() const override
        {
            std::cout << "ConcreteClass says: Overridden Hook1" << std::endl;
        }
    };
}
