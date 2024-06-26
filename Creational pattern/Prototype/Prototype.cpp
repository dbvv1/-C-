#include <bits/stdc++.h>

namespace Prototype
{
    class Prototype
    {
    public:
        virtual ~Prototype() = default;
        virtual Prototype* Clone() const = 0; // 纯虚函数，要求派生类实现
    };

    // 具体原型类
    class ConcretePrototype1 : public Prototype
    {
    private:
        std::string m_name;

    public:
        ConcretePrototype1(const std::string& name) : m_name(name) {}

        // 实现克隆方法
        Prototype* Clone() const override
        {
            return new ConcretePrototype1(*this);
        }

        void Show() const
        {
            std::cout << "ConcretePrototype1: " << m_name << std::endl;
        }
    };

    class ConcretePrototype2 : public Prototype
    {
    public:
        ConcretePrototype2(const std::string& type) : type_(type) {}

        // 实现克隆方法
        Prototype* Clone() const override
        {
            return new ConcretePrototype2(*this);
        }

        void Show() const
        {
            std::cout << "ConcretePrototype2: " << type_ << std::endl;
        }

    private:
        std::string type_;
    };

    void Client(Prototype* prototype)
    {
        Prototype* clonedPrototype = prototype->Clone();
        if (ConcretePrototype1* p = dynamic_cast<ConcretePrototype1*>(clonedPrototype))
        {
            p->Show();
        }
        else if (ConcretePrototype2* p = dynamic_cast<ConcretePrototype2*>(clonedPrototype))
        {
            p->Show();
        }
        delete clonedPrototype;
    }
}
