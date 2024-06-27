#include <bits/stdc++.h>

namespace Bridge
{
    // 实现部分接口 (Implementor)
    class DrawAPI
    {
    public:
        virtual void DrawCircle(int radius, int x, int y) const = 0;
        virtual void DrawRectangle(int width, int height, int x, int y) const = 0;
        virtual ~DrawAPI() = default;
    };

    // 具体实现类 (Concrete Implementor)
    class RasterDrawAPI : public DrawAPI
    {
    public:
        void DrawCircle(int radius, int x, int y) const override
        {
            std::cout << "Raster Drawing Circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
        }

        void DrawRectangle(int width, int height, int x, int y) const override
        {
            std::cout << "Raster Drawing Rectangle at (" << x << ", " << y << ") with width " << width << " and height "
                << height << std::endl;
        }
    };

    class VectorDrawAPI : public DrawAPI
    {
    public:
        void DrawCircle(int radius, int x, int y) const override
        {
            std::cout << "Vector Drawing Circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
        }

        void DrawRectangle(int width, int height, int x, int y) const override
        {
            std::cout << "Vector Drawing Rectangle at (" << x << ", " << y << ") with width " << width << " and height "
                << height << std::endl;
        }
    };

    // 抽象部分接口 (Abstraction)
    class Shape
    {
    protected:
        std::shared_ptr<DrawAPI> drawAPI;

    public:
        Shape(std::shared_ptr<DrawAPI> api) : drawAPI(api) {}
        virtual void Draw() const = 0;
        virtual ~Shape() = default;
    };

    // 具体抽象部分 (Refined Abstraction)
    class Circle : public Shape
    {
    private:
        int x, y, radius;

    public:
        Circle(int x, int y, int radius, std::shared_ptr<DrawAPI> api)
            : Shape(api), x(x), y(y), radius(radius) {}

        void Draw() const override
        {
            drawAPI->DrawCircle(radius, x, y);
        }
    };

    class Rectangle : public Shape
    {
    private:
        int x, y, width, height;

    public:
        Rectangle(int x, int y, int width, int height, std::shared_ptr<DrawAPI> api)
            : Shape(api), x(x), y(y), width(width), height(height) {}

        void Draw() const override
        {
            drawAPI->DrawRectangle(width, height, x, y);
        }
    };
}
