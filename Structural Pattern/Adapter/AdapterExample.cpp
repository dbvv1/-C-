#include <bits/stdc++.h>

namespace Adapter
{
    // 目标接口 (Target)
    class Shape
    {
    public:
        virtual void Draw() const = 0;
        virtual ~Shape() = default;
    };

    // 旧的矩形类 (Adaptee)
    class LegacyRectangle
    {
    public:
        void DrawRectangle(int x1, int y1, int x2, int y2) const
        {
            std::cout << "Drawing rectangle with coordinates: ("
                << x1 << ", " << y1 << ") to ("
                << x2 << ", " << y2 << ")" << std::endl;
        }
    };

    // 矩形适配器 (Adapter)
    class RectangleAdapter : public Shape
    {
    private:
        std::shared_ptr<LegacyRectangle> legacyRectangle;
        int x, y, width, height;

    public:
        RectangleAdapter(std::shared_ptr<LegacyRectangle> legacyRect, int x, int y, int width, int height)
            : legacyRectangle(legacyRect), x(x), y(y), width(width), height(height) {}

        void Draw() const override
        {
            legacyRectangle->DrawRectangle(x, y, x + width, y + height);
        }
    };
}
