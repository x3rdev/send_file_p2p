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
            size_t len = socket.read_some(asio::buffer(buffer));

            std::string request(buffer, len);
            std::string response = HandleRequest(request);
            asio::write(socket, asio::buffer(response));
        }
    } catch (std::exception& e) {   
        if (!running_) {
            Log(e.what());
        }
    }
}

std::string Server::HandleRequest(const std::string& request) {
    // Parse the first line to get the path
    size_t method_end = request.find(' ');
    size_t path_end = request.find(' ', method_end + 1);

    if (method_end == std::string::npos || path_end == std::string::npos) {
        return CreateResponse(400, "Bad Request");
    }

    std::string path = request.substr(method_end + 1, path_end - method_end - 1);

    if (path == "/stun") {
        return CreateResponse(200, "STUN endpoint");
    } else if (path == "/") {
        return CreateResponse(200, "Hello World");
    } else {
        return CreateResponse(404, "Not Found");
    }
}

std::string Server::CreateResponse(int status_code, const std::string& body) {
    std::string status_text = (status_code == 200) ? "OK" :
                               (status_code == 404) ? "Not Found" : "Bad Request";

    return "HTTP/1.1 " + std::to_string(status_code) + " " + status_text + "\r\n"
           "Content-Length: " + std::to_string(body.size()) + "\r\n"
           "Connection: close\r\n"
           "\r\n" + body;
}
