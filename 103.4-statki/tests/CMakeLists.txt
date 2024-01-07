cmake_minimum_required(VERSION 3.16.0)
project(StatkiTests VERSION 0.1.0)

Include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.0.1)
# w nowszych cmake (> 3.15) starczyłoby tylko:  FetchContent_MakeAvailable(Catch2)
FetchContent_GetProperties(Catch2)
if(NOT catch2_POPULATED)
    FetchContent_Populate(Catch2)
    add_subdirectory("${catch2_SOURCE_DIR}"
                     "${catch2_BINARY_DIR}")
endif()

add_executable(StatkiTests
gameTests.cpp
)

set_target_properties(StatkiTests
    PROPERTIES 
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
add_test(NAME StatkiTests COMMAND StatkiTests)
target_compile_options(StatkiTests PRIVATE -Wall -Wextra -Werror)
target_link_libraries(StatkiTests PRIVATE Statki Catch2::Catch2WithMain)
target_link_directories(StatkiTests PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/lib")
target_include_directories(StatkiTests PUBLIC "${PROJECT_SOURCE_DIR}/../lib")
