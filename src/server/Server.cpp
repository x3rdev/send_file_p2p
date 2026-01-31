//
// Created by Nicolae Ungur on 1/28/2026.
//

#include "Server.h"

#include "log/logger.h"

using asio::ip::udp;

Server::Server(const uint16_t port) {
    this->port_ = port;
}

void Server::Start() {
    if (running_.exchange(true)) return;

    endpoint_ = std::make_unique<udp::endpoint>(udp::endpoint(udp::v4(), port_));
    socket_ = std::make_unique<udp::socket>(udp::socket(io_context_, *endpoint_));

    server_thread_ = std::thread(&Server::Run, this);
    Log("Server started on port: " + std::to_string(port_));
}

void Server::Stop() {
    if (!running_.exchange(false)) return;

    socket_->close();

    if (server_thread_.joinable()) {
        server_thread_.join();
    }
    Log("Server stopped");
}

void Server::Run() {
    try {
        while (running_) {
            std::array<char, 1> recv_buf;
            socket_->receive_from(asio::buffer(recv_buf), *endpoint_);

            std::string data = "test data";
            std::error_code ignored_error;
            socket_->send_to(asio::buffer(data), *endpoint_, 0, ignored_error);
        }

    } catch (std::exception& e) {   
        if (!running_) {
            Log(e.what());
        }
    }
}
