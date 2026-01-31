//
// Created by Nicolae Ungur on 1/28/2026.
//

#include "Server.h"

#include "log/logger.h"

using asio::ip::udp;

Server::Server(const uint16_t port) {
    this->port_ = port;
    this->endpoint_ = std::make_unique<udp::endpoint>(udp::endpoint(udp::v4(), port_));
    this->socket_ = std::make_unique<udp::socket>(udp::socket(io_context_, *endpoint_));

    server_thread_ = std::thread(&Server::Run, this);
    Log("Server started on port: " + std::to_string(port_));
}

Server::~Server() {
    socket_->cancel();
    socket_->close();
    if (server_thread_.joinable()) {
        server_thread_.join();
    }
    Log("Server stopped");
}

void Server::Run() const {
    try {
        for (;;) {
            char recv_buf[128];
            socket_->receive_from(asio::buffer(recv_buf), *endpoint_);

            std::string sender_addr = endpoint_->address().to_string();
            std::string sender_port = std::to_string(endpoint_->port());

            std::string data = sender_addr + ":" + sender_port;
            std::error_code ignored_error;
            socket_->send_to(asio::buffer(data), *endpoint_, 0, ignored_error);
        }
    } catch (std::exception& e) {   
        Log(e.what());
    }
}
