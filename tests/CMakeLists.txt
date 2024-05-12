cmake_minimum_required(VERSION 3.26)
project(puppetx)

set(CMAKE_CXX_STANDARD 23)

set(EXECUTABLE_NAME ${CMAKE_PROJECT_NAME}-test)
add_executable(${EXECUTABLE_NAME})

target_sources(${EXECUTABLE_NAME}
    PRIVATE
        PuppetXAppTests.cpp
)

find_package(GTest REQUIRED)

target_include_directories(${EXECUTABLE_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}
)
target_link_libraries(${EXECUTABLE_NAME}
    PRIVATE
        ${GTEST_LIBRARIES}
        ${GMOCK_LIBRARIES}
)

target_compile_options(${EXECUTABLE_NAME} PUBLIC -Wall)
