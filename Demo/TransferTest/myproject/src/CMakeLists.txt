cmake_minimum_required(VERSION 3.10)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(serialization STATIC
    SerializeFactory.cpp
    Foo.cpp
    Point3D.cpp
    Bar.cpp
)
target_include_directories(serialization PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/third_party/pugixml-1.15/src
)
