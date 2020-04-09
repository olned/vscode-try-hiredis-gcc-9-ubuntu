cmake_minimum_required(VERSION 3.10)
project(my_project)

set (PROJECT_VER "0.1.0")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(ENABLE_TESTING)
  enable_testing()
  add_subdirectory(test)
endif()

add_subdirectory(src)
