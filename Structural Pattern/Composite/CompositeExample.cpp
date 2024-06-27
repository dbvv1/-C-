#include <bits/stdc++.h>

namespace Composite
{
    // 抽象组件类 (SceneObject)
    class SceneObject
    {
    public:
        virtual void Add(std::shared_ptr<SceneObject> obj)
        {
            throw std::runtime_error("Add not supported");
        }

        virtual void Remove(std::shared_ptr<SceneObject> obj)
        {
            throw std::runtime_error("Remove not supported");
        }

        virtual std::shared_ptr<SceneObject> GetChild(int index) const
        {
            throw std::runtime_error("GetChild not supported");
        }

        virtual void Render() const = 0;
        virtual ~SceneObject() = default;
    };

    // 具体叶子节点类 (Sprite)
    class Sprite : public SceneObject
    {
    public:
        Sprite(const std::string& name) : name(name) {}

        void Render() const override
        {
            std::cout << "Rendering Sprite: " << name << std::endl;
        }

    private:
        std::string name;
    };

    // 具体组合节点类 (Layer)
    class Layer : public SceneObject
    {
    private:
        std::vector<std::shared_ptr<SceneObject>> children;

    public:
        void Add(std::shared_ptr<SceneObject> obj) override
        {
            children.push_back(obj);
        }

        void Remove(std::shared_ptr<SceneObject> obj) override
        {
            children.erase(std::remove(children.begin(), children.end(), obj), children.end());
        }

        std::shared_ptr<SceneObject> GetChild(int index) const override
        {
            if (index < 0 || index >= children.size())
            {
                throw std::out_of_range("Index out of range");
            }
            return children[index];
        }

        void Render() const override
        {
            std::cout << "Rendering Layer" << std::endl;
            for (const auto& child : children)
            {
                child->Render();
            }
        }
    };

    void fun()
    {
        std::shared_ptr<SceneObject> background = std::make_shared<Sprite>("Background");
        std::shared_ptr<SceneObject> character = std::make_shared<Sprite>("Main Character");
        std::shared_ptr<SceneObject> enemy = std::make_shared<Sprite>("Enemy");

        std::shared_ptr<SceneObject> layer1 = std::make_shared<Layer>();
        layer1->Add(background);
        layer1->Add(character);

        std::shared_ptr<SceneObject> layer2 = std::make_shared<Layer>();
        layer2->Add(enemy);

        std::shared_ptr<SceneObject> scene = std::make_shared<Layer>();
        scene->Add(layer1);
        scene->Add(layer2);

        std::cout << "Rendering Scene:" << std::endl;
        scene->Render();
    }
}
