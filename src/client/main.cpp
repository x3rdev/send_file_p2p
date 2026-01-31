
#include <iostream>
#include <asio/config.hpp>
#include <asio/ip/address.hpp>

#include "Client.h"
#include "../common/status.h"
#include "../common/cli/cli.h"
#include "../common/log/logger.h"

static asio::ip::address SERVER_IP = asio::ip::make_address("127.0.0.1");

Client* client;

void Init();

int main(int argc, char* argv[]) {
    Log("initializing send_file_p2p client");
    Init();
    Log("done");
    if (cli::Loop() == status::error) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void Init() {
    client = new Client();
    cli::RegisterCommand("connect", [](const std::vector<std::string> & args) {
        client->Connect();
        return status::ok;
    });
    cli::RegisterCommand("help", [](const std::vector<std::string>& args) {
        cli::PrintCommands();
        return status::ok;
    });
    cli::RegisterCommand("quit", [](const std::vector<std::string>& args) {
        return status::exit;
    });
}

