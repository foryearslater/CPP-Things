/**
 * @file TreeModelFactory.hpp
 * @author nichenglong
 * @brief 定义了享元工厂,用于创建和管理 TreeModel 对象
 * @version 0.1
 * @date 2025-08-05
 */

#pragma once
#include "TreeModel.hpp"

#include <map>
#include <string>
#include <memory> 

/**
 * @class TreeModelFactory
 * @brief 享元工厂:创建并管理享元对象。
 * @detail 它确保享元被适当地共享.当客户端请求一个享元时，工厂会检查对象池中是否已存在一个实例，如果存在则返回它,否则就创建一个新的实例并添加到池中，然后返回
 */
class TreeModelFactory
{
public:

    std::shared_ptr<TreeModel> GetTreeModel(const std::string& mesh, const std::string& texture);

    void ListFlyweights() const;

private:

    std::map<std::string, std::shared_ptr<TreeModel>> m_flyweights;

};