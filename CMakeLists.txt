cmake_minimum_required(VERSION 4.0)
project(send_file_p2p)

set(CMAKE_CXX_STANDARD 20)

add_executable(send_file_p2p
        src/client/main.cpp
        src/client/cli/cli.h
        src/client/cli/cli.cpp
        src/client/cli/command.cpp
        src/client/cli/command.h
)
