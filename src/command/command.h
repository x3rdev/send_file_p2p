//
// Created by nicol on 12/27/2025.
//

#ifndef SEND_FILE_P2P_COMMAND_H
#define SEND_FILE_P2P_COMMAND_H

#include <functional>
#include <string>
#include "command_input.h"

class command {
public:
    command();
    command(
        const std::string& name,
        const std::function<int(command_input)>& func_
    );

    int execute(const command_input& input) const;

private:
    std::string name;
    std::function<int(command_input)> func_;
};


#endif //SEND_FILE_P2P_COMMAND_H