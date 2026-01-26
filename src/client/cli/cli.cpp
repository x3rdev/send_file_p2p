//
// Created by Nicolae Ungur on 1/26/2026.
//

#include "cli.h"

#include <iostream>
#include <unordered_map>

namespace cli {

    std::unordered_map<std::string, CmdHandler> command_registry;

    bool RegisterCommand(const std::string& input, const CmdHandler& handler) {
        command_registry.insert({input, handler});
        return true;
    }

    void Loop() {
        std::string line;
        while (true) {
            std::cout << "> " << std::flush;
            std::getline(std::cin, line);

            break;
        }
    }
}

