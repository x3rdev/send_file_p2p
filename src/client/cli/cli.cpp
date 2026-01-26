//
// Created by Nicolae Ungur on 1/26/2026.
//

#include <iostream>

namespace cli {
    void loop() {
        std::string line;
        while (true) {
            std::cout << "> " << std::flush;
            std::getline(std::cin, line);

            break;
        }
    }
}
