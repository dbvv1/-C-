#include <bits/stdc++.h>

namespace Iterator
{
    // 抽象迭代器类 (Iterator)
    template <typename T>
    class Iterator
    {
    public:
        virtual ~Iterator() = default;
        virtual T Next() = 0;
        virtual bool HasNext() const = 0;
    };

    // 抽象聚合类 (Aggregate)
    template <typename T>
    class Aggregate
    {
    public:
        virtual ~Aggregate() = default;
        virtual std::shared_ptr<Iterator<T>> CreateIterator() const = 0;
    };

    // 具体迭代器类 (ConcreteIterator)
    template <typename T>
    class ConcreteIterator : public Iterator<T>
    {
    public:
        ConcreteIterator(const std::vector<T>& items) : items(items), index(0) {}

        T Next() override
        {
            return items[index++];
        }

        bool HasNext() const override
        {
            return index < items.size();
        }

    private:
        std::vector<T> items;
        size_t index;
    };

    // 具体聚合类 (ConcreteAggregate)
    template <typename T>
    class ConcreteAggregate : public Aggregate<T>
    {
    public:
        void Add(const T& item)
        {
            items.push_back(item);
        }

        std::shared_ptr<Iterator<T>> CreateIterator() const override
        {
            return std::make_shared<ConcreteIterator<T>>(items);
        }

    private:
        std::vector<T> items;
    };

    void fun()
    {
        ConcreteAggregate<int> aggregate;
        aggregate.Add(1);
        aggregate.Add(2);
        aggregate.Add(3);

        std::shared_ptr<Iterator<int>> iterator = aggregate.CreateIterator();
        while (iterator->HasNext())
        {
            std::cout << iterator->Next() << " ";
        }
        std::cout << std::endl;
    }
}

class MyIterator
{
    class Aggregate;
    class ConcreteAggregate;


    class Item {};

    class Iterator
    {
    public:
        virtual Item* First() = 0;
        virtual void Next() = 0;
        virtual Item* currentItem() = 0;
        virtual bool isDone() = 0;
    };

    class ConcreteIterator : public Iterator
    {
    private:
        ConcreteAggregate* aggregate;
        int current = 0;

    public:
        ConcreteIterator(ConcreteAggregate* agg): aggregate(agg) {}

        Item* First() override
        {
            return &(*aggregate)[0];
        }

        void Next() override
        {
            current++;
        }

        Item* currentItem() override
        {
            // 判断越界
            return &(*aggregate)[current];
        }

        bool isDone() override
        {
            return current >= aggregate->GetLen();
        }
    };

    class Aggregate
    {
    public:
        virtual Iterator* CreateIterator() = 0;
        virtual int GetLen() = 0;
        virtual void Add(Item i) = 0;
        virtual Item& operator[](int index) = 0;
    };

    class ConcreteAggregate : public Aggregate
    {
    private:
        std::vector<Item> data;

    public:
        Iterator* CreateIterator() override
        {
            return new ConcreteIterator(this);
        }

        int GetLen() override
        {
            return data.size();
        }

        Item& operator[](int index) override
        {
            return data[index];
        }

        void Add(Item i)
        {
            data.push_back(i);
        }
    };
};
