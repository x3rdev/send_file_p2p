
#include <iostream>

#include "cli/cli.h"

static void Log(const std::string &msg);
void Init();

int main(int argc, char* argv[]) {
    Log("initializing send_file_p2p");
    Init();
    Log("done");

    cli::Loop();
    return EXIT_SUCCESS;
}

static void Log(const std::string &msg) {
    std::cout << "[CLIENT]: " << msg << std::endl;
}

void Init() {
    cli::RegisterCommand("help", [](const std::vector<std::string>& args) {
        Log("List of commands:");

        return cli::status::ok;
    });
    cli::RegisterCommand("quit", [](const std::vector<std::string>& args) {
        return cli::status::exit;
    });
}

