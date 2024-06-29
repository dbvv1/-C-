#include <bits/stdc++.h>

namespace Memento
{
    // 备忘录类 (Memento)
    class Memento
    {
    public:
        Memento(const std::string& state) : state(state) {}

        std::string GetState() const
        {
            return state;
        }

    private:
        std::string state;
    };

    // 发起人类 (Originator)
    class Originator
    {
    public:
        void SetState(const std::string& state)
        {
            this->state = state;
        }

        std::string GetState() const
        {
            return state;
        }

        std::shared_ptr<Memento> SaveStateToMemento() const
        {
            return std::make_shared<Memento>(state);
        }

        void GetStateFromMemento(const std::shared_ptr<Memento>& memento)
        {
            state = memento->GetState();
        }

    private:
        std::string state;
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
        Originator originator;
        Caretaker caretaker;

        originator.SetState("State1");
        caretaker.AddMemento(originator.SaveStateToMemento());

        originator.SetState("State2");
        caretaker.AddMemento(originator.SaveStateToMemento());

        originator.SetState("State3");

        std::cout << "Current State: " << originator.GetState() << std::endl;

        originator.GetStateFromMemento(caretaker.GetMemento(1));
        std::cout << "Restored to State: " << originator.GetState() << std::endl;

        originator.GetStateFromMemento(caretaker.GetMemento(0));
        std::cout << "Restored to State: " << originator.GetState() << std::endl;
    }
}
