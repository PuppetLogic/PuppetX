cmake_minimum_required(VERSION 3.26)
project(puppetx)

set(CMAKE_CXX_STANDARD 23)

set(EXECUTABLE_NAME ${CMAKE_PROJECT_NAME}-test)
add_executable(${EXECUTABLE_NAME})

add_subdirectory(../puppetlogic/utils ${CMAKE_CURRENT_BINARY_DIR}/src/puppetlogic/utils EXCLUDE_FROM_ALL)
add_subdirectory(../puppetlogic/test ${CMAKE_CURRENT_BINARY_DIR}/tests)

target_sources(${EXECUTABLE_NAME}
    PRIVATE
        PuppetXTestMain.cpp
)

add_subdirectory(puppetlogic)

find_package(GTest REQUIRED)

target_include_directories(${EXECUTABLE_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/puppetlogic
        ${CMAKE_SOURCE_DIR}/puppetlogic/test

        ${GTEST_INCLUDE_DIRS}
)
target_link_libraries(${EXECUTABLE_NAME}
    PRIVATE
        ${GTEST_LIBRARIES}
)

target_compile_options(${EXECUTABLE_NAME} PUBLIC -Wall)
