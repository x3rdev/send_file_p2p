
#include <iostream>

#include "../common/status.h"
#include "../common/cli/cli.h"
#include "../common/log/logger.h"

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
    cli::RegisterCommand("help", [](const std::vector<std::string>& args) {
        cli::PrintCommands();
        return status::ok;
    });
    cli::RegisterCommand("quit", [](const std::vector<std::string>& args) {
        return status::exit;
    });
}

