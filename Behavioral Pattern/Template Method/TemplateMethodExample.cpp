#include<bits/stdc++.h>


namespace TemplateMethod
{
    // 抽象类 (GameCharacter)
    class GameCharacter
    {
    public:
        void CharacterAction() const
        {
            Spawn();
            Move();
            Attack();
            Defend();
            Die();
        }

        // 基本操作实现
        void Spawn() const
        {
            std::cout << "GameCharacter: Spawning the character." << std::endl;
        }

        void Die() const
        {
            std::cout << "GameCharacter: Character has died." << std::endl;
        }

        // 子类必须实现的基本操作 (抽象方法)
        virtual void Move() const = 0;
        virtual void Attack() const = 0;
        virtual void Defend() const = 0;
    };

    // 具体类 - 玩家角色 (PlayerCharacter)
    class PlayerCharacter : public GameCharacter
    {
    protected:
        void Move() const override
        {
            std::cout << "PlayerCharacter: Moving to the player's command." << std::endl;
        }

        void Attack() const override
        {
            std::cout << "PlayerCharacter: Attacking the enemy." << std::endl;
        }

        void Defend() const override
        {
            std::cout << "PlayerCharacter: Defending against the enemy attack." << std::endl;
        }
    };

    // 具体类 - 敌人角色 (EnemyCharacter)
    class EnemyCharacter : public GameCharacter
    {
    protected:
        void Move() const override
        {
            std::cout << "EnemyCharacter: Moving towards the player." << std::endl;
        }

        void Attack() const override
        {
            std::cout << "EnemyCharacter: Attacking the player." << std::endl;
        }

        void Defend() const override
        {
            std::cout << "EnemyCharacter: Defending against the player's attack." << std::endl;
        }
    };

    void fun()
    {
        std::shared_ptr<GameCharacter> player = std::make_shared<PlayerCharacter>();
        std::shared_ptr<GameCharacter> enemy = std::make_shared<EnemyCharacter>();

        std::cout << "Player Action Sequence:" << std::endl;
        player->CharacterAction();

        std::cout << "\nEnemy Action Sequence:" << std::endl;
        enemy->CharacterAction();

    }
}
