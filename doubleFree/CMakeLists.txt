cmake_minimum_required(VERSION 3.10)
project(doubleFree)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

#add_library(common SHARED src/common.cpp)

add_library(lib1 SHARED src/api1.cpp src/common.cpp)

add_library(lib2 SHARED src/api2.cpp src/common.cpp)

add_library(leonTest SHARED src/test.cpp)

add_executable(doubleFree1 src/mainTest1.cpp)
target_link_libraries(doubleFree1 lib1 lib2)

add_executable(doubleFree2 src/mainTest2.cpp)
target_link_libraries(doubleFree2 leonTest)