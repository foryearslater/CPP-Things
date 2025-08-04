/**
 * @file File.hpp
 * @author nichenglong
 * @brief 定义了组合模式中的叶子（Leaf）节点，即文件
 * @version 0.1
 * @date 2025-08-04
 */
#pragma once
#include "FileSystemComponent.hpp"

/**
 * @class File
 * @brief 叶子（Leaf）：表示组合中的叶子对象，它没有子节点
 * @detail 实现了 FileSystemComponent 接口，代表一个文件
 */

class File : public FileSystemComponent
{
public:

    File(const std::string& name, int size);

    const std::string& GetName() const override;

    int GetSize() const override;

    void Display(int indent = 0) const override;

private:

    std::string m_name; 

    int m_size;         
};