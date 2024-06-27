#include <bits/stdc++.h>

namespace Facade
{
    // 子系统类A
    class SubsystemA
    {
    public:
        void OperationA() const
        {
            std::cout << "SubsystemA: OperationA" << std::endl;
        }
    };

    // 子系统类B
    class SubsystemB
    {
    public:
        void OperationB() const
        {
            std::cout << "SubsystemB: OperationB" << std::endl;
        }
    };

    // 子系统类C
    class SubsystemC
    {
    public:
        void OperationC() const
        {
            std::cout << "SubsystemC: OperationC" << std::endl;
        }
    };

    // 外观类 (Facade)
    class Facade
    {
    private:
        std::shared_ptr<SubsystemA> subsystemA;
        std::shared_ptr<SubsystemB> subsystemB;
        std::shared_ptr<SubsystemC> subsystemC;

    public:
        Facade()
            : subsystemA(std::make_shared<SubsystemA>()),
              subsystemB(std::make_shared<SubsystemB>()),
              subsystemC(std::make_shared<SubsystemC>()) {}

        void Operation1() const
        {
            std::cout << "Facade: Operation1" << std::endl;
            subsystemA->OperationA();
            subsystemB->OperationB();
        }

        void Operation2() const
        {
            std::cout << "Facade: Operation2" << std::endl;
            subsystemB->OperationB();
            subsystemC->OperationC();
        }
    };
}
