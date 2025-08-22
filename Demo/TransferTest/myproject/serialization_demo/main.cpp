#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <iomanip>
#include <SerializeFactory.hpp>
#include "Foo.hpp"
#include "Bar.hpp"
#include "Point3D.hpp"
#include <pugixml.hpp>

void RegisterFoo()
{
    SerializeFactory<double>::Register("Foo", []()
                                       { return std::make_unique<Foo<double>>(42, Point3D<double>(1.7, 2.0, 3.0)); });
}

void RegisterBar()
{
    SerializeFactory<double>::Register("Bar", []()
                                       { return std::make_unique<Bar<double>>(99); });
}

void RegisterPoint3D()
{
    SerializeFactory<double>::Register("Point3D", []()
                                       { return std::make_unique<Point3D<double>>(7, 8, 9); });
}

template <typename T>
void PrintXml(const Serializable<T> *obj, const std::string &rootName)
{
    pugi::xml_document doc;
    auto root = doc.append_child(rootName.c_str());
    obj->SaveToXml(root);
    std::ostringstream oss;
    doc.save(oss);
    std::cout << oss.str() << std::endl;
}

int main()
{
    RegisterFoo();
    RegisterBar();
    RegisterPoint3D();
    std::cout << std::fixed << std::setprecision(2);
    auto fooObj = SerializeFactory<double>::Create("Foo");
    if (fooObj)
    {
        Foo<double> *foo = dynamic_cast<Foo<double> *>(fooObj.get());
        if (foo)
        {
            // std::cout << "Foo<int> created!" << std::endl;
            // std::cout << "m_value = " << foo->m_value << std::endl;
            // std::cout << "m_point = (" << foo->m_point.x << ", " << foo->m_point.y << ", " << foo->m_point.z << ")" << std::endl;
            // std::cout << "Foo<int> XML:" << std::endl;
            PrintXml(foo, "Foo");
        }
    }

    auto barObj = SerializeFactory<double>::Create("Bar");
    if (barObj)
    {
        auto *bar = dynamic_cast<Bar<double> *>(barObj.get());
        if (bar)
        {
            // std::cout << "Bar<int> created!" << std::endl;
            // std::cout << "m_data = " << bar->m_data << std::endl;
            // std::cout << "Bar<int> XML:" << std::endl;
            PrintXml(bar, "Bar");
        }
    }
    auto pointObj = SerializeFactory<double>::Create("Point3D");
    if (pointObj)
    {
        auto *point = dynamic_cast<Point3D<double> *>(pointObj.get());
        if (point)
        {
            // std::cout << "Point3D<int> created!" << std::endl;
            // std::cout << "x = " << point->x << ", y = " << point->y << ", z = " << point->z << std::endl;
            // std::cout << "Point3D<int> XML:" << std::endl;
            PrintXml(point, "Point3D");
        }
    }

    return 0;
}