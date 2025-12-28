//
// Created by nicol on 12/27/2025.
//

#include "command_input.h"

#include <iostream>


command_input::command_input(const std::vector<std::string>& input_tokens) {
    this->name = input_tokens[0];
    std::vector<std::string> parameters;
    std::unordered_map<std::string, std::string> flags;

    for (int i = 1; i < input_tokens.size(); i++) {
        std::string token = input_tokens[i];
        if (token.starts_with('-')) {
            if (i+1 >= input_tokens.size()) {
                throw "flag missing argument";
            }
            std::string next = input_tokens[i+1];
            i++;
            flags[token] = next;
        } else {
            parameters.push_back(token);
        }
    }

    this->parameters = parameters;
    this->flags = flags;
}

std::string command_input::getName() {
    return name;
}
