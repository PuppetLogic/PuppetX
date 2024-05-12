cmake_minimum_required(VERSION 3.26)
project(PuppetX)

set(CMAKE_CXX_STANDARD 23)

set(EXECUTABLE_NAME ${CMAKE_PROJECT_NAME})
add_executable(${EXECUTABLE_NAME})

add_subdirectory(main)
add_subdirectory(puppetlogic)
add_subdirectory(tests)

target_include_directories(${EXECUTABLE_NAME}
    PRIVATE
        .
        main
        puppetlogic
)
