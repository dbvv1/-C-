#include <bits/stdc++.h>

namespace ChainOfResponsibility
{
    // 抽象处理者 (Handler)
    class Handler
    {
    public:
        virtual ~Handler() = default;

        void SetNext(std::shared_ptr<Handler> nextHandler)
        {
            next = nextHandler;
        }

        void virtual  HandleRequest(int request)
        {
            if (next)
            {
                next->HandleRequest(request);
            }
            else
            {
                std::cout << "No handler could handle the request." << std::endl;
            }
        }

    protected:
        virtual bool CanHandleRequest(int request) const = 0;

    private:
        std::shared_ptr<Handler> next = nullptr;
    };

    // 具体处理者A (ConcreteHandlerA)
    class ConcreteHandlerA : public Handler
    {
    protected:
        bool CanHandleRequest(int request) const override
        {
            return request < 10;
        }

    public:
        void HandleRequest(int request) override
        {
            if (CanHandleRequest(request))
            {
                std::cout << "ConcreteHandlerA handled the request: " << request << std::endl;
            }
            else
            {
                Handler::HandleRequest(request);
            }
        }
    };

    // 具体处理者B (ConcreteHandlerB)
    class ConcreteHandlerB : public Handler
    {
    protected:
        bool CanHandleRequest(int request) const override
        {
            return request >= 10 && request < 20;
        }

    public:
        void HandleRequest(int request) override
        {
            if (CanHandleRequest(request))
            {
                std::cout << "ConcreteHandlerB handled the request: " << request << std::endl;
            }
            else
            {
                Handler::HandleRequest(request);
            }
        }
    };

    // 具体处理者C (ConcreteHandlerC)
    class ConcreteHandlerC : public Handler
    {
    protected:
        bool CanHandleRequest(int request) const override
        {
            return request >= 20;
        }

    public:
        void HandleRequest(int request) override
        {
            if (CanHandleRequest(request))
            {
                std::cout << "ConcreteHandlerC handled the request: " << request << std::endl;
            }
            else
            {
                Handler::HandleRequest(request);
            }
        }
    };

    void fun()
    {
        std::shared_ptr<Handler> handlerA = std::make_shared<ConcreteHandlerA>();
        std::shared_ptr<Handler> handlerB = std::make_shared<ConcreteHandlerB>();
        std::shared_ptr<Handler> handlerC = std::make_shared<ConcreteHandlerC>();

        handlerA->SetNext(handlerB);
        handlerB->SetNext(handlerC);

        std::vector<int> requests = {5, 14, 22, 3, 18, 27};

        for (int request : requests)
        {
            handlerA->HandleRequest(request);
        }
    }
}
