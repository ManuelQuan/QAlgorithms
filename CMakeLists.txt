project(QAlgorithms)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(leetcode)
add_subdirectory(general_algorithms)
add_subdirectory(googletest)
add_subdirectory(unittests)
# enable_testing()
# add_subdirectory(googletest)
# include_directories(googletest/googletest/include/)
