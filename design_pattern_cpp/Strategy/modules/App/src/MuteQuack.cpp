#include "MuteQuack.hpp"

MuteQuack::MuteQuack()
{
    std::cout << "MuteQuack strategy created." << std::endl;
}

MuteQuack::~MuteQuack()
{
    std::cout << "MuteQuack strategy destroyed." << std::endl;
}

void MuteQuack::QuackNow() const
{
    std::cout << "<<Silence>>" << std::endl;
}