#include<bits/stdc++.h>

// 具体的实例：运算类（加减乘除）
namespace FactoryMethod
{
    // 抽象运算类
    class AbstractOperator
    {
    private:
        double m_x;
        double m_y;

    public:
        AbstractOperator(double x = 0, double y = 0): m_x(x), m_y(y) {}
        void setX(double x){m_x = x;}
        void setY(double y){m_y = y;}

        virtual void GetResult() const = 0;
    };
    // 具体运算类 略


    
    // 抽象工厂类
    class IOperatorFactory
    {
    public:
        virtual AbstractOperator* CreateOperator() = 0;
    };

    
    // 具体工厂类 略
    
}
