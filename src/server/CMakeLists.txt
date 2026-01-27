project(server)
add_executable(server
        main.cpp
        log/logger.cpp
)
target_link_libraries(server PRIVATE asio)
target_compile_definitions(server PRIVATE ASIO_STANDALONE)
#if (WIN32)
#    target_link_libraries(server PRIVATE Ws2_32)
#endif()