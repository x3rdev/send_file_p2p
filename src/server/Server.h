//
// Created by Nicolae Ungur on 1/28/2026.
//

#ifndef SEND_FILE_P2P_SERVER_H
#define SEND_FILE_P2P_SERVER_H
#include <atomic>
#include <cstdint>
#include <thread>
#include <asio.hpp>


class Server {
public:
    Server(uint16_t port);
    ~Server();
private:
    uint16_t port_;

    asio::io_context io_context_;
    std::unique_ptr<asio::ip::udp::endpoint> endpoint_;
    std::unique_ptr<asio::ip::udp::socket> socket_;
    std::thread server_thread_;

    void Run() const;
};

#endif //SEND_FILE_P2P_SERVER_H