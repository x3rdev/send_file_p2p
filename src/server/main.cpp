//
// Created by Nicolae Ungur on 1/26/2026.
//

#include <cstdlib>
#include <asio.hpp>

#include "../common/cli/cli.h"
#include "../common/log/logger.h"
#include "web/Server.h"

Server* server;

void Init();

int main(int argc, char* argv[]) {
    Log("initializing send_file_p2p server");
    Init();
    Log("done");

    if (cli::Loop() == status::error) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void Init() {


    cli::RegisterCommand("server", [](const std::vector<std::string>& args) {
        if (args.size() != 2) {
            Log("Usage: \"server [start | stop | status]\"");
            return status::warning;
        }
        if (args[1] == "start") {
            server = new Server(8080);
            server->Start();
        }
        if (args[1] == "stop") {
            if (server == nullptr) {
                Log("Server has not been started, unable to stop");
                return status::warning;
            }
            server->Stop();
        }
        if (args[1] == "status") {
            if (server == nullptr) {
                Log("Status - stopped");
                return status::warning;
            }
            if (server->isRunning()) {
                Log("Status - started");
                Log("Uptime - ");
            } else {
                Log("Status - stopped");
            }
            return status::ok;
        }
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
