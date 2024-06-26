#include <bits/stdc++.h>

namespace Builder
{
    // 产品类
    class Product
    {
    private:
        std::vector<std::string> parts;

    public:
        void Add(const std::string& part)
        {
            parts.push_back(part);
        }

        void Show() const
        {
            std::cout << "Product Parts: ";
            for (const auto& part : parts)
            {
                std::cout << part << " ";
            }
            std::cout << std::endl;
        }
    };

        // 抽象生成器类
        class Builder
        {
        public:
            virtual ~Builder() = default;

            virtual void BuildPartA() = 0;
            virtual void BuildPartB() = 0;
            virtual void BuildPartC() = 0;
            virtual Product* GetResult() = 0;
        };

        // 具体生成器类
        class ConcreteBuilder : public Builder
        {
        private:
            Product* product;
        public:
            ConcreteBuilder()
            {
                product = new Product();
            }

            ~ConcreteBuilder()
            {
                delete product;
            }

            void BuildPartA() override
            {
                product->Add("PartA");
            }

            void BuildPartB() override
            {
                product->Add("PartB");
            }

            void BuildPartC() override
            {
                product->Add("PartC");
            }

            Product* GetResult() override
            {
                return product;
            }
        };

    // 指导者类
    class Director {
    public:
        void Construct(Builder* builder) {
            builder->BuildPartA();
            builder->BuildPartB();
            builder->BuildPartC();
        }
    };

    void fun()
    {
        Director director;
        ConcreteBuilder builder;

        director.Construct(&builder);

        Product* product = builder.GetResult();
        product->Show();

    }
}
