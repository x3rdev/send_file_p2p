//
// Created by Nicolae Ungur on 1/26/2026.
//

#define ASIO_STANDALONE

#include <cstdlib>
#include <asio.hpp>
#include "log/logger.h"

using asio::ip::tcp;

int main(int argc, char* argv[]) {
    Log("initializing send_file_p2p server");
    asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 13));
    return EXIT_SUCCESS;
}
