# minimum cmake version required to build project
cmake_minimum_required(VERSION 3.10)

# set project name
set(PROJECTNAME "UnitTests")
project(${PROJECTNAME} VERSION 1.0)

# define compiler standard
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)
add_subdirectory(tests)

add_executable(${PROJECTNAME} 
                main.cpp
                ${PROJECT_SOURCE_DIR}/tests/TestCommandLineParser/TestCommandLineParser.cpp
)

target_link_libraries( UnitTests PUBLIC
                                    CppUTest
                                    CommandLineParser
)

target_include_directories(${PROJECTNAME}  PUBLIC "${PROJECT_SOURCE_DIR}"
                                        "${PROJECT_SOURCE_DIR}/lib/CppUTest/include"
                                        "${PROJECT_SOURCE_DIR}/lib/CommandLineParser/include"
                                        )