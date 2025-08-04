#include <iostream>
#include "Folder.hpp"
#include "File.hpp"

int main() 
{
    
    auto root = std::make_shared<Folder>("C:");

    auto documents = std::make_shared<Folder>("Documents");
    auto pictures = std::make_shared<Folder>("Pictures");
    
    auto file1 = std::make_shared<File>("report.docx", 2048);
    auto file2 = std::make_shared<File>("budget.xlsx", 4096);
    auto image1 = std::make_shared<File>("cat.jpg", 8192);

    documents->Add(file1);
    documents->Add(file2);

    pictures->Add(image1);
    
    root->Add(documents);
    root->Add(pictures);

    auto system_log = std::make_shared<File>("system.log", 1024);
    root->Add(system_log);

    std::cout << "--- Displaying File System Structure ---" << std::endl;

    root->Display();

    std::cout << "\n--- Calculating Total Sizes ---" << std::endl;
    
    std::cout << "Size of '" << documents->GetName() << "': " << documents->GetSize() << " bytes" << std::endl;
    std::cout << "Size of '" << root->GetName() << "': " << root->GetSize() << " bytes" << std::endl;

    return 0;
}