#include "Factory.hpp"

/**
 * @brief 客户端代码，使用抽象工厂创建和操作家具。
 *
 * @param factory 具体的家具工厂实例的引用。
 * @detail 客户端通过抽象接口与工厂和产品交互，不关心具体实现（例如，它不知道
 *         正在创建的是维多利亚风格还是现代风格的家具）。
 *         由于工厂方法返回的是 std::unique_ptr，内存管理由智能指针自动处理，
 *         无需手动 delete。
 */

void clientCode(const FurnitureFactory& factory)
{
    std::cout << "\n--- 客户端请求家具 ---" << std::endl;

    std::unique_ptr<Chair> chair = factory.createChair();
    std::unique_ptr<Sofa> sofa = factory.createSofa();
    std::unique_ptr<CoffeeTable> table = factory.createCoffeeTable();

    std::cout << chair->sitOn() << std::endl;
    std::cout << sofa->lieOn() << std::endl;
    std::cout << table->placeItems() << std::endl;
    std::cout << "--- 家具请求完成 ---" << std::endl;
}


int main() {

    VictorianFurnitureFactory victorianFactory;

    clientCode(victorianFactory);

    ModernFurnitureFactory modernFactory;

    clientCode(modernFactory);

    return 0;
}