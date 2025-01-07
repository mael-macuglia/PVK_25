cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Set Eigen path
set(EIGEN3_INCLUDE_DIR "/opt/homebrew/Cellar/eigen/3.4.0_1/include/eigen3")




add_executable(cpp-template-vector-basic src/cpp-template-vector-basic.cpp)
add_executable(cpp-functions src/cpp-functions.cpp)
add_executable(some-eigen src/some-eigen.cpp)
add_executable(square-lin-sys src/square-lin-sys.cpp)
add_executable(general-lin-sys src/general-lin-sys.cpp)



target_include_directories(cpp-template-vector-basic PRIVATE ${EIGEN3_INCLUDE_DIR})
target_include_directories(some-eigen PRIVATE ${EIGEN3_INCLUDE_DIR})
target_include_directories(square-lin-sys PRIVATE ${EIGEN3_INCLUDE_DIR})

target_include_directories(general-lin-sys PRIVATE ${EIGEN3_INCLUDE_DIR})
