/**
 * @file FileSystemComponent.hpp
 * @author nichenglong
 * @brief 定义了组合模式中的组件接口
 * @version 0.1
 * @date 2025-08-04
 */
#pragma once
#include <string>
#include <memory> 


/**
 * @class FileSystemComponent
 * @brief 组件接口：为组合中的对象声明了统一的接口
 * @detail 无论是简单的叶子节点还是复杂的组合节点,客户端都可以通过这个接口以相同的方式对待它们
 */

class FileSystemComponent
{
public:

    virtual ~FileSystemComponent() = default;

    virtual const std::string& GetName() const = 0;

    virtual int GetSize() const = 0;

    virtual void Display(int indent = 0) const = 0;

    virtual void Add(std::shared_ptr<FileSystemComponent> component) {}

    virtual void Remove(std::shared_ptr<FileSystemComponent> component) {}
};