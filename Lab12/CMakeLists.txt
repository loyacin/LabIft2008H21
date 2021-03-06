cmake_minimum_required(VERSION 3.5)
project(Sort)


########################
# Flag
########################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


########################
# Source inclusion
########################
set(SOURCE_FILES
        src/main/Tri.h
        src/main/TriBulle.hpp
        src/main/TriFusion.hpp
        src/main/TriInsertion.hpp
        src/main/TriParTas.hpp
        src/main/TriRapide.hpp
        src/main/TriSelection.hpp
        src/main/TriShell.hpp
        src/main/main.cpp)
add_executable(Sort ${SOURCE_FILES})


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
    set(GTEST_LIBRARIES pthread gtest gmock gtest_main gmock_main)

    enable_testing()

    add_subdirectory(src/test)
endif()
