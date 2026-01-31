//
// Created by Nicolae Ungur on 1/26/2026.
//

#include "cli.h"

#include <format>
#include <iostream>
#include <map>
#include <sstream>

#include "../status.h"
#include "../log/logger.h"

std::vector<std::string> Tokenize(const std::string& input);

namespace cli {

    std::map<std::string, CmdHandler> command_registry;

    bool RegisterCommand(const std::string& input, const CmdHandler& handler) {
        if (command_registry.contains(input)) {
            return false;
        }
        command_registry.insert({input, handler});
        return true;
    }

    status Loop() {
        std::string line;
        auto loop_status = status::ok;
        while (loop_status != status::error && loop_status != status::exit) {
            std::cout << ">" << std::flush;
            std::getline(std::cin, line);
            if (std::cin.eof()) {
                loop_status = status::exit;
                continue;
            }
            if (line.empty()) {
                // Try again
                continue;
            }
            std::vector<std::string> tokens = Tokenize(line);
            if (!tokens.empty()) {
                auto it = command_registry.find(tokens[0]);
                if (it != command_registry.end()) {
                    loop_status = it->second(tokens);
                } else {
                    Log(std::format("Unknown command [{}]", tokens[0]));
                }
            }
        }
        return loop_status;
    }

    void PrintCommands() {
        Log("List of commands: ");
        std::string line;
        bool first = true;
        for (const auto& command : command_registry) {
            if (!first) {
                line.append(", ");
            }
            line.append(command.first);
            first = false;
        }
        Log(line);
    }

}

std::vector<std::string> Tokenize(const std::string& input) {
    std::istringstream stream(input);
    std::vector<std::string> tokens;
    std::string token;

    while (stream >> token) {
        for (char &c : token) {
            c = static_cast<char>(std::tolower(c));
        }
        tokens.push_back(token);
    }
    return tokens;
}

