cmake_minimum_required(VERSION 4.2)
project(InverseKinematics)

set(CMAKE_CXX_STANDARD 20)

add_executable(InverseKinematics main.cpp
        vector2d.h
        kinematics.h
        kinematics.cpp)
