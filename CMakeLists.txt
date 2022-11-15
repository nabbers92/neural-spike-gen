cmake_minimum_required(VERSION 3.15)
project(spikelib VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(include)
option(BUILD_EXAMPLES "Whether or not to build examples" ON)

if (BUILD_EXAMPLES MATCHES ON)
    message(STATUS "Building examples...")
    add_subdirectory(example)
endif()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
