cmake_minimum_required(VERSION 3.10)
add_executable(serialization_demo
    main.cpp 
)


target_link_libraries(serialization_demo
    serialization
    pugixml::pugixml
)

target_include_directories(serialization_demo
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src 
    ${CMAKE_SOURCE_DIR}/third_party/pugixml  
)