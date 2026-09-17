cmake_minimum_required(VERSION 4.2)
project(InverseKinematics)

include(FetchContent)
set(CMAKE_CXX_STANDARD 20)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
)

FetchContent_MakeAvailable(raylib)

add_executable(InverseKinematics main.cpp
        vector2d.h
        kinematic/kinematics.h
        kinematic/kinematics.cpp)

target_link_libraries(InverseKinematics PRIVATE raylib)
