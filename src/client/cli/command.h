//
// Created by Nicolae Ungur on 1/26/2026.
//

#ifndef SEND_FILE_P2P_COMMAND_H
#define SEND_FILE_P2P_COMMAND_H
#include <functional>

#include "cli.h"


using CmdHandler = std::function<cli::status(const std::vector<std::string>&)>;

bool RegisterCommand();

#endif //SEND_FILE_P2P_COMMAND_H