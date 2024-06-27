#include <bits/stdc++.h>

namespace Decorator
{
    // 抽象角色类 (Component)
    class GameCharacter
    {
    public:
        virtual void Render() const = 0;
        virtual int GetAttackPower() const = 0;
        virtual ~GameCharacter() = default;
    };

    // 具体角色类 (ConcreteComponent)
    class BasicCharacter : public GameCharacter
    {
    public:
        void Render() const override
        {
            std::cout << "Rendering Basic Character" << std::endl;
        }

        int GetAttackPower() const override
        {
            return 10;
        }
    };

    // 装饰抽象类 (Decorator)
    class CharacterDecorator : public GameCharacter
    {
    protected:
        std::shared_ptr<GameCharacter> character;

    public:
        CharacterDecorator(std::shared_ptr<GameCharacter> character) : character(character) {}

        void Render() const override
        {
            character->Render();
        }

        int GetAttackPower() const override
        {
            return character->GetAttackPower();
        }
    };

    // 具体装饰类A (ConcreteDecoratorA) - 武器
    class WeaponDecorator : public CharacterDecorator
    {
    public:
        WeaponDecorator(std::shared_ptr<GameCharacter> character) : CharacterDecorator(character) {}

        void Render() const override
        {
            CharacterDecorator::Render();
            std::cout << " with a Weapon" << std::endl;
        }

        int GetAttackPower() const override
        {
            return CharacterDecorator::GetAttackPower() + 15;
        }
    };

    // 具体装饰类B (ConcreteDecoratorB) - 护甲
    class ArmorDecorator : public CharacterDecorator
    {
    public:
        ArmorDecorator(std::shared_ptr<GameCharacter> character) : CharacterDecorator(character) {}

        void Render() const override
        {
            CharacterDecorator::Render();
            std::cout << " wearing Armor" << std::endl;
        }

        int GetAttackPower() const override
        {
            return CharacterDecorator::GetAttackPower() + 5;
        }
    };

    void fun()
    {
        std::shared_ptr<GameCharacter> character = std::make_shared<BasicCharacter>();
        std::shared_ptr<GameCharacter> characterWithWeapon = std::make_shared<WeaponDecorator>(character);
        std::shared_ptr<GameCharacter> fullyEquippedCharacter = std::make_shared<ArmorDecorator>(characterWithWeapon);

        std::cout << "Character Render:" << std::endl;
        fullyEquippedCharacter->Render();

        std::cout << "Total Attack Power: " << fullyEquippedCharacter->GetAttackPower() << std::endl;

        return 0;
    }
}
