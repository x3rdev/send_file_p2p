//
// Created by Nicolae Ungur on 1/30/2026.
//

#ifndef SEND_FILE_P2P_OPERATION_CODES_H
#define SEND_FILE_P2P_OPERATION_CODES_H
#include <cstdint>

namespace sfp2p {
    enum codes : uint8_t {
        STUN = 0,
        SEND_FILE = 1,
        RECEIVE_FILE = 2
    };
}

#endif //SEND_FILE_P2P_OPERATION_CODES_H