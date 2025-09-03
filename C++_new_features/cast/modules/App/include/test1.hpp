//static_cast

#include <iostream>

class Base 
{
public:
    virtual void Speak() 
    { 
        std::cout << "I am Base" << std::endl; 
    }
};

class Derived : public Base 
{
public:
    void Speak() override 
    { 
        std::cout << "I am Derived" << std::endl; 
    }
    void UniqueToDerived() 
    { 
        std::cout << "This is a derived-only method." << std::endl; 
    }
};
void test1()
{
    //1.base
    double pi = 3.14159;
    int truncated_pi = static_cast<int>(pi);
    std::cout << "Truncated Pi: " << truncated_pi << std::endl;


    // unsafe down transform
    Base* p_base = new Derived();
    Derived* p_derived = static_cast<Derived*>(p_base);
    p_derived->UniqueToDerived();

    // danger
    Base* p_only_base = new Base();
    //unsafe
    Derived* p_derived_danger = static_cast<Derived*>(p_only_base);
    p_derived_danger->UniqueToDerived(); 

    delete p_base;
    delete p_only_base;
}