#include "main.h"

#include <map>
#include <vector>
#include <iostream>
#include <string>
#include "client.h"
#include "input_pattern/input_pattern.h"

static std::map<std::string, input_pattern> patterns = {{}};

int main() {
    std::cout << "initializing send_file_p2p" << std::endl;
    bool exit = false;
    setupPatterns();
    std::cout << "done" << std::endl;

    while (!exit) {
        std::string input;
        std::cout << "> ";
        getline(std::cin, input);

        std::vector<std::string> tokens = tokenizeInput(input);

        input_pattern command = patterns.at(tokens[0]);
        command.execute();
    }
    return 0;
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

void setupPatterns() {
    patterns.try_emplace(
        std::string("help"),
        input_pattern(
            std::string("help"),
            std::vector<flag_type>{},
            std::map<std::string, flag_type>{{"c", flag_type::bool_}},
            [](const std::vector<flag_type>&, const std::map<std::string, flag_type>&) {
                std::cout << "HI";
            }
        )
    );
}