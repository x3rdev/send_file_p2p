//
// Created by nicol on 1/22/2026.
//

#ifndef SEND_FILE_P2P_CLI_H
#define SEND_FILE_P2P_CLI_H
#include <string>

namespace cli {

    enum class status {
        ok,
        error,
        exit
    };

    void loop();

}

#endif //SEND_FILE_P2P_CLI_H