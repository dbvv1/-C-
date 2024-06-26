#include<bits/stdc++.h>

namespace Prototype
{
    // 抽象原型类
    class Monster {
    public:
        virtual ~Monster() = default;
        virtual Monster* Clone() const = 0; // 纯虚函数，要求派生类实现
        virtual void Show() const = 0;      // 纯虚函数，要求派生类实现

    protected:
        std::string name_;
        int health_;
    };

    // 具体原型类：Dragon
    class Dragon : public Monster {
    public:
        Dragon(const std::string& name, int health) {
            name_ = name;
            health_ = health;
        }

        Monster* Clone() const override {
            return new Dragon(*this);
        }

        void Show() const override {
            std::cout << "Dragon: " << name_ << ", Health: " << health_ << std::endl;
        }
    };

    // 具体原型类：Goblin
    class Goblin : public Monster {
    public:
        Goblin(const std::string& name, int health) {
            name_ = name;
            health_ = health;
        }

        Monster* Clone() const override {
            return new Goblin(*this);
        }

        void Show() const override {
            std::cout << "Goblin: " << name_ << ", Health: " << health_ << std::endl;
        }
    };

    
}
