#include <bits/stdc++.h>

namespace Observer
{
    // 观察者接口
    class IObserver
    {
    public:
        virtual void Update() = 0;
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
}
