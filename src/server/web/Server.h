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
    explicit Server(uint16_t port);

    void Start();
    void Stop();

    bool isRunning() {return running_;};
private:
    uint16_t port_;
    std::atomic<bool> running_ = false;

    asio::io_context io_context_;
    std::unique_ptr<asio::ip::tcp::acceptor> acceptor_;
    std::thread server_thread_;

    void Run();
};

#endif //SEND_FILE_P2P_SERVER_H