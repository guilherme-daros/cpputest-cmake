# minimum cmake version required to build project
cmake_minimum_required(VERSION 3.10)

# set project name
project(teste VERSION 1.0)

# define compiler standard
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

add_subdirectory(CommandLineParser)

add_executable(teste main.cpp)

target_link_libraries(teste PUBLIC CommandLineParser)

target_include_directories(teste PUBLIC "${PROJECT_SOURCE_DIR}"
                                        "${PROJECT_SOURCE_DIR}/CommandLineParser")