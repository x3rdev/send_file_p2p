//
// Created by nicol on 12/27/2025.
//

#include "command.h"

command::command() {
    this->name = std::string();
    this->func_ = [](command_input) { return 0; };
}

command::command(const std::string& name, const std::function<int(command_input)>& func_) {
    this->name = name;
    this->func_ = func_;
}

int command::execute(const command_input& input) const {
    return func_(input);
}
