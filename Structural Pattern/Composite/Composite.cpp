#include <bits/stdc++.h>

namespace Composite
{
    // 抽象组件类 (Component)
    class Component
    {
    public:
        virtual void Operation() const = 0;

        virtual void Add(std::shared_ptr<Component> component)
        {
            throw std::runtime_error("Add not supported");
        }

        virtual void Remove(std::shared_ptr<Component> component)
        {
            throw std::runtime_error("Remove not supported");
        }

        virtual std::shared_ptr<Component> GetChild(int index) const
        {
            throw std::runtime_error("GetChild not supported");
        }

        virtual ~Component() = default;
    };

    // 叶子节点类 (Leaf)
    class Leaf : public Component
    {
    public:
        void Operation() const override
        {
            std::cout << "Leaf Operation" << std::endl;
        }
    };

    // 组合节点类 (Composite)
    class Composite : public Component
    {
    private:
        std::vector<std::shared_ptr<Component>> children;

    public:
        void Operation() const override
        {
            std::cout << "Composite Operation" << std::endl;
            for (const auto& child : children)
            {
                child->Operation();
            }
        }

        void Add(std::shared_ptr<Component> component) override
        {
            children.push_back(component);
        }

        void Remove(std::shared_ptr<Component> component) override
        {
            children.erase(std::remove(children.begin(), children.end(), component), children.end());
        }

        std::shared_ptr<Component> GetChild(int index) const override
        {
            if (index < 0 || index >= children.size())
            {
                throw std::out_of_range("Index out of range");
            }
            return children[index];
        }
    };

    void fun()
    {
        std::shared_ptr<Component> leaf1 = std::make_shared<Leaf>();
        std::shared_ptr<Component> leaf2 = std::make_shared<Leaf>();
        std::shared_ptr<Component> composite1 = std::make_shared<Composite>();
        std::shared_ptr<Component> composite2 = std::make_shared<Composite>();

        composite1->Add(leaf1);
        composite1->Add(leaf2);

        composite2->Add(composite1);
        composite2->Add(std::make_shared<Leaf>());

        std::cout << "Composite2 Operation:" << std::endl;
        composite2->Operation();
    }
}
