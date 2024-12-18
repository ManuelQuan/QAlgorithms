project(general_algorithms)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*/*.h*)
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/sorters/)

add_library(${PROJECT_NAME}
    SHARED
    ${HEARDER_FILES} ${SRC_FILES}
)

target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        GENERAL_ALGORITHMS_LIB
)
