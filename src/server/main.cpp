//
// Created by Nicolae Ungur on 1/26/2026.
//

#include <cstdlib>
#include <asio.hpp>

#include "../common/cli/cli.h"
#include "../common/log/logger.h"
#include "Server.h"

Server* server;

void Init();

int main(int argc, char* argv[]) {
    Log("initializing send_file_p2p server");
    Init();

    if (cli::Loop() == status::error) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void Init() {
    server = new Server(3478);
    cli::RegisterCommand("status", [](const std::vector<std::string>& args) {
        Log("Status - started");
        Log("Uptime - ");
        return status::ok;
    });
    cli::RegisterCommand("help", [](const std::vector<std::string>& args) {
        cli::PrintCommands();
        return status::ok;
    });
    cli::RegisterCommand("quit", [](const std::vector<std::string>& args) {
        delete server;
        return status::exit;
    });
}
