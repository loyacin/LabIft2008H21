cmake_minimum_required(VERSION 3.5)
project(exercice7)


########################
# Flag
########################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


########################
# Source inclusion
########################
set(SOURCE_FILES
        src/main/main.cpp
        src/main/Vector.hpp
        src/main/Vector.h)
add_executable(exercice7 ${SOURCE_FILES})


########################
# GTest inclusion
########################
option(BUILD_TESTING "build unit tests" ON)

if(BUILD_TESTING)
    include(ExternalProject)

    ExternalProject_add(gtest-target
            GIT_REPOSITORY "https://github.com/google/googletest"
            CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/extern"
            UPDATE_COMMAND ""
            )

    include_directories(${CMAKE_CURRENT_BINARY_DIR}/extern/include)
    link_directories(${CMAKE_CURRENT_BINARY_DIR}/extern/lib)
    set(GTEST_LIBRARIES gtest gmock gtest_main gmock_main pthread)

    enable_testing()

    add_subdirectory(src/test)
endif()
