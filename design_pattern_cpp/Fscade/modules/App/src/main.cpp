#include <iostream>
#include <memory> 

#include "DvdPlayer.hpp"
#include "Projector.hpp"
#include "Amplifier.hpp"
#include "HomeTheaterFacade.hpp"

int main() {

    std::unique_ptr<DvdPlayer> dvd = std::make_unique<DvdPlayer>("Top-O-Line DVD Player");
    std::unique_ptr<Projector> projector = std::make_unique<Projector>("Top-O-Line Projector");
    std::unique_ptr<Amplifier> amp = std::make_unique<Amplifier>("Top-O-Line Amplifier");

    std::unique_ptr<HomeTheaterFacade> homeTheater = std::make_unique<HomeTheaterFacade>(dvd.get(), projector.get(), amp.get());

    std::cout << "--- Client wants to watch a movie ---" << std::endl;
    homeTheater->WatchMovie("Raiders of the Lost Ark");

    std::cout << "\n--- Client wants to end the movie ---" << std::endl;
    homeTheater->EndMovie();

    std::cout << "\nProgram finished." << std::endl;

    return 0;
}