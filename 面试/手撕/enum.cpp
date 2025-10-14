/*
enum 与 enum class 的区别
enum 为 c++ 98 提供的未限域枚举
enum class 为 c++11 提供的限域枚举
区别:
1. 是否存在命名空间污染
enum 存在, 会将枚举值直接暴露到包含枚举的作用域中;
enum class 不存在, 会限定作用域;
2. 类型安全
enum 类型不安全, 可以隐式转换, 可能导致意外错误;
enum class 提供强类型安全, 防止意外的隐式转换;
3. 默认情况下是否支持前置声明
默认情况下, enum 无法进行前置声明, 核心原因是枚举的底层类型是隐式确定的, 在c++98不能在声明时指定, 在c++11之后可以通过手动指定底层类型支持前置声明;
默认情况下, [enum class]支持前置声明;
*/
// 编译不过
//  enum Color
//  {
//      BLACK,
//      WHITE,
//      RED
//  };
//  enum TrafficLight
//  {
//      RED,
//      YELLOW,
//      CREEN
//  };
// 保证类型安全
enum class Color
{
    BLACK,
    WHITE,
    RED
};
enum class TrafficLight
{
    RED,
    YELLOW,
    CREEN
};
int main()
{
    Color c = Color::RED;
    TrafficLight t = TrafficLight::RED;

    return 0;
}