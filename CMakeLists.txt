cmake_minimum_required(VERSION 4.0)
project(send_file_p2p)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
        asio
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
        GIT_TAG        asio-1-36-0
)
FetchContent_MakeAvailable(asio)

add_library(asio INTERFACE)
target_include_directories(asio INTERFACE
        ${asio_SOURCE_DIR}/asio/include
)
target_compile_definitions(asio INTERFACE
        ASIO_STANDALONE
        ASIO_NO_DEPRECATED
        _WIN32_WINNT=0x0A00
)

add_subdirectory(src/server)
add_subdirectory(src/client)
add_subdirectory(src/common)

if(WIN32)
    add_compile_definitions(_WIN32_WINNT=0x0A00)
endif()