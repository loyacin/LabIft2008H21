add_executable(fileTesteur FileTesteur.cpp)
add_test(FileTesteur.cpp fileTesteur)
target_link_libraries(fileTesteur ${GTEST_LIBRARIES})
