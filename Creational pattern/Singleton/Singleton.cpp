#include <mutex>
#include <bits/stdc++.h>

namespace Singleton
{
    // 单线程 + 不考虑用户自己构造or复制or赋值
    class SingletonInSingleThread
    {
    private:
        static SingletonInSingleThread* m_instance;

    public:
        static SingletonInSingleThread* GetInstance()
        {
            if (m_instance == nullptr)
            {
                m_instance = new SingletonInSingleThread();
            }
            return m_instance;
        }
    };

    // 实现一：使用C++11之后的静态局部变量实现
    class SingletonByLocalStatic
    {
    public:
        static SingletonByLocalStatic& GetInstance()
        {
            static SingletonByLocalStatic instance;
            return instance;
        }
    };

    // 实现二：饿汉实现
    class LazySingleton
    {
    private:
        // 私有构造函数
        LazySingleton() {};
        static LazySingleton m_instance;

    public:
        // 删除拷贝构造函数和赋值运算符，防止拷贝实例
        LazySingleton(const LazySingleton&) = delete;
        LazySingleton& operator=(const LazySingleton&) = delete;

        static LazySingleton& GetInstance()
        {
            return m_instance;
        }
    };

    LazySingleton LazySingleton::m_instance;


    // 实现三：懒汉实现（双检查锁）
    class HungrySingleton
    {
    private:
        HungrySingleton() {}
        static volatile HungrySingleton* m_instance;
        static std::mutex mutex; // 静态互斥锁，用于同步
    public:
        HungrySingleton(const HungrySingleton&) = delete;
        HungrySingleton& operator=(const HungrySingleton&) = delete;

        static volatile HungrySingleton* GetInstance()
        {
            if (m_instance == nullptr)
            {
                std::lock_guard<std::mutex> lock(mutex); // 加锁
                if (m_instance == nullptr)
                {
                    m_instance = new HungrySingleton();
                }
            }
            return m_instance;
        }
    };

    volatile HungrySingleton* HungrySingleton::m_instance = nullptr;
    std::mutex Singleton::mutex;

    // 实现四：模板单例
    template <typename T>
    class Singleton
    {
    public:
        // 获取单例实例的静态方法
        static T& GetInstance()
        {
            static T instance; // 静态局部变量，线程安全并且只初始化一次
            return instance;
        }

        // 删除拷贝构造函数和赋值运算符，防止拷贝实例
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

    protected:
        // 构造函数和析构函数设为保护，以防止外部直接创建实例
        Singleton() {}
        virtual ~Singleton() {}
    };
}
