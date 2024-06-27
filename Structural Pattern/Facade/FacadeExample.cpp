#include <bits/stdc++.h>

namespace Facade
{
    // 子系统类 - 电视
    class TV
    {
    public:
        void On() const
        {
            std::cout << "TV is On" << std::endl;
        }

        void Off() const
        {
            std::cout << "TV is Off" << std::endl;
        }

        void SetInputChannel() const
        {
            std::cout << "TV Channel is set for DVD" << std::endl;
        }
    };

    // 子系统类 - 音响系统
    class SoundSystem
    {
    public:
        void On() const
        {
            std::cout << "SoundSystem is On" << std::endl;
        }

        void Off() const
        {
            std::cout << "SoundSystem is Off" << std::endl;
        }

        void SetVolume(int level) const
        {
            std::cout << "SoundSystem volume set to " << level << std::endl;
        }
    };

    // 子系统类 - DVD播放器
    class DVDPlayer
    {
    public:
        void On() const
        {
            std::cout << "DVD Player is On" << std::endl;
        }

        void Off() const
        {
            std::cout << "DVD Player is Off" << std::endl;
        }

        void Play() const
        {
            std::cout << "DVD Player is Playing" << std::endl;
        }
    };

    // 外观类 - 家庭娱乐系统
    class HomeTheaterFacade
    {
    private:
        std::shared_ptr<TV> tv;
        std::shared_ptr<SoundSystem> soundSystem;
        std::shared_ptr<DVDPlayer> dvdPlayer;

    public:
        HomeTheaterFacade(std::shared_ptr<TV> tv, std::shared_ptr<SoundSystem> soundSystem,
                          std::shared_ptr<DVDPlayer> dvdPlayer)
            : tv(tv), soundSystem(soundSystem), dvdPlayer(dvdPlayer) {}

        void WatchMovie() const
        {
            std::cout << "Get ready to watch a movie..." << std::endl;
            tv->On();
            tv->SetInputChannel();
            soundSystem->On();
            soundSystem->SetVolume(5);
            dvdPlayer->On();
            dvdPlayer->Play();
        }

        void EndMovie() const
        {
            std::cout << "Shutting movie theater down..." << std::endl;
            dvdPlayer->Off();
            soundSystem->Off();
            tv->Off();
        }
    };

    // 客户端代码
    void fun()
    {
        std::shared_ptr<TV> tv = std::make_shared<TV>();
        std::shared_ptr<SoundSystem> soundSystem = std::make_shared<SoundSystem>();
        std::shared_ptr<DVDPlayer> dvdPlayer = std::make_shared<DVDPlayer>();

        HomeTheaterFacade homeTheater(tv, soundSystem, dvdPlayer);

        homeTheater.WatchMovie();
        std::cout << std::endl;
        homeTheater.EndMovie();

    }
}
