cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)

project(Testen)
add_executable(Testen main.cpp)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(Testen ${PYTHON_LIBRARIES})

#find_package(PythonLibs REQUIRED Development PATHS "C:/Users/fabia/AppData/Local/Programs/Python")

