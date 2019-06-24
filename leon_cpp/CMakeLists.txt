cmake_minimum_required(VERSION 3.10)
project(leon_cpp)

set(CMAKE_CXX_STANDARD 11)
include_directories($ENV{EM_DATA_OPENCV_ROOT_PATH}/include)
link_directories($ENV{EM_DATA_OPENCV_ROOT_PATH}/lib)

# Boost
find_package(Boost 1.55 REQUIRED COMPONENTS system thread filesystem regex log log_setup)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARIES})
#ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

#find_package(OpenCV 3 REQUIRED)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

include_directories(${CMAKE_SOURCE_DIR}/include)

list(APPEND TEST_LINK_LIBS PUBLIC opencv_core)
list(APPEND TEST_LINK_LIBS PUBLIC opencv_imgproc)
list(APPEND TEST_LINK_LIBS PUBLIC opencv_imgcodecs)
list(APPEND TEST_LINK_LIBS PUBLIC opencv_highgui)
list(APPEND TEST_LINK_LIBS PUBLIC opencv_ml)
list(APPEND TEST_LINK_LIBS PUBLIC opencv_video)
list(APPEND TEST_LINK_LIBS PUBLIC opencv_videoio)
list(APPEND TEST_LINK_LIBS PUBLIC ${Boost_LIBRARIES})

add_subdirectory(src/boost)
add_subdirectory(src/c11)

add_executable(leon_cpp main.cpp imageProcess.hpp)
target_link_libraries(leon_cpp ${TEST_LINK_LIBS})

add_executable(virtual_destructor src/virtual_destructor.cpp)
add_executable(virtual_func_call  src/virtual_func_call.cpp)

add_executable(any src/any.cpp)
target_link_libraries(any ${Boost_LIBRARIES})

add_executable(boostFileSystem src/boostFileSystem.cpp)
target_link_libraries(boostFileSystem ${Boost_LIBRARIES})

add_executable(passByReference src/passByReference.cpp)

add_executable(cast src/cast.cpp)

add_executable(polymorphism src/ploymorphism.cpp)

add_executable(memberReference src/memberReference.cpp)

add_executable(copyelision src/copyElision.cpp)

add_executable(templateCallback src/templateCallback.cpp)

add_executable(map src/map.cpp)
target_link_libraries(map ${TEST_LINK_LIBS})

add_executable(line src/opencv/line.cpp)
target_link_libraries(line ${TEST_LINK_LIBS})

add_executable(dilate_ecrode src/opencv/dilate_erode.cpp)
target_link_libraries(dilate_ecrode ${TEST_LINK_LIBS})

add_executable(floodFill src/opencv/floodFill.cpp)
target_link_libraries(floodFill ${TEST_LINK_LIBS})

add_executable(trackBarTest src/opencv/trackBar.cpp)
target_link_libraries(trackBarTest ${TEST_LINK_LIBS})

add_executable(contours src/opencv/contours.cpp)
target_link_libraries(contours ${TEST_LINK_LIBS})

add_executable(draw_contours src/opencv/drawContours.cpp)
target_link_libraries(draw_contours ${TEST_LINK_LIBS})

add_executable(candy src/opencv/candy.cpp)
target_link_libraries(candy ${TEST_LINK_LIBS})

add_executable(laplacian src/opencv/laplacian.cpp)
target_link_libraries(laplacian ${TEST_LINK_LIBS})

add_executable(scharr src/opencv/scharr.cpp)
target_link_libraries(scharr ${TEST_LINK_LIBS})

add_executable(houghlines src/opencv/houghlines.cpp)
target_link_libraries(houghlines ${TEST_LINK_LIBS})

add_executable(remap src/opencv/remap.cpp)
target_link_libraries(remap ${TEST_LINK_LIBS})

add_executable(warpAffine src/opencv/warpAffine.cpp)
target_link_libraries(warpAffine ${TEST_LINK_LIBS})

add_executable(filter src/opencv/filter.cpp)
target_link_libraries(filter ${TEST_LINK_LIBS})

add_executable(surfDetector src/opencv/surfDetector.cpp)
target_link_libraries(surfDetector ${TEST_LINK_LIBS})

add_executable(rotate src/opencv/rotate.cpp)
target_link_libraries(rotate ${TEST_LINK_LIBS})

add_executable(rotate_test src/opencv/rotate_test.cpp)
target_link_libraries(rotate_test ${TEST_LINK_LIBS})

