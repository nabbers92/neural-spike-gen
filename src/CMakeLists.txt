project(spikelib VERSION 0.1.0)

add_library(neuralspike firing.cpp tuning.cpp)

target_include_directories(neuralspike
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include)