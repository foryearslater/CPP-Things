#pragma once
#include <vector>
#include <memory>

#include "EditorMemento.hpp"

/**
 * @class History
 * @brief 负责人：负责保存和管理备忘录（Memento）
 * @detail 它不操作备忘录的内部内容，只负责存储和检索
 */
class History
{
public:
    History();

    ~History();

    void Push(std::unique_ptr<EditorMemento> memento);

    std::unique_ptr<EditorMemento> Pop();

    size_t GetCount() const;

private:
    std::vector<std::unique_ptr<EditorMemento>> m_mementos;
};