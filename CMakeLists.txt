cmake_minimum_required(VERSION 4.0)
project(send_file_p2p)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(extern/librats)

add_executable(send_file_p2p
        src/main.cpp
        src/client.cpp
        src/main.h
        src/command/command.cpp
        src/command/command.h
        src/command/command_input.cpp
        src/command/command_input.h
)

target_link_libraries(send_file_p2p PRIVATE rats)
