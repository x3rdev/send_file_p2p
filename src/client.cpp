#include "librats.h"
#include "client.h"

static std::unique_ptr<librats::RatsClient> client;
static std::mutex mutex;

bool startClient(int port) {
    std::lock_guard lk(mutex);
    if (client != nullptr) {
        std::cerr << "Failed to start client - already running" << std::endl;
        return false;
    }

    client = std::make_unique<librats::RatsClient>(port);
    client->set_logging_enabled(false);
    setupCallbacks();

    if (!client->start()) {
        std::cerr << "Failed to start client" << std::endl;
        client.reset();
        return false;
    }

    return true;
}

void setupCallbacks() {
    client->set_connection_callback([](socket_t socket, const std::string& peer_id) {
        std::cout << "✅ New peer connected: " << peer_id << std::endl;
    });

    client->set_string_data_callback([](socket_t socket, const std::string& peer_id, const std::string& message) {
        std::cout << "💬 Message from " << peer_id << ": " << message << std::endl;
    });
}

void stopClient() {
    std::lock_guard lk(mutex);
    if (!client) {
        std::cerr << "Failed to stop client - not running" << std::endl;
        return;
    }
    client->stop();
    while (client->get_active_thread_count() > 0) {/* wait */}
    client.reset();
}

librats::RatsClient* getRatsClient() {
    std::lock_guard lk(mutex);
    return client.get();
}
