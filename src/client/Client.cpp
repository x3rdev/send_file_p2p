//
// Created by Nicolae Ungur on 1/30/2026.
//

#include "Client.h"

#include <asio/ip/udp.hpp>

#include "log/logger.h"

using asio::ip::udp;

status Client::Connect() {
    udp::socket socket(io_context_);
    try {
        udp::resolver resolver(io_context_);
        udp::endpoint server_endpoint = *resolver.resolve(udp::v4(), "127.0.0.1", "3478").begin();
        socket.open(udp::v4());

        std::array<char, 1> send_buffer = {{67}};
        socket.send_to(asio::buffer(send_buffer), server_endpoint);
        std::array<char, 128> recv_buf;
        udp::endpoint sender_endpoint;
        size_t len = socket.receive_from(
            asio::buffer(recv_buf), sender_endpoint);

        Log(std::string(recv_buf.data(), len));
        socket.close();
    } catch (std::exception& e) {
        Log(e.what());
        io_context_.restart();
        socket.close();
        return status::warning;
    }
    io_context_.restart();
    return status::ok;
}
