#include <bits/stdc++.h>

namespace MementoExample
{
    // 备忘录类 (Memento)
    class Memento
    {
    public:
        Memento(int health, int mana, int experience)
            : health(health), mana(mana), experience(experience) {}

        int GetHealth() const
        {
            return health;
        }

        int GetMana() const
        {
            return mana;
        }

        int GetExperience() const
        {
            return experience;
        }

    private:
        int health;
        int mana;
        int experience;
    };

    // 发起人类 (GameCharacter)
    class GameCharacter
    {
    public:
        void SetState(int health, int mana, int experience)
        {
            this->health = health;
            this->mana = mana;
            this->experience = experience;
        }

        void PrintState() const
        {
            std::cout << "Health: " << health
                << ", Mana: " << mana
                << ", Experience: " << experience << std::endl;
        }

        std::shared_ptr<Memento> SaveStateToMemento() const
        {
            return std::make_shared<Memento>(health, mana, experience);
        }

        void GetStateFromMemento(const std::shared_ptr<Memento>& memento)
        {
            if (memento)
            {
                health = memento->GetHealth();
                mana = memento->GetMana();
                experience = memento->GetExperience();
            }
        }

    private:
        int health;
        int mana;
        int experience;
    };

    // 管理者类 (Caretaker)
    class Caretaker
    {
    public:
        void AddMemento(const std::shared_ptr<Memento>& memento)
        {
            mementos.push_back(memento);
        }

        std::shared_ptr<Memento> GetMemento(int index) const
        {
            if (index >= 0 && index < mementos.size())
            {
                return mementos[index];
            }
            return nullptr;
        }

    private:
        std::vector<std::shared_ptr<Memento>> mementos;
    };

    void fun()
    {
        GameCharacter character;
        Caretaker caretaker;

        character.SetState(100, 50, 0);
        std::cout << "Initial State: ";
        character.PrintState();
        caretaker.AddMemento(character.SaveStateToMemento());

        character.SetState(80, 30, 10);
        std::cout << "State after battle: ";
        character.PrintState();
        caretaker.AddMemento(character.SaveStateToMemento());

        character.SetState(50, 10, 20);
        std::cout << "State after another battle: ";
        character.PrintState();

        std::cout << "Restoring to previous state..." << std::endl;
        character.GetStateFromMemento(caretaker.GetMemento(1));
        character.PrintState();

        std::cout << "Restoring to initial state..." << std::endl;
        character.GetStateFromMemento(caretaker.GetMemento(0));
        character.PrintState();
    }
}
