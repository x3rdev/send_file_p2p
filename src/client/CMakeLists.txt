project(client)
add_executable(client
        main.cpp
)

target_link_libraries(client
        PRIVATE
        common
        asio
)
target_compile_definitions(client PRIVATE ASIO_STANDALONE)

if (WIN32)
    target_link_libraries(client PRIVATE ws2_32)
endif()