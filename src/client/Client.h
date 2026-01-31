//
// Created by Nicolae Ungur on 1/30/2026.
//

#ifndef SEND_FILE_P2P_CLIENT_H
#define SEND_FILE_P2P_CLIENT_H

#include <asio.hpp>
#include "status.h"


class Client {
public:
    Client();
    ~Client();
    status DiscoverClientAddress();
private:
    asio::io_context io_context_;
    std::unique_ptr<asio::ip::udp::resolver> resolver_;
    std::unique_ptr<asio::ip::udp::socket> socket_;
};


#endif //SEND_FILE_P2P_CLIENT_H