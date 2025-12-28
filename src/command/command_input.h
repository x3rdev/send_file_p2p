//
// Created by nicol on 12/27/2025.
//

#ifndef SEND_FILE_P2P_COMMAND_INPUT_H
#define SEND_FILE_P2P_COMMAND_INPUT_H
#include <functional>
#include <string>

class command_input {
public:
    command_input(
            const std::vector<std::string>& input_tokens
    );

    std::string getName();

private:
    std::string name;
    std::vector<std::string> parameters;
    std::unordered_map<std::string, std::string> flags;
};


#endif //SEND_FILE_P2P_COMMAND_INPUT_H