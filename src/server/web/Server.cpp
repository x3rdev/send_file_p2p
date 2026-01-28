//
// Created by Nicolae Ungur on 1/28/2026.
//

#include "Server.h"

#include "log/logger.h"

using asio::ip::tcp;

Server::Server(const uint16_t port) {
    this->port_ = port;
}

void Server::Start() {
    if (running_.exchange(true)) return;

    acceptor_ = std::make_unique<tcp::acceptor>(
        io_context_, tcp::endpoint(tcp::v4(), port_)
    );

    server_thread_ = std::thread(&Server::Run, this);
    Log("Server started");
}

void Server::Stop() {
    if (!running_.exchange(false)) return;

    acceptor_->close();

    if (server_thread_.joinable()) {
        server_thread_.join();
    }
    Log("Server stopped");
}

void Server::Run() {
    try {
        while (running_) {
            tcp::socket socket(io_context_);
            acceptor_->accept(socket);

            char buffer[1024];
            socket.read_some(asio::buffer(buffer));

            std::string body = "Hello World";
            std::string message =
                "HTTP/1.1 200 OK\r\n"
                "Content-Length: " + std::to_string(body.size()) + "\r\n"
                "Connection: close\r\n"
                "\r\n" +
                body;

            asio::write(socket, asio::buffer(message));
        }
    } catch (std::exception& e) {
        if (!running_) {
            Log(e.what());
        }
    }
}
