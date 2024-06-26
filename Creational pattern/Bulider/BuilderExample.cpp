#include <bits/stdc++.h>

namespace BuilderPattern
{
    class Car
    {
        std::string engine;
        std::string body;
        std::string wheel;
    };

    class CarBuilder
    {
    public:
        std::string engine;
        std::string body;
        std::string wheel;

        virtual void BuildEngine() = 0;
        virtual void BuildBody() = 0;
        virtual void BuildWheel() = 0;

        virtual Car* GetResule() = 0;
    };

    class BMWCarBuilder : public CarBuilder
    {
        virtual void BuildEngine() override
        {
            engine = "BMW的引擎";
        }

        virtual void BuildBody() override
        {
            body = "BMW的车身";
        }

        virtual void BuildWheel() override
        {
            wheel = "BMW的轮胎";
        }

        virtual Car* GetResule() override
        {
            return new Car();
        }
    };

    class CarDirector
    {
    private:
        CarBuilder* m_cb;

    public:
        CarDirector(CarBuilder* cb): m_cb(cb) {};

        void CreateCar()
        {
            m_cb->BuildEngine();
            m_cb->BuildBody();
            m_cb->BuildEngine();
        }
    };
}
