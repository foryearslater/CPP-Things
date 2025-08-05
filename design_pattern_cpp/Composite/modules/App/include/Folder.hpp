/**
 * @file Folder.hpp
 * @author nichenglong
 * @brief 定义了组合模式中的组合（Composite）节点，即文件夹
 * @version 0.1
 * @date 2025-08-04
 */

#pragma once
#include "FileSystemComponent.hpp"
#include <vector>
#include <memory>


/**
 * @class Folder
 * @brief 组合：定义了有子组件的节点的行为
 * @detail 实现了 FileSystemComponent 接口，并存储了子组件, 它对子组件的操作会委托给子组件来完成
 */

class Folder : public FileSystemComponent
{
public:
  
    Folder(const std::string& name);
 
    const std::string& GetName() const override;

    int GetSize() const override;

    void Display(int indent = 0) const override;

    void Add(std::shared_ptr<FileSystemComponent> component) override;

    void Remove(std::shared_ptr<FileSystemComponent> component) override;

private:

    std::string m_name; 
    
    std::vector<std::shared_ptr<FileSystemComponent>> m_children;

};