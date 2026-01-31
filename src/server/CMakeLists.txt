project(server)
add_executable(server
        main.cpp
        Server.cpp
        Server.h
)

target_link_libraries(server
        PRIVATE
        common
        asio
)
target_compile_definitions(server PRIVATE ASIO_STANDALONE)

if (WIN32)
    target_link_libraries(server PRIVATE ws2_32)
endif()