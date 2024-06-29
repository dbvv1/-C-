#include <bits/stdc++.h>

namespace StateExample
{
    // 抽象状态类 (State)
    class State
    {
    public:
        virtual ~State() = default;
        virtual void HandleInput() = 0;
        virtual void Update() = 0;
    };

    // 前向声明 (Forward Declaration)
    class GameCharacter;

    // 具体状态类 - 行走状态 (WalkingState)
    class WalkingState : public State
    {
    public:
        WalkingState(GameCharacter* character) : character_(character) {}

        void HandleInput() override;

        void Update() override
        {
            std::cout << "Character is walking" << std::endl;
        }

    private:
        GameCharacter* character_;
    };

    // 具体状态类 - 跑步状态 (RunningState)
    class RunningState : public State
    {
    public:
        RunningState(GameCharacter* character) : character_(character) {}

        void HandleInput() override;

        void Update() override
        {
            std::cout << "Character is running" << std::endl;
        }

    private:
        GameCharacter* character_;
    };

    // 具体状态类 - 跳跃状态 (JumpingState)
    class JumpingState : public State
    {
    public:
        JumpingState(GameCharacter* character) : character_(character) {}

        void HandleInput() override;

        void Update() override
        {
            std::cout << "Character is jumping" << std::endl;
        }

    private:
        GameCharacter* character_;
    };

    // 环境类 - 游戏角色 (GameCharacter)
    class GameCharacter
    {
    public:
        GameCharacter() : state_(std::make_shared<WalkingState>(this)) {}

        void SetState(std::shared_ptr<State> state)
        {
            state_ = state;
        }

        void HandleInput()
        {
            state_->HandleInput();
        }

        void Update()
        {
            state_->Update();
        }

    private:
        std::shared_ptr<State> state_;
    };

    // 定义状态转换的具体实现
    void WalkingState::HandleInput()
    {
        // 简单示例，实际情况可根据具体输入进行状态转换
        std::cout << "Transitioning from Walking to Running" << std::endl;
        character_->SetState(std::make_shared<RunningState>(character_));
    }

    void RunningState::HandleInput()
    {
        std::cout << "Transitioning from Running to Jumping" << std::endl;
        character_->SetState(std::make_shared<JumpingState>(character_));
    }

    void JumpingState::HandleInput()
    {
        std::cout << "Transitioning from Jumping to Walking" << std::endl;
        character_->SetState(std::make_shared<WalkingState>(character_));
    }

    void fun()
    {
        GameCharacter character;

        character.Update();
        character.HandleInput();

        character.Update();
        character.HandleInput();

        character.Update();
        character.HandleInput();

        character.Update();
    }
}
