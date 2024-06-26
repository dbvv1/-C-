#include<bits/stdc++.h>

namespace AbstractFactory
{
    // 抽象产品类：按钮
    class Button
    {
    public:
        virtual void Render() const = 0; 
        virtual ~Button() = default; 
    };

    // 抽象产品类：文本框
    class TextBox
    {
    public:
        virtual void Render() const = 0; 
        virtual ~TextBox() = default; 
    };

    // 具体产品类：Windows按钮
    class WindowsButton : public Button
    {
    public:
        void Render() const override
        {
            std::cout << "Rendering Windows Button" << std::endl;
        }
    };

    // 具体产品类：Windows文本框
    class WindowsTextBox : public TextBox
    {
    public:
        void Render() const override
        {
            std::cout << "Rendering Windows TextBox" << std::endl;
        }
    };

    // 具体产品类：Mac按钮
    class MacButton : public Button
    {
    public:
        void Render() const override
        {
            std::cout << "Rendering Mac Button" << std::endl;
        }
    };

    // 具体产品类：Mac文本框
    class MacTextBox : public TextBox
    {
    public:
        void Render() const override
        {
            std::cout << "Rendering Mac TextBox" << std::endl;
        }
    };

    // 抽象工厂类
    class GUIFactory
    {
    public:
        virtual Button* CreateButton() const = 0; 
        virtual TextBox* CreateTextBox() const = 0;
        virtual ~GUIFactory() = default; 
    };

    // 具体工厂类：Windows工厂
    class WindowsFactory : public GUIFactory
    {
    public:
        Button* CreateButton() const override
        {
            return new WindowsButton();
        }

        TextBox* CreateTextBox() const override
        {
            return new WindowsTextBox();
        }
    };

    // 具体工厂类：Mac工厂
    class MacFactory : public GUIFactory
    {
    public:
        Button* CreateButton() const override
        {
            return new MacButton();
        }

        TextBox* CreateTextBox() const override
        {
            return new MacTextBox();
        }
    };
}
