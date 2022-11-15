project(spikelib VERSION 0.1.0)

add_executable(main main.cpp)

target_link_libraries(main
    PRIVATE
    spikes)