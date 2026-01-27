
#include <iostream>

#include "../common/cli/cli.h"
#include "../common/log/logger.h"

void Init();

int main(int argc, char* argv[]) {
    Log("initializing send_file_p2p client");
    Init();
    Log("done");

    cli::Loop();
    return EXIT_SUCCESS;
}

void Init() {
    cli::RegisterCommand("help", [](const std::vector<std::string>& args) {
        cli::PrintCommands();
        return cli::status::ok;
    });
    cli::RegisterCommand("quit", [](const std::vector<std::string>& args) {
        return cli::status::exit;
    });
}

