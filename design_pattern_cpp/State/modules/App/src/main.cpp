#include <iostream>
#include <memory>
#include "MusicPlayer.hpp"
#include "PlayingState.hpp" 
#include "PausedState.hpp"
#include "StoppedState.hpp"

int main()
{
    std::cout << "--- Creating MusicPlayer ---" << std::endl;
    std::unique_ptr<MusicPlayer> player = std::make_unique<MusicPlayer>();

    std::cout << "Initial state: " << player->GetCurrentState()->ToString() << std::endl
              << std::endl;

    std::cout << "--- Test Sequence 1 ---" << std::endl;
    player->PressPlay();
    player->PressPause();
    player->PressPlay();
    player->PressStop();

    std::cout << "--- Test Sequence 2 ---" << std::endl;
    player->PressPause();
    player->PressStop();
    player->PressPlay();
    player->PressPlay();
    player->PressStop();

    std::cout << "\nProgram finished." << std::endl;

    return 0;
}