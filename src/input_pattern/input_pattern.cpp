//
// Created by nicol on 12/14/2025.
//

#include "input_pattern.h"

#include <functional>
#include <string>
#include <sstream>
#include <vector>

input_pattern::input_pattern(
        const std::string& command,
        const std::vector<flag_type>& args,
        const std::map<std::string, flag_type>& flags,
        const std::function<void(const std::vector<flag_type>&, const std::map<std::string, flag_type>&)>& function_) {
    this->command = command;
    this->args = args;
    this->flags = flags;
    this->function_ = function_;

    const void execute(); {
        function_(args, flags);
    }
}
