#include "SedanCarFactory.hpp" 
#include "SUVCarFactory.hpp"
#include "TruckCarFactory.hpp"


/**
 * @brief 主函数，演示工厂方法模式的客户端使用。
 *
 * @detail 客户端通过抽象工厂接口与具体工厂交互，无需了解具体产品的创建细节。
 *         它下订单给不同的具体汽车工厂，并接收生产出的汽车产品。
 * @return int 程序的退出码。
 */
int main() {

    std::unique_ptr<CarFactory> sedanFactory = std::make_unique<SedanCarFactory>();
    std::unique_ptr<Car> mySedan = sedanFactory->ProduceCar();
    mySedan->ShowInfo(); 

    std::unique_ptr<CarFactory> suvFactory = std::make_unique<SUVCarFactory>();
    std::unique_ptr<Car> mySUV = suvFactory->ProduceCar();
    mySUV->ShowInfo(); 


    std::unique_ptr<CarFactory> truckFactory = std::make_unique<TruckCarFactory>();
    std::unique_ptr<Car> myTruck = truckFactory->ProduceCar();
    myTruck->ShowInfo(); 

    std::cout << "\n所有车辆和工厂的生命周期即将结束。\n";

    return 0;
}