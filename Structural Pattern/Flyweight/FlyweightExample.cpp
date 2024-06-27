#include<bits/stdc++.h>

namespace Flyweight
{
    // 享元接口 (Flyweight)
    class Character
    {
    public:
        virtual void Display(int fontSize, const std::string& color) const = 0;
        virtual ~Character() = default;
    };

    // 具体享元类 (ConcreteFlyweight)
    class ConcreteCharacter : public Character
    {
    private:
        char symbol; // 内部状态

    public:
        ConcreteCharacter(char symbol) : symbol(symbol) {}

        void Display(int fontSize, const std::string& color) const override
        {
            std::cout << "Character: " << symbol
                << ", Font Size: " << fontSize
                << ", Color: " << color << std::endl;
        }
    };

    // 享元工厂 (FlyweightFactory)
    class CharacterFactory
    {
    private:
        std::unordered_map<char, std::shared_ptr<Character>> characters;

    public:
        std::shared_ptr<Character> GetCharacter(char symbol)
        {
            if (characters.find(symbol) == characters.end())
            {
                characters[symbol] = std::make_shared<ConcreteCharacter>(symbol);
                std::cout << "Creating new character: " << symbol << std::endl;
            }
            else
            {
                std::cout << "Reusing existing character: " << symbol << std::endl;
            }
            return characters[symbol];
        }
    };

    // 客户端代码
    int main()
    {
        CharacterFactory factory;

        std::shared_ptr<Character> charA1 = factory.GetCharacter('A');
        std::shared_ptr<Character> charA2 = factory.GetCharacter('A');
        std::shared_ptr<Character> charB = factory.GetCharacter('B');

        charA1->Display(12, "Red");
        charA2->Display(14, "Blue");
        charB->Display(12, "Green");

        return 0;
    }
}
