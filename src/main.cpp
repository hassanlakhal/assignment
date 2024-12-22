#include "DeribitClient.hpp"
// #include "WebSocketServer.hpp"
#include "DeribitWebSocketClient.hpp"
int main() {
    WebSocketServer wsServer;

    // Start WebSocket server in a separate thread
    std::thread serverThread([&]() { wsServer.startServer(9002); });
    DeribitWebSocketClient deribitClient("wss://test.deribit.com/ws/api/v2");

    
    deribitClient.connect();

    deribitClient.run();

    serverThread.join();
    return 0;
}
