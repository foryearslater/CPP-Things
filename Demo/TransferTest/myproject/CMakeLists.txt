cmake_minimum_required(VERSION 3.10)
project(myproject)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(third_party/pugixml-1.15)

add_subdirectory(src)

add_executable(serialization_demo
    serialization_demo/main.cpp 
)

target_include_directories(serialization_demo PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(serialization_demo PRIVATE
    serialization      
    pugixml             
)
set_target_properties(serialization_demo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/Debug
)