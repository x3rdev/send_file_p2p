//
// Created by Nicolae Ungur on 1/26/2026.
//

#include "command.h"

#include <string>
#include <unordered_map>


std::unordered_map<std::string, CmdHandler> command_registry;

bool RegisterCommand(const std::string& input, const CmdHandler& handler) {
    command_registry.insert({input, handler});
    return true;
}