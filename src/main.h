//
// Created by nicol on 12/14/2025.
//

#ifndef SEND_FILE_P2P_MAIN_H
#define SEND_FILE_P2P_MAIN_H

#include <vector>
#include <string>
#include <unordered_map>

#include "command/command.h"

int main();
void buildCommands(std::unordered_map<std::string, command>&);
std::vector<std::string> tokenizeInput(const std::string& s);

#endif //SEND_FILE_P2P_MAIN_H