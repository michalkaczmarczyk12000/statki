cmake_minimum_required(VERSION 3.16.0)
project(StatisticsApp VERSION 0.1.0)

add_executable(StatkiApp
    main.cpp
)

set_target_properties(StatkiApp
    PROPERTIES 
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_compile_options(StatkiApp PRIVATE -Wall -Wextra -pedantic -Werror)
target_link_libraries(StatkiApp PRIVATE Statki)

target_link_directories(StatkiApp PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/lib")
target_include_directories(StatkiApp PUBLIC "${PROJECT_SOURCE_DIR}/../lib")
