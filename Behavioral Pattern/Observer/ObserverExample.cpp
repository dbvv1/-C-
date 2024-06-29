#include <bits/stdc++.h>

namespace ObserverExamle
{
    // 观察者接口
    class IObserver
    {
    public:
        virtual void Update(int health) = 0;
        virtual ~IObserver() = default;
    };

    // 主题接口
    class ISubject
    {
    public:
        virtual void Attach(std::shared_ptr<IObserver> observer) = 0;
        virtual void Detach(std::shared_ptr<IObserver> observer) = 0;
        virtual void Notify() = 0;
        virtual ~ISubject() = default;
    };

    // 具体主题类（角色生命值）
    class Health : public ISubject
    {
    private:
        std::vector<std::shared_ptr<IObserver>> observers;
        int health;

    public:
        Health(int initialHealth) : health(initialHealth) {}

        void SetHealth(int newHealth)
        {
            health = newHealth;
            Notify();
        }

        int GetHealth() const
        {
            return health;
        }

        void Attach(std::shared_ptr<IObserver> observer) override
        {
            observers.push_back(observer);
        }

        void Detach(std::shared_ptr<IObserver> observer) override
        {
            observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
        }

        void Notify() override
        {
            for (auto& observer : observers)
            {
                observer->Update(health);
            }
        }
    };

    // 具体观察者类（UI更新）
    class HealthUI : public IObserver
    {
    public:
        void Update(int health) override
        {
            std::cout << "HealthUI: Player health is now " << health << std::endl;
        }
    };

    // 具体观察者类（音效播放）
    class HealthSound : public IObserver
    {
    public:
        void Update(int health) override
        {
            std::cout << "HealthSound: Play health change sound for new health " << health << std::endl;
        }
    };

    void fun()
    {
        // 创建具体主题对象（角色生命值）
        auto playerHealth = std::make_shared<Health>(100);

        // 创建具体观察者对象
        auto healthUI = std::make_shared<HealthUI>();
        auto healthSound = std::make_shared<HealthSound>();

        // 订阅观察者
        playerHealth->Attach(healthUI);
        playerHealth->Attach(healthSound);

        // 改变生命值，触发通知
        playerHealth->SetHealth(80);

        // 取消订阅
        playerHealth->Detach(healthUI);

        // 再次改变生命值，触发通知
        playerHealth->SetHealth(50);
    }
}
