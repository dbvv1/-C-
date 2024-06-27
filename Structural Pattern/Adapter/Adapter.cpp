#include <bits/stdc++.h>

/// Target:定义Client使用的与特定领域相关的接口
/// Client:与符合Target接口的对象协同
/// Adaptee:定义一个已经存在的接口，这个接口需要适配
/// Adapter:对Adaptee的接口与Target接口进行适配

namespace AdapterByInherit
{
    // 继承实现(类版本)
    class Target
    {
    public:
        virtual void Request()
        {
            std::cout<<"普通请求"<<std::endl;
        }
    };

    // 一个已经存在的接口，这个接口需要适配
    class Adaptee
    {
    public:
        void SpecificRequest()
        {
            std::cout << "特殊请求"<<std::endl;
        }
    };

    class Adapter:public Target,private Adaptee
    {
        virtual void Request() override
        {
            SpecificRequest();
        }
    };

    void fun()
    {
        Target* target = new Adapter();
        target->Request();
    }
}

namespace AdapterByCompose
{
    // 组合实现(对象版本)
    class Target
    {
    public:
        virtual  void Request()
        {
            std::cout<<"普通请求"<<std::endl;
        }
    };

    class Adaptee
    {
    public:
        void SpecificRequest()
        {
            std::cout << "特殊请求"<<std::endl;
        }
    };

    class Adapter:public Target
    {
    private:
        Adaptee* m_adaptee;
    public:
        Adapter():m_adaptee(new Adaptee()){}

        virtual void Request() override
        {
            m_adaptee->SpecificRequest();
        }
    };

    void fun()
    {
        Target* target = new Adapter();
        target->Request();
    }
}
