cmake_minimum_required(VERSION 3.15)
project(spikelib VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(include)
option(BUILD_EXAMPLES "Whether or not to build examples" ON)
option(BUILD_TESTS "Whether or not to build tests" ON)

if (BUILD_EXAMPLES MATCHES ON)
    message(STATUS "Building examples...")
    add_subdirectory(example)
endif()

if (BUILD_TESTS MATCHES ON)
    message(STATUS "Building tests...")
    add_subdirectory(tests)
endif()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
