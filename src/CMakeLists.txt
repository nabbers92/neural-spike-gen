project(spikelib VERSION 0.1.0)

add_library(spikes SHARED firing.cpp tuning.cpp)

target_include_directories(spikes
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include)