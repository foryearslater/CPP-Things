#include <iostream>
#include <memory> 

#include "L1Support.hpp"
#include "L2Support.hpp"
#include "L3Support.hpp"

int main() 
{
    std::unique_ptr<SupportHandler> l1 = std::make_unique<L1Support>();
    SupportHandler* l2 = new L2Support();
    SupportHandler* l3 = new L3Support();
    l1->SetNext(l2);
    l2->SetNext(l3);

    std::cout << "--- Sending Requests ---" << std::endl;

    Request req1 = {Request::GENERAL, "My internet is slow."};
    l1->Handle(req1);
    std::cout << std::endl;

    Request req2 = {Request::TECHNICAL, "Software installation failed."};
    l1->Handle(req2);
    std::cout << std::endl;

    Request req3 = {Request::BILLING, "I have a question about my last bill."};
    l1->Handle(req3);
    std::cout << std::endl;

    Request req4 = {Request::CRITICAL, "System is completely down!"};
    l1->Handle(req4);
    std::cout << std::endl;
    
    Request req5 = {Request::Type(999), "Unknown issue type."}; 
    l1->Handle(req5);
    std::cout << std::endl;

    std::cout << "--- All requests processed ---" << std::endl;

    return 0;
}