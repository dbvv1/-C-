#include <bits/stdc++.h>

namespace Proxy
{
    // 抽象主题接口 (Subject)
    class Subject
    {
    public:
        virtual void Request() const = 0;
        virtual ~Subject() = default;
    };

    // 真实主题类 (RealSubject)
    class RealSubject : public Subject
    {
    public:
        void Request() const override
        {
            std::cout << "RealSubject: Handling Request" << std::endl;
        }
    };

    // 代理类 (Proxy)
    class Proxy : public Subject
    {
    private:
        std::shared_ptr<RealSubject> realSubject;

        // 检查访问权限
        bool CheckAccess() const
        {
            // 这里可以添加访问控制的逻辑
            std::cout << "Proxy: Checking access prior to firing a real request." << std::endl;
            return true;
        }

        // 日志记录请求信息
        void LogAccess() const
        {
            std::cout << "Proxy: Logging the time of request." << std::endl;
        }

    public:
        Proxy(std::shared_ptr<RealSubject> realSubject) : realSubject(realSubject) {}

        void Request() const override
        {
            if (CheckAccess())
            {
                // 还可以进行一个延迟的初始化
                realSubject->Request();
                LogAccess();
            }
        }
    };
}
