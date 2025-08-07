#include "Duck.hpp"

Duck::Duck(std::unique_ptr<FlyBehavior> flyBehavior,
           std::unique_ptr<QuackBehavior> quackBehavior,
           const std::string &type)
    : m_flyBehavior(std::move(flyBehavior)),
      m_quackBehavior(std::move(quackBehavior)),
      m_type(type)
{
    std::cout << m_type << " created." << std::endl;
}

Duck::~Duck()
{
    std::cout << m_type << " destroyed." << std::endl;
}

void Duck::PerformFly() const
{
    std::cout << m_type << " attempts to fly: ";
    if (m_flyBehavior)
    {
        m_flyBehavior->Fly();
    }
    else
    {
        std::cout << "No fly behavior set!" << std::endl;
    }
}

void Duck::PerformQuack() const
{
    std::cout << m_type << " attempts to quack: ";
    if (m_quackBehavior)
    {
        m_quackBehavior->QuackNow();
    }
    else
    {
        std::cout << "No quack behavior set!" << std::endl;
    }
}

void Duck::SetFlyBehavior(std::unique_ptr<FlyBehavior> newFlyBehavior)
{
    std::cout << m_type << " is getting new fly behavior." << std::endl;
    m_flyBehavior = std::move(newFlyBehavior);
}

void Duck::SetQuackBehavior(std::unique_ptr<QuackBehavior> newQuackBehavior)
{
    std::cout << m_type << " is getting new quack behavior." << std::endl;
    m_quackBehavior = std::move(newQuackBehavior);
}

void Duck::Display() const
{
    std::cout << "I'm a " << m_type << " duck." << std::endl;
}