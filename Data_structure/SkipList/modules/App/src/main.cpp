#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include "SkipList.hpp"

int main()
{
    std::unique_ptr<SkipList<int, int>> skipList = std::make_unique<SkipList<int, int>>();

    skipList->Insert(3, 30);
    skipList->Insert(6, 60);
    skipList->Insert(7, 70);
    skipList->Insert(9, 90);
    skipList->Insert(12, 120);
    skipList->Insert(17, 170);
    skipList->Insert(19, 190);
    skipList->Insert(26, 260);
    skipList->Insert(21, 210);
    skipList->Insert(20, 200);
    skipList->Insert(1, 10);
    skipList->Insert(2, 20);

    std::cout << "Attempting to insert duplicate key 7: " << (skipList->Insert(7, 75) ? "Success" : "Failed (Key exists)") << std::endl;

    skipList->Display();

    int searchKey1 = 17;
    int searchValue1 = 0;
    if (skipList->Search(searchKey1, searchValue1))
    {
        std::cout << "Found key " << searchKey1 << ", value: " << searchValue1 << std::endl;
    }
    else
    {
        std::cout << "Key " << searchKey1 << " not found." << std::endl;
    }

    int searchKey2 = 10;
    int searchValue2 = 0;
    if (skipList->Search(searchKey2, searchValue2))
    {
        std::cout << "Found key " << searchKey2 << ", value: " << searchValue2 << std::endl;
    }
    else
    {
        std::cout << "Key " << searchKey2 << " not found." << std::endl;
    }

    int deleteKey1 = 6;
    if (skipList->Delete(deleteKey1))
    {
        std::cout << "Deleted key " << deleteKey1 << "." << std::endl;
    }
    else
    {
        std::cout << "Key " << deleteKey1 << " not found for deletion." << std::endl;
    }

    int deleteKey2 = 100;
    if (skipList->Delete(deleteKey2))
    {
        std::cout << "Deleted key " << deleteKey2 << "." << std::endl;
    }
    else
    {
        std::cout << "Key " << deleteKey2 << " not found for deletion." << std::endl;
    }

    skipList->Display();

    if (skipList->Search(deleteKey1, searchValue1))
    {
        std::cout << "Found key " << deleteKey1 << ", value: " << searchValue1 << std::endl;
    }
    else
    {
        std::cout << "Key " << deleteKey1 << " not found." << std::endl;
    }

    return 0;
}