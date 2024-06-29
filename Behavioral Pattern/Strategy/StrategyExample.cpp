#include <bits/stdc++.h>

namespace StrategyExample
{
    // 策略接口
    class IAttackStrategy
    {
    public:
        virtual void Attack() const = 0;
        virtual ~IAttackStrategy() = default;
    };

    // 具体策略1：近战攻击
    class MeleeAttack : public IAttackStrategy
    {
    public:
        void Attack() const override
        {
            std::cout << "Performing melee attack!" << std::endl;
        }
    };

    // 具体策略2：远程攻击
    class RangedAttack : public IAttackStrategy
    {
    public:
        void Attack() const override
        {
            std::cout << "Performing ranged attack!" << std::endl;
        }
    };

    // 具体策略3：魔法攻击
    class MagicAttack : public IAttackStrategy
    {
    public:
        void Attack() const override
        {
            std::cout << "Performing magic attack!" << std::endl;
        }
    };

    // 上下文类
    class Character
    {
    private:
        IAttackStrategy* attackStrategy;

    public:
        Character(IAttackStrategy* strategy) : attackStrategy(strategy) {}

        void SetStrategy(IAttackStrategy* strategy)
        {
            attackStrategy = strategy;
        }

        void Attack() const
        {
            attackStrategy->Attack();
        }
    };

    void fun()
    {
        // 创建具体策略对象
        MeleeAttack meleeAttack;
        RangedAttack rangedAttack;
        MagicAttack magicAttack;

        // 创建角色并设置初始策略
        Character warrior(&meleeAttack);
        Character archer(&rangedAttack);
        Character mage(&magicAttack);

        // 执行攻击
        std::cout << "Warrior's attack: ";
        warrior.Attack();

        std::cout << "Archer's attack: ";
        archer.Attack();

        std::cout << "Mage's attack: ";
        mage.Attack();

        // 切换策略
        std::cout << "Mage switches to melee attack: ";
        mage.SetStrategy(&meleeAttack);
        mage.Attack();
    }
}
