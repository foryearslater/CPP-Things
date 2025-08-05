#include "Tree.hpp"

Tree::Tree(float x, float y, float scale, std::shared_ptr<TreeModel> model)
    : m_x(x), m_y(y), m_scale(scale), m_model(model) {}

void Tree::Draw() const 
{
    if (m_model) 
    {
        m_model->Draw(m_x, m_y, m_scale);
    }
}