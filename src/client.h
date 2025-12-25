#ifndef SEND_FILE_P2P_CLIENT_H
#define SEND_FILE_P2P_CLIENT_H

#include "librats.h"

bool startClient(int port);
void setupCallbacks();
void stopClient();
librats::RatsClient* getRatsClient();

#endif //SEND_FILE_P2P_CLIENT_H