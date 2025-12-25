//
// Created by nicol on 12/14/2025.
//

#ifndef SEND_FILE_P2P_INPUT_PATTERN_H
#define SEND_FILE_P2P_INPUT_PATTERN_H

#include <functional>
#include <map>
#include <string>
#include <vector>

enum class flag_type {
    bool_,
    int_,
    float_,
    string_
};

class input_pattern {
public:

    explicit input_pattern(
        const std::string& command,
        const std::vector<flag_type>& args,
        const std::map<std::string, flag_type>& flags,
        const std::function<void(const std::vector<flag_type>&, const std::map<std::string, flag_type>&)>&
    );

    const std::string& get_command() const { return command; }

    const void execute();

private:
    std::string command;
    std::vector<flag_type> args;
    std::map<std::string, flag_type> flags;
    std::function<void(std::vector<flag_type>&, std::map<std::string, flag_type>&)> function_;
};


#endif //SEND_FILE_P2P_INPUT_PATTERN_H