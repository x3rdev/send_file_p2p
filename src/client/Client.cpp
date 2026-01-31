//
// Created by Nicolae Ungur on 1/30/2026.
//

#include "Client.h"

#include <asio/ip/udp.hpp>

#include "operation_codes.h"
#include "log/logger.h"

using asio::ip::udp;

Client::Client() {
    this->resolver_ = std::make_unique<udp::resolver>(udp::resolver(io_context_));
    this->socket_ = std::make_unique<udp::socket>(udp::socket(io_context_));
    socket_->open(udp::v4());
    Log("Client started");
}

Client::~Client() {
    socket_->close();
    Log("Client stopped");
}

status Client::DiscoverClientAddress() {
    try {
        udp::endpoint server_endpoint = *resolver_->resolve(udp::v4(), "127.0.0.1", "3478").begin();

        std::array<char, 1> send_buffer = {{sfp2p::codes::STUN}};
        socket_->send_to(asio::buffer(send_buffer), server_endpoint);
        char recv_buf[128];
        udp::endpoint sender_endpoint;
        const size_t len = socket_->receive_from(asio::buffer(recv_buf), sender_endpoint);
        Log(std::string(recv_buf, len));
    } catch (std::exception& e) {
        Log(e.what());
        return status::warning;
    }
    return status::ok;
}
