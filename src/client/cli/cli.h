//
// Created by nicol on 1/22/2026.
//

#ifndef SEND_FILE_P2P_CLI_H
#define SEND_FILE_P2P_CLI_H
#include <functional>
#include <string>

namespace cli {

    enum class status {
        ok,
        error,
        exit
    };

    using CmdHandler = std::function<status(const std::vector<std::string>& args)>;

    bool RegisterCommand(const std::string& input, const CmdHandler& handler);
    void Loop();

}

#endif //SEND_FILE_P2P_CLI_H