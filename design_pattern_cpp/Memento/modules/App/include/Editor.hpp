#pragma once
#include <string>
#include <memory>            // For std::unique_ptr
#include "EditorMemento.hpp" // 包含备忘录类

/**
 * @class Editor
 * @brief 原发器: 一个需要保存其内部状态的对象
 * @detail 负责创建备忘录（以保存其当前状态）和使用备忘录（以恢复到以前的状态）
 */
class Editor
{
public:
    explicit Editor(const std::string &initialText);

    ~Editor();

    void SetText(const std::string &newText);

    std::string GetText() const;

    std::unique_ptr<EditorMemento> Save() const;

    void Restore(const EditorMemento *memento);

private:
    std::string m_text;
};