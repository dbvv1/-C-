#include <bits/stdc++.h>

namespace IteartorExample
{
    // 游戏角色类 (GameCharacter)
class GameCharacter {
public:
    GameCharacter(const std::string& name) : name(name) {}

    std::string GetName() const {
        return name;
    }

private:
    std::string name;
};

// 抽象迭代器类 (Iterator)
template<typename T>
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual T Next() = 0;
    virtual bool HasNext() const = 0;
};

// 抽象聚合类 (Aggregate)
template<typename T>
class Aggregate {
public:
    virtual ~Aggregate() = default;
    virtual std::shared_ptr<Iterator<T>> CreateIterator() const = 0;
};

// 具体迭代器类 (GameCharacterIterator)
class GameCharacterIterator : public Iterator<std::shared_ptr<GameCharacter>> {
public:
    GameCharacterIterator(const std::vector<std::shared_ptr<GameCharacter>>& characters) : characters(characters), index(0) {}

    std::shared_ptr<GameCharacter> Next() override {
        return characters[index++];
    }

    bool HasNext() const override {
        return index < characters.size();
    }

private:
    std::vector<std::shared_ptr<GameCharacter>> characters;
    size_t index;
};

// 具体聚合类 (GameCharacterAggregate)
class GameCharacterAggregate : public Aggregate<std::shared_ptr<GameCharacter>> {
public:
    void Add(const std::shared_ptr<GameCharacter>& character) {
        characters.push_back(character);
    }

    std::shared_ptr<Iterator<std::shared_ptr<GameCharacter>>> CreateIterator() const override {
        return std::make_shared<GameCharacterIterator>(characters);
    }

private:
    std::vector<std::shared_ptr<GameCharacter>> characters;
};

int main() {
    GameCharacterAggregate aggregate;
    aggregate.Add(std::make_shared<GameCharacter>("Hero"));
    aggregate.Add(std::make_shared<GameCharacter>("Villain"));
    aggregate.Add(std::make_shared<GameCharacter>("Sidekick"));

    std::shared_ptr<Iterator<std::shared_ptr<GameCharacter>>> iterator = aggregate.CreateIterator();
    while (iterator->HasNext()) {
        std::shared_ptr<GameCharacter> character = iterator->Next();
        std::cout << character->GetName() << " ";
    }
    std::cout << std::endl;

    return 0;
}
}
