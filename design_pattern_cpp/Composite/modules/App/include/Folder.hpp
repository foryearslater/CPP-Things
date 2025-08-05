/**
 * @file Folder.hpp
 * @author nichenglong
 * @brief ���������ģʽ�е���ϣ�Composite���ڵ㣬���ļ���
 * @version 0.1
 * @date 2025-08-04
 */

#pragma once
#include "FileSystemComponent.hpp"
#include <vector>
#include <memory>


/**
 * @class Folder
 * @brief ��ϣ���������������Ľڵ����Ϊ
 * @detail ʵ���� FileSystemComponent �ӿڣ����洢�������, ����������Ĳ�����ί�и�����������
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