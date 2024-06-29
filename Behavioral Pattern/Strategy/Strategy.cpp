#include <bits/stdc++.h>

namespace Strategy
{
    // 策略接口
    class IStrategy {
    public:
        virtual void Execute() const = 0;
        virtual ~IStrategy() = default;
    };

    // 上下文类
    class Context {
    private:
        std::unique_ptr<IStrategy> strategy;
    public:
        void SetStrategy(std::unique_ptr<IStrategy> newStrategy) {
            strategy = std::move(newStrategy);
        }

        void ExecuteStrategy() const {
            if (strategy) {
                strategy->Execute();
            } else {
                std::cerr << "Strategy not set!" << std::endl;
            }
        }
    };

    // 具体策略A
    class ConcreteStrategyA : public IStrategy {
    public:
        void Execute() const override {
            std::cout << "Executing Strategy A" << std::endl;
        }
    };

    // 具体策略B
    class ConcreteStrategyB : public IStrategy {
    public:
        void Execute() const override {
            std::cout << "Executing Strategy B" << std::endl;
        }
    };

    // 示例使用
    void fun() {
        // 上下文对象
        Context context;

        // 设置策略A并执行
        context.SetStrategy(std::make_unique<ConcreteStrategyA>());
        context.ExecuteStrategy();

        // 设置策略B并执行
        context.SetStrategy(std::make_unique<ConcreteStrategyB>());
        context.ExecuteStrategy();

    }
}
