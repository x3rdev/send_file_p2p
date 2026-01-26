
#include <iostream>

#include "cli/cli.h"

static void log(const std::string &msg);
void init();

int main(int argc, char* argv[]) {
    log("initializing send_file_p2p");
    init();
    log("done");

    cli::loop();
    return EXIT_SUCCESS;
}

static void log(const std::string &msg) {
    std::cout << "[CLIENT]: " << msg << std::endl;
}

void init() {

}

