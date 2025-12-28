#include "main.h"

#include <map>
#include <vector>
#include <iostream>
#include <string>
#include "client.h"
#include "command/command.h"
#include "command/command_input.h"

int main() {
    std::cout << "initializing send_file_p2p" << std::endl;
    bool exit = false;
    auto commands = std::unordered_map<std::string, command>();
    buildCommands(commands);
    std::cout << "done" << std::endl;

    while (!exit) {
        std::cout << std::endl;
        std::string input;
        std::cout << "> ";
        getline(std::cin, input);

        std::vector<std::string> tokens = tokenizeInput(input);
        if (tokens.size() > 0) {
            try {
                auto parsed_command_input = command_input(tokens);
                auto name = parsed_command_input.getName();
                if (!commands.contains(name)) {
                    throw std::runtime_error("Command not found: " + name);
                }
                command parsed_command = commands.at(name);
                if (parsed_command.execute(parsed_command_input) == -1) {
                    exit = true;
                }
            } catch (const std::runtime_error ex) {
                std::cout << ex.what() << std::endl;
            }
        }
    }
    return 0;
}

void buildCommands(std::unordered_map<std::string, command>& map) {
    map["help"] = command("help", [](command_input) {
        std::cout << "help command executed" << std::endl;
        return 0;
    });
    map["start"] = command("start", [](command_input command_input) {
        command_input
        startClient();
        return 0;
    });
}

std::vector<std::string> tokenizeInput(const std::string& s) {
    std::istringstream iss(s);
    std::vector<std::string> result;
    std::string word;
    while (iss >> word) {
        result.push_back(word);
    }
    return result;
}