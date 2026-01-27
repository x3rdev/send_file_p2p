//
// Created by Nicolae Ungur on 1/26/2026.
//

#include "logger.h"

#include <iostream>

extern void Log(const std::string &msg) {
    std::cout << "[SERVER]: " << msg << std::endl;
}
