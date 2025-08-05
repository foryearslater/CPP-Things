#include <iostream>
#include <vector>
#include "TreeModelFactory.hpp"
#include "Tree.hpp"

int main() 
{

    TreeModelFactory factory;

    std::vector<Tree> forest;
    
    std::cout << "\n--- Planting the forest ---" << std::endl;
    forest.emplace_back(10.0f, 20.0f, 1.0f, factory.GetTreeModel("oak_mesh.obj", "oak_texture.png"));
    forest.emplace_back(15.0f, 25.0f, 1.1f, factory.GetTreeModel("oak_mesh.obj", "oak_texture.png"));
    forest.emplace_back(50.0f, 30.0f, 0.9f, factory.GetTreeModel("oak_mesh.obj", "oak_texture.png"));

    forest.emplace_back(80.0f, 60.0f, 1.2f, factory.GetTreeModel("pine_mesh.obj", "pine_texture.png"));
    forest.emplace_back(90.0f, 70.0f, 1.0f, factory.GetTreeModel("pine_mesh.obj", "pine_texture.png"));

    factory.ListFlyweights();

    std::cout << "\n--- Rendering the forest ---" << std::endl;
    
    for (const auto& tree : forest) 
    {
        tree.Draw();
    }

    return 0;
}