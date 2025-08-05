#include "TreeModel.hpp"

TreeModel::TreeModel(const std::string& mesh, const std::string& texture)
    : m_mesh(mesh), m_texture(texture)
{
    std::cout << "Loading heavyweight resources for TreeModel: "
              << "Mesh='" << m_mesh << "', Texture='" << m_texture << "'" << std::endl;
}

void TreeModel::Draw(float x, float y, float scale) const 
{
    std::cout << "  Drawing a tree with model (" << m_mesh << ", " << m_texture
              << ") at position (" << x << ", " << y << ") with scale " << scale << "." << std::endl;
}